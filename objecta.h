#ifndef OBJECTA_H
#define OBJECTA_H

#include "myobject.h"

class ObjectA : public MyObject
{
    MY_OBJECT
public:
    ObjectA(){}

my_signals:
    void sig1();
};

#endif // OBJECTA_H
