#include <vector>
#include "table.h"
#include <iostream>

table::table(std::vector<std::vector<char>> _vector)
{
    m_x = m_size(_vector);
    m_y = _vector.size();

    m_ppChar = new char*[m_y];

    for(int i = 0; i < m_y; i++)
    {
        size_t j = 0;
        m_ppChar[i] = new char[m_x];

        for(j; j < _vector[i].size(); j++)
        {
            m_ppChar[i][j] = _vector[i][j];
        }
        for (j; j < m_x; j++)
        {
            m_ppChar[i][j] = " "[0];
        }   
    }

    return;
}   

table::~table()
{   
    return;
}   

int table::m_size(std::vector<std::vector<char>> _vector)
{
    int out = 0;

    for(int i = 0; i < _vector.size(); i++)
    {
        if(_vector[i].size() > out)
        {
            out = _vector[i].size();
        }
    }

    return out;
}

int table::m_canFall(int _x, int _y, int _offset)
{
    if(m_ppChar[_y][_x] == " "[0])
    {
        return 0;
    }
    else if(m_ppChar[_y + 1][_x] == " "[0])
    {
        return 2;
    }
    else if(_x - 1 >= 0)
    {
        if(m_ppChar[_y + 1][_x - _offset] == " "[0])
        {
            return 1;
        }
    }
    if(_x + 1 < m_x)
    {
        if(m_ppChar[_y + 1][_x + _offset] == " "[0])
        {
            return 3;
        }
    } 
    return 0;
}

bool table::m_fall(int _offset)
{
    bool changed = false;

    for(int i = m_y - 2; i >= 0; i--)
    {   
        for(int j = 0; j < m_x; j++)
        {
            switch (m_canFall(j, i, _offset))
            {
            case 0:
                break;
            case 1:
                m_ppChar[i + 1][j - _offset] = m_ppChar[i][j];
                m_ppChar[i][j] = " "[0];
                changed = true;
                break;
            case 2:
                m_ppChar[i + 1][j] = m_ppChar[i][j];
                m_ppChar[i][j] = " "[0];
                changed = true;
                break;
            case 3:
                m_ppChar[i + 1][j + _offset] = m_ppChar[i][j];
                m_ppChar[i][j] = " "[0];
                changed = true;
                break; 
            default:
                break;
            }
        }
    }

    return changed;
}

void table::printc()
{
    std::cout << "\n";

    for(int i = 0; i < m_y; i++)
    {
        for(int j = 0; j < m_x; j++)
        {
            std::cout << "[" << m_ppChar[i][j] << "]";
        }
        std::cout << "\n";
    }

    std::cout << std::endl;
    return;
}

void table::print()
{
    return;
}

void table::trunOnGravity()
{
    for(int i = 0; i < m_x, i++)
    {
        while (m_fall(i))
        {
            printc();
        }    
    }

    return;
}