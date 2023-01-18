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

    m_printc();
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

int table::m_canFall(int _x, int _y)
{
    char dummy = m_ppChar[_y][_x];

    if(dummy == "9"[0])
    {
        int dummy2 = 0;
    }

    if(m_ppChar[_y][_x] == " "[0])
    {
        std::cout << "0\n";
        return 0;
    }
    else if(m_ppChar[_y + 1][_x] == " "[0])
    {
        std::cout << "2\n";
        return 2;
    }
    else if(_x - 1 >= 0)
    {
        std::cout << "x-1 >= 0\n";
        if(m_ppChar[_y + 1][_x - 1] == " "[0])
        {
            std::cout << "1\n";
            return 1;
        }
    }
    if(_x + 1 < m_x)
    {
        std::cout << "x+1 < 0\n";
        if(m_ppChar[_y + 1][_x + 1] == " "[0])
        {
            std::cout << "3\n";
            return 3;
        }
    } 

    std::cout << "4\n";
    return 0;
}

void table::m_fall()
{
    for(int i = m_y - 2; i >= 0; i--)
    {   
        for(int j = 0; j < m_x; j++)
        {
            switch (m_canFall(j,i))
            {
            case 0:
                std::cout << "case 0 called\n";
                break;
            case 1:
                std::cout << "case 1 called\n";
                m_ppChar[i + 1][j - 1] = m_ppChar[i][j];
                m_ppChar[i][j] = " "[0];
                break;
            case 2:
                std::cout << "case 2 called\n";
                m_ppChar[i + 1][j] = m_ppChar[i][j];
                m_ppChar[i][j] = " "[0];
                break;
            case 3:
                std::cout << "case 3 called\n";
                m_ppChar[i + 1][j + 1] = m_ppChar[i][j];
                m_ppChar[i][j] = " "[0];
                break; 
            default:
                break;
            }
        }
    }

    std::cout << "before print\n";
    m_printc();
}

void table::m_printc()
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

void table::m_print()
{
    return;
}