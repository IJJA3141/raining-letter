#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "page.h"

std::vector<std::string> read(const char* _path)
{
    std::vector<std::string> out;
    std::fstream file;
    
    file.open(_path, std::ios::in);
    if(file.is_open())
    {
        std::string str;
        while (std::getline(file, str))
        {
            out.push_back(str);
        }
    }

    file.close();
    return out;
}

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

int main()
{
    const char* t_path = ".txt";

    page p = page(read(t_path));

    for(int i = 0; i < p.vvLetter.size(); i++)
    {
        for(size_t j = 0; j < p.vvLetter[i].size(); j++)
        std::cout 
        << p.vvLetter[i][j]->character << ": "
        << p.vvLetter[i][j]->x
        << p.vvLetter[i][j]->y << "\n";
    }
    
    return 0;
}