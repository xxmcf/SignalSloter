/*
 * @brief   �����Զ����źŲ�
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

//����SIGNAL�궨��
static void test1()
{
    const char* p = MYSIGNAL(helloword);
    test(__FUNCTION__, p, "helloword");
}

//����SLOT�궨��
static void test2()
{
    const char* p = MYSLOT(MyObject);
    test(__FUNCTION__, p, "MyObject");
}

//������Ϣ���źŲ�����
static void test3()
{
    ObjectA obj1;
    ObjectB obj2;
    MyObject::my_connect(&obj1, MYSIGNAL(sig1), &obj2, MYSLOT(slot1));
    my_emit obj1.sig1();
    test(__FUNCTION__, obj2.slotStr.c_str(), "slot1");
}

//������Ϣ���źŲ�����
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
    qDebug() << QStringLiteral("�Զ�����Ϣ�Ų۲���");
    test1();
    test2();
    test3();
    test4();
}
