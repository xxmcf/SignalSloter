/*
 * @brief   模仿QT实现ObjectA的moc文件,主要实现类信号函数和回调
 * @author  xiao2macf
 * @version 1.0
 * @date    2020/03/21
 *
 */
#include "objecta.h"

static const char signalNames[] = "sig1\n";
static const char slotNames[] = "";
MetaObject ObjectA::meta = {signalNames, slotNames};


void ObjectA::metacall(int idx)
{

}

MetaObject* ObjectA::metaObject()
{
    return &this->meta;
}


void ObjectA::sig1()
{
    MetaObject::active(this, 0);
}



