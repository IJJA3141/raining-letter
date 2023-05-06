#include "cell.h"

// cell
cell::cell(char *_pChar, int _x, int _y, matrix* _pParent)
{
    this->m_pMatrix = _pParent;
    this->pChar = _pChar;
    this->x = _x;
    this->y = _y;
    this->yVect = 0;
    return;
};

void cell::push()
{
    this->xVect++;
    return;
}

void cell::drop()
{
    if (this->m_pMatrix->vect[this->x + this->xVect][this->y + 1] == nullptr)
    {
        this->xVect = 0;
        this->m_pMatrix->vect[this->x + this->xVect][this->y + 1] = this;
        this->m_pMatrix->vect[this->x][this->y] = nullptr;
        return;
    }
    else if (this->m_pMatrix->vect[this->x - this->xVect][this->y + 1] == nullptr)
    {
        this->m_pMatrix->vect[this->x + this->xVect][this->y + 1]->push();
        this->xVect = 0;
        this->m_pMatrix->vect[this->x - this->xVect][this->y + 1] = this;
        this->m_pMatrix->vect[this->x][this->y] = nullptr;
        return;
    }
    else
        this->m_pMatrix->vect[this->x - this->xVect][this->y + 1]->push();
    return;
}

// left
void leftCell::drop()
{
    if (this->m_pMatrix->vect[this->x + this->xVect][this->y + 1] == nullptr)
    {
        this->xVect = 0;
        this->m_pMatrix->vect[this->x + this->xVect][this->y + 1] = this;
        this->m_pMatrix->vect[this->x][this->y] = nullptr;
        return;
    }
}

// right
void rightCell::drop()
{
    if (this->m_pMatrix->vect[this->x - this->xVect][this->y + 1] == nullptr)
    {
        this->xVect = 0;
        this->m_pMatrix->vect[this->x - this->xVect][this->y + 1] = this;
        this->m_pMatrix->vect[this->x][this->y] = nullptr;
        return;
    }
}

// wall
wall::wall(int _x, int _y)
{
    this->pChar = nullptr;
    this->x = _x;
    this->y = _y;
    this->xVect = 0;
    this->yVect = 0;
}