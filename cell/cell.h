#ifndef CELL
#define CELL

#include "./../matrix/matrix.h"

class iCell
{
public:
    char *pChar;
    int x;
    int y;
    int xVect;
    int yVect = 1;

public:
    iCell();
    ~iCell();
    virtual void push() = 0;
    virtual void drop() = 0;
};

class cell : public iCell
{
public:
    cell(char *_pChar, int _x, int _y, matrix *_pParent);
    matrix *m_pMatrix;
    void push();
    void drop();
};

class leftCell : public cell
{
public:
    leftCell(char *_pChar, int _x, int _y, matrix *_pParent) : cell{_pChar, _x, _y, _pParent} {};
    void drop();
};

class rightCell : public cell
{
public:
    rightCell(char *_pChar, int _x, int _y, matrix *_pParent) : cell{_pChar, _x, _y, _pParent} {};
    void drop();
};

class wall : public iCell
{
public:
    wall(int _x, int _y);
    inline void push(){};
    inline void drop(){};
};

#endif