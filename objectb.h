#ifndef OBJECTB_H
#define OBJECTB_H

#include "myobject.h"

class ObjectB : public MyObject
{
    MY_OBJECT
public:
    ObjectB(){}

public my_slots:
    void slot1()
    {
        slotStr = "slot1"; //测试用
    }
};

#endif // OBJECTB_H
