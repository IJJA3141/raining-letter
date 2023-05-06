#ifndef MATRIX
#define MATRIX

#include "./../cell/cell.h"
#include "vector"
#include <iostream>

class matrix
{
private:
    std::vector<iCell*> m_vect;

public:
    matrix();
    void drop();
    void print();
    std::vector<std::vector<iCell*>> vect;
};

#endif