/*
 * @brief   测试自定义信号槽
 * @author  xiao2macf
 * @version 1.0
 * @date    2020/03/21
 *
 */

#include "objecta.h"
#include "objectb.h"
#include <sstream>
#include <string>

static void test(const char* testName, const char* real,  const char* expected)
{
    std::stringstream sstr;
    sstr << testName << " : ";
    if (real == nullptr && expected == nullptr)
        sstr << "PASSED";
    else if (real == nullptr && expected != nullptr)
        sstr << "FALIED";
    else if (real != nullptr && expected == nullptr)
        sstr << "FALIED";
    else if (strcmp(real, expected) != 0)
        sstr << "FALIED";
    else
        sstr << "PASSED";

    qDebug() << sstr.str().c_str();
}

//测试SIGNAL宏定义
static void test1()
{
    const char* p = MYSIGNAL(helloword);
    test(__FUNCTION__, p, "helloword");
}

//测试SLOT宏定义
static void test2()
{
    const char* p = MYSLOT(MyObject);
    test(__FUNCTION__, p, "MyObject");
}

//测试信息号信号槽连接
static void test3()
{
    ObjectA obj1;
    ObjectB obj2;
    MyObject::my_connect(&obj1, MYSIGNAL(sig1), &obj2, MYSLOT(slot1));
    my_emit obj1.sig1();
    test(__FUNCTION__, obj2.slotStr.c_str(), "slot1");
}

//测试信息号信号槽连接
static void test4()
{
    ObjectA obj1;
    ObjectB obj2;
    MyObject::my_connect(&obj1, MYSIGNAL(sig1), &obj2, MYSLOT(slot1));
    my_emit obj1.sig1();
    test(__FUNCTION__, obj1.slotStr.c_str(), "");
}

void myobject_test()
{
    qDebug() << QStringLiteral("自定义信息号槽测试");
    test1();
    test2();
    test3();
    test4();
}
