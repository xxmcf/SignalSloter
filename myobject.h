/*
 * @brief   自定义Object声明和必要的宏定义
 * @author  xiao2macf
 * @version 1.0
 * @date    2020/03/21
 *
 */
#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <map>
#include <QDebug>
#include <string>


#define MYSIGNAL(a) #a
#define MYSLOT(a) #a
#define my_emit
#define my_signals public
#define my_slots
#define MY_OBJECT \
public:\
    static MetaObject meta; \
    virtual void metacall(int idx); \
    virtual MetaObject* metaObject();

class MyObject;
struct MetaObject
{
    const char* signalNames;
    const char* slotNames;
    static void active(MyObject* sender, int idx);
};

struct Connection
{
    MyObject* receiver;
    int method;
};

typedef std::multimap<int, Connection> ConnectionMap;
typedef std::multimap<int, Connection>::iterator ConnectionMapIt;


class MyObject
{
    MY_OBJECT
 public:
    MyObject(){}

    static bool my_connect(MyObject* sender, const char* sig, MyObject* receiver, const char* slt);

    friend struct MetaObject;
protected:
    ConnectionMap connections;
public:
    std::string slotStr;

};

#endif // MYOBJECT_H
