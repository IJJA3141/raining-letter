#include "table.h"

table::table()
{
    return;
}

table::~table()
{
    return;
}

void table::push_back(std::string _str)
{
    m_vStr.push_back(_str);
    return;
}

int table::m_canFAll(int _x, int _y, int _offset)
{
    if(m_vStr.size() >= _y)
    {
        if(m_vStr[_y].size() >= _x)
        {
            return 0;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}