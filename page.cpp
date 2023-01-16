#include <string>
#include <vector>
#include "page.h"

letter::letter(char _character, int _x, int _y)
{
    this->character = _character;
    this->x = _x;
    this->y = _y;
    return;
}

page::page(std::vector<std::string> _text)
{
    this->text = _text;

    for(size_t i = 0; i < _text.size(); i++)
    {
        for(size_t j = 0; j < _text[i].length(); j++)
        {
            if(_text[i][j] != *" ")
            {
                this->vLetter.push_back(new letter(_text[i][j], j, i));
            }
        }
    }

    return;
}