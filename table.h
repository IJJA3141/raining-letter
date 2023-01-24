#pragma once
#include <string>
#include <vector>

class table
{
private:
    
public:
    std::vector<std::string> m_vStr = {};
    int m_canFAll(int _x, int _y, int _offset);
    table();
    ~table();

    void push_back(std::string _str);
};