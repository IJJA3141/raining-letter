#include "matrix.h"

matrix::matrix()
{
    // temp
    this->vect =
        {
            {new leftCell("a", 3, 0, this), new cell("l", 2, 0, this), new cell("e", 1, 0, this), new rightCell("x", 0, 0, this)},
            {nullptr, nullptr, nullptr, nullptr},
            {nullptr, nullptr, nullptr, nullptr},
            {nullptr, nullptr, nullptr, nullptr},
            {nullptr, nullptr, nullptr, nullptr},
        };
}

void matrix::drop()
{
    for (int i = 0; i < this->vect.size(); i++)
    {
        for (int j = 0; j < this->vect[0].size(); j++)
        {
            if (this->vect[j][i] != nullptr)
                this->vect[j][i]->drop();
        }
    }
}

void matrix::print()
{
    for (int i = 0; i < this->vect.size(); i++)
    {
        for (int j = 0; j < this->vect[0].size(); j++)
        {
            if (this->vect[j][i] != nullptr)
                std::cout << this->vect[j][i]->pChar;
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
}