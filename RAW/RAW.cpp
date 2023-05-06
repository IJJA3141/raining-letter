#include "RAW.h"
#include <iostream>

void read(const char *_path, std::vector<char> *_pvCharacter, std::vector<int> *_pvInt)
{
    std::fstream file;
    _pvCharacter->clear();
    _pvInt->clear();
    _pvInt->push_back(-1);

    file.open(_path, std::ios::in);
    if (file.is_open())
    {
        std::string str;
        while (std::getline(file, str))
        {
            _pvInt->push_back(str.length() + _pvInt->back());
            for (int i = 0; i < str.length(); i++)
                _pvCharacter->push_back(str[i]);
        }
        file.close();
    }
    return;
}

/*
void render(const char* _path, std::string _out)
{
    std::fstream file;
    file.open(_path, std::ios::out);
    {
        file << _out;
    }
    file.close();
    return;
}

void printVector(std::vector<std::vector<char>> _vector)
{
    for(size_t i = 0; i < _vector.size(); i++)
    {
        for (size_t j = 0; j < _vector[i].size(); j++)
        {
            std::cout << "[" << _vector[i][j] << "]";
        }

        std::cout << "\n";
    }
}
*/