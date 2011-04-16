#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <errno.h>
#include <vector>
#include "VMA.h"
#include "Global.h"
#include "Result.h"
//#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <fcntl.h>
#include <QString>
#include <QDebug>


class Memory {

public:
    Memory(pid_t pid);
	bool setValue (long, BYTE, int);
	bool getValue (long, BYTE &);
    //lock value
    // lock and allow only greater than
    // lock and allow smaller than only
        VMA readVMA(VMA region);
        std::vector<VMA> vmaList (int);
   // void scanVMA(VMA area,std::vector<Result>* results, void* key, long length);
	bool attach ();
	void detach ();
private:

	pid_t m_pid;
    std::vector<Result> foundAddrs;
};

#endif // MEMORY_H
