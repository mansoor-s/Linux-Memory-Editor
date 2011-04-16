#include "Scanner.h"
#include <QDebug>
#include <exception>

using namespace std;
/*
*
*/
Scanner::Scanner () {
    s_stop = false;
    s_results = new std::vector<Result>;
}

/*
*	the entry point of the thread;
*
*/
void Scanner::run ()
{
    // We'll just start the event loop here and call all of the required methods via signals
    exec();

}


/*
*   first cache the entire Virtual Memory Area and then scan it so
*	it doesn't hold up the target process while this is searching for the key
*	it also drasticaly reduced the number of ptrace calls
*/
void Scanner::newScan (int pid, BYTE key, int type, int operation)
{
    try {
        //s_pid = pid; s_type = type;
        Memory memory(pid);
        long length = 4;//sizeof(key);

        std::vector<VMA> areas = memory.vmaList(REGION_ALL);

        // if no suitable virtual memory areas found, throw exception
        if(areas.size() < 1) {
            throw(QString("No suitable memory locations were located"));
        }
        // go over every virtual memory area
        for(unsigned long i = 0; i < areas.size() ; i++) {
            if(s_stop == true) {
                break;
            }
            // no point in scanning a VMA too small to contain the key
            if(areas.at(i).size() < length) {
                continue;
            }

            unsigned char workSet[length];
            VMA ee = areas.at(i);
            ee = memory.readVMA(ee);
            unsigned char *buffer = ee.vmaData();

            // this loop incrementaly goes over every byte of the VMA and compares
            // in sets of sizeof(key) bytes
            for(unsigned long j = 0; j < ee.size() - length; j++ ) {
                if(s_stop == true) {
                    break;
                }
                //copy sizeof(key) bytes from the vma data
                memcpy(workSet,buffer + j,length);
                //compare the key with the bytes copied from the vma
                if(memcmp(workSet,key,length) == 0 ) {
                    Result found(static_cast<VMA>(areas.at(i)).baseAddr() + j, workSet, length);
                    s_results->push_back(found);
                }
            }
        }

        if(s_stop != true)
            emit setResults(*s_results);

        //reset the stop switch
        s_stop = false;

    } catch(bad_alloc&) {
        qDebug() << "failed at memory alloc";
    } catch(QString e) {
        emit scanFailed("No suitable memory locations were located");
        qDebug() << e;
    }
}

void Scanner::scan (BYTE key, int operation)
{

}

void Scanner::stop ()
{
    s_stop = true;
}
