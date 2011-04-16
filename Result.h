#ifndef RESULT_H
#define RESULT_H

#include "Global.h"

class Result {

public:
    Result (long baseAddr, BYTE data)               {r_baseAddr = baseAddr; r_data = data;}
    Result (long baseAddr, BYTE data, long length)  {r_baseAddr = baseAddr; r_data = data; r_length = length;}
    void setBaseAddr (long baseAddr)                {r_baseAddr = baseAddr; }
    long baseAddr ()                                {return r_baseAddr;     }
    void setLength (long length)                    {r_length = length;     }
    long length ()                                  {return r_length;       }
    void setData (BYTE data)                        {r_data = data;         }
    BYTE data ()                                    {return r_data;         }
    int type ()                                     {return r_type;         }
    void setType (int type)                         {r_type = type;         }

private:
    long r_baseAddr;
    long r_length;
    BYTE r_data;
    int  r_type;

};

#endif // RESULT_H
