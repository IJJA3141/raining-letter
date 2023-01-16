#pragma once

struct letter
{
public:
    letter(char _character, int _x, int _y);
    char character;
    int x;
    int y;
};

class page
{
public:
    page(std::vector<std::string> _text);

    std::vector<string> drop();
    std::vector<std::string> text;
    std::vector<std::vector<letter*>> vvLetter;
};