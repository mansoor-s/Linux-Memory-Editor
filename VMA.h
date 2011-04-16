#ifndef VMA_H
#define VMA_H

#include "Global.h"

class VMA {

public:
    void setVmaId(unsigned id)                  {v_id = id;}
    unsigned vmaID()                            {return v_id;}
    void setBaseAddr(unsigned long baseAddr)    {v_baseAddr = baseAddr;}
    unsigned long baseAddr()                    {return v_baseAddr;}
    void setSize(unsigned long size)            {v_size = size;}
    unsigned long size()                        {return v_size;}
    void setReadOnly(bool readOnly)             {v_readOnly = readOnly;}
    bool isReadOnly()                           {return v_readOnly;}
	void setVMAData(BYTE data)                  {v_vmaData = data;}
    BYTE vmaData()                              {return v_vmaData;}

private:
    unsigned v_id;
    unsigned long v_baseAddr;
    unsigned long v_size;
    bool v_readOnly;
    BYTE v_vmaData;

};

#endif // VMA_H
