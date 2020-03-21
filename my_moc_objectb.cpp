/*
 * @brief   模仿QT实现ObjectB的moc文件,主要实现类信号函数和回调
 * @author  xiao2macf
 * @version 1.0
 * @date    2020/03/21
 *
 */
#include "objectb.h"

static const char signalNames[] = "";
static const char slotNames[] = "slot1\n";
MetaObject ObjectB::meta = {signalNames, slotNames};


void ObjectB::metacall(int idx)
{
    switch(idx)
    {
    case 0:
        slot1();
        break;
    default:
        break;
    }
}

MetaObject* ObjectB::metaObject()
{
    return &this->meta;
}
