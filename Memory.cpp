/************************************************************************************
*
*   This file is part of the H3xLabs Linux Process Memory Scanner and Editor program.
*   Copyright (C) <2010>  <Mansoor Sayed> [astropirate[at]gmail[dot]com]
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**********************************************************************************/
#include "Memory.h"

Memory::Memory (pid_t pid)
{
	m_pid = pid;
}

/*
 * Attach to the specified process
 *
 */
unsigned int Memory::attach ()
{
    try {
        int status;

        /* attach, to the target application, which should cause a SIGSTOP */
        if (ptrace(PTRACE_ATTACH, m_pid, NULL, NULL) == -1L) {
            fprintf(stderr, "error: failed to attach to %d, %s\n", m_pid, strerror(errno));
            //throw(QString("Unable to attach to the process. errno: %s").arg(strerror(errno)));
        }

        /* wait for the SIGSTOP to take place. */
        if (waitpid(m_pid, &status, 0) == -1 || !WIFSTOPPED(status)) {
            //throw(QString("There was an error waiting for the target to stop. errno: %s").arg(strerror(errno)));
            fprintf(stdout, "info: %s\n", strerror(errno));
        }
    } catch(QString e) {
        qDebug() << e;
        return 0;
    }
    return 1;
}

/*
  *
  * Detach from the specified prcess
  *
  *
  */
void Memory::detach ()
{
	ptrace(PTRACE_DETACH, m_pid, NULL, NULL);
}


/*
  * Get the data from the specified address
  *
  * returns true if successful
  *
  */

unsigned int Memory::getValue (long addr, BYTE &buffer)
{
    if(!attach())
        return 0;
    long length = sizeof(buffer);
    long x = 0;

    int i = 0;
    int j = length / sizeof(long);
    for (i = 0; i < j; i++) {
        x = ptrace(PTRACE_PEEKDATA, m_pid, addr + i * sizeof(long), NULL);
        if (errno != 0){
            detach();
            return 0;
        }
        memcpy(buffer + i * sizeof(long), &x, sizeof(long));

    }

    j = length % sizeof(long);
    if (j > 0) {
        x = ptrace(PTRACE_PEEKDATA, m_pid, addr + i * sizeof(long), NULL);
        if (errno != 0){
            detach();
            return 0;

        }
        memcpy(buffer + i * sizeof(long), &x, j);
    }
    detach();
    return 1;
}

unsigned int Memory::setValue (long addr, BYTE value, int type)
{
    long length = sizeof(value);
    if(!attach())
        return 0;
    long *x = new long[256];

    int i = 0;
    int j = length / sizeof(long);
    for (i = 0; i < j; i++) {
        memcpy(&x, &value + i*sizeof(long), sizeof(long));
        ptrace(PTRACE_POKEDATA, m_pid, addr + i*sizeof(long), x);
        if (errno != 0) {
            detach();
            return 0;
        }
    }

    j = length % sizeof(long);
    if (j > 0) {
        *x = ptrace(PTRACE_PEEKDATA, m_pid, addr, x);
        if (errno != 0) {
            detach();
            return 0;
        }
    }
    memcpy(&x, value + i*sizeof(long), j);
    ptrace(PTRACE_POKEDATA, m_pid, addr + i*sizeof(long), x);
    if (errno != 0){
        detach();
        return 0;
    }
    detach();
    return 1;
}


/*
  *     Reads the /proc/PID/mem file for the specified pid and parses it
  *     saves the parsed location of the memory areas in *VMAregions
  *
  */
std::vector<VMA> Memory::vmaList(int scanAreas)
{
    FILE *maps;
    char name[128], *line = NULL;
    char exename[128];
    size_t len = 0;
    std::vector<VMA> *VMAregions = new std::vector<VMA>;

#define MAX_LINKBUF_SIZE 256
    char linkbuf[MAX_LINKBUF_SIZE];
    int linkbuf_size;
    try {
        /* construct the maps filename */
        snprintf(name, sizeof(name), "/proc/%u/maps", m_pid);

        /* attempt to open the maps file */
        if ((maps = fopen(name, "r")) == NULL) {
            //printf ("failed to open maps file %s.\n", name);
            throw(QString("Failed to open maps file %s").arg(name));

        }

        /* read every line of the maps file */
        while (getline(&line, &len, maps) != -1) {
            unsigned long start, end;
            char read, write, exec, cow, *filename;
            int offset, dev_major, dev_minor, inode;

            /* slight overallocation */
            if ((filename = new char[len]) == NULL) {
                //printf ("failed to allocate %lu bytes for filename.\n", (unsigned long)len);
                throw(QString("Failed to allocate %lu bytes for filename").arg((unsigned long)len));
            }

            /* initialise to zero */
            memset(filename, '\0', len);

            /* parse each line */
            if (sscanf(line, "%lx-%lx %c%c%c%c %x %x:%x %u %s", &start, &end, &read,
                       &write, &exec, &cow, &offset, &dev_major, &dev_minor, &inode, filename) >= 6) {

                /* must have permissions to read and be non-zero size
                *   only save what we actually need
                */
                if ((read == 'r') && ((end - start) > 0)) {
                    // at the very least it should be readable. check for write permission later

                    /* determine if this region is useful */
                    bool useful = false;
                    switch (scanAreas)
                    {
                    case REGION_ALL:
                        useful = true;
                        break;
                    case REGION_HEAP_STACK_EXECUTABLE_BSS:
                        if (filename[0] == '\0') {
                            useful = true;
                            break;
                        }
                        /* fall through */
                                case REGION_HEAP_STACK_EXECUTABLE:
                        if ((!strcmp(filename, "[heap]")) || (!strcmp(filename, "[stack]"))) {
                            useful = true;
                            break;
                        }

                        /* test if the region is mapped to the executable */
                        snprintf(exename, sizeof(exename), "/proc/%u/exe", m_pid);
                        if((linkbuf_size = readlink(exename, linkbuf, MAX_LINKBUF_SIZE)) == -1) {
                            throw(QString("Failed to read executable link"));
                        }
                        if (linkbuf_size >= MAX_LINKBUF_SIZE) {
                            throw(QString("path to the executable is too long"));
                        }
                        linkbuf[linkbuf_size] = 0;
                        if (strcmp(filename, linkbuf) == 0)
                            useful = true;
                        break;
                    }

                    // If not usefull then move onto the next VMA region
                    if (!useful) {
                        continue;
                    }

                    VMA VMAregion;
                    VMAregion.setBaseAddr(start);
                    VMAregion.setSize((unsigned long) (end - start));
                    // Check to see if the regions is read only or not. either way it gets saved in VMAregions
                    if(write == 'w') {
                        VMAregion.setReadOnly(false);
                    }
                    else {
                        VMAregion.setReadOnly(true);
                    }
                    VMAregions->push_back(VMAregion);
                }
            }
        }
    } catch(QString e) {
        qDebug() << e;
    }
    return *VMAregions;
}


VMA Memory::readVMA(VMA region)
{
    try {
        if(!attach())
		  {
			throw(QString("Trying to read VMA but not attached to process!!"));
        }

        char* file = new char[region.size()];
        sprintf(file, "/proc/%d/mem", m_pid);
        int hndl = open(file, O_RDONLY);
        unsigned char* buffer = new unsigned char[region.size()];
        pread(hndl, buffer, region.size(), region.baseAddr());
        region.setVMAData(buffer);

    } catch(QString e) {
        qDebug() << e;
    }

    return region;
}
