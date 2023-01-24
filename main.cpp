#include "table.h"

int main()
{
    table a = table();
    a.push_back("aaaa");
    return a.m_canFAll(2, 0, 2);
}