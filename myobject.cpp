/*
 * @brief   自定义Object实现
 * @author  xiao2macf
 * @version 1.0
 * @date    2020/03/21
 *
 */

#include "myobject.h"

MetaObject MyObject::meta = {"", ""};

static int find_string(const char* str, const char* substr)
{
    if (nullptr == str || nullptr == substr)
    {
        return -1;
    }
    if (strlen(str) < strlen(substr))
    {
        return -1;
    }
    int idx = 0;
    char* p = (char*)str;
    bool start = true;
    int len = strlen(substr);
    while(*p)
    {
        if (start && !strncmp(p, substr, len) && p[len] == '\n')
        {
            return idx;
        }
        start = false;
        if (*p == '\n')
        {
            start = true;
            idx++;
        }
        p++;
    }
    return -1;
}

void MetaObject::active(MyObject* sender, int idx)
{
    ConnectionMapIt it;
    std::pair<ConnectionMapIt, ConnectionMapIt> ret;
    ret = sender->connections.equal_range(idx);

    for (it = ret.first; it != ret.second; ++it)
    {
        Connection c = (*it).second;
        c.receiver->metacall(c.method);
    }
}

bool MyObject::my_connect(MyObject* sender, const char* sig, MyObject* receiver, const char* slt)
{
    int sig_idx = find_string(sender->metaObject()->signalNames, sig);
    int slt_idx = find_string(receiver->metaObject()->slotNames, slt);
    if (sig_idx == -1 || slt_idx == -1)
    {
        return false;
    }
    Connection c = {receiver, slt_idx};
    sender->connections.insert(std::pair<int, Connection>(sig_idx, c));
    return true;
}

void MyObject::metacall(int idx)
{

}

MetaObject* MyObject::metaObject()
{
    return &this->meta;
}
