#include <QtGui/QApplication>
#include "mainwindow.h"
#define _FILE_OFFSET_BITS 64
#include <QCleanlooksStyle>
#include <typeinfo>
#include <fcntl.h>
//#define _XOPEN_SOURCE 500
#include <unistd.h>
#include "Memory.h"
#include <errno.h>
#include "VMA.h"

void readmem ();

int main(int argc, char *argv[])
{
        //readmem();
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
    return 0;
}
/*
void readmem ()
{
        int wantedLocations = REGION_ALL;
        Memory mem(8115);
        mem.attach();
        std::vector<VMA>* regions = new std::vector<VMA>;
        mem.vmaList(regions, wantedLocations);

        unsigned char* buffer = new unsigned char[256];
        int HANDLE = open("/proc/8115/mem", O_RDONLY);
        for(int i = 0; i < 500; i++) {
                printf("||");
                VMA tt = regions->at(i);
                unsigned long addr = tt.baseAddr();
                for(int k = 0; k < tt.size() - 4; k+=4) {
                        addr += 4;
                        if(pread(HANDLE,buffer,4, addr) == -1)
                                printf("failed to read this is why: %s\n", strerror( errno ));
                        //printf("%s", buffer);

                }
        }

        mem.detach();
}
*/
