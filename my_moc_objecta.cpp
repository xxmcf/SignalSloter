/*
 * @brief   ģ��QTʵ��ObjectA��moc�ļ�,��Ҫʵ�����źź����ͻص�
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



