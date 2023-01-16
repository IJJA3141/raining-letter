#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "page.h"

std::vector<std::string> read(const char* _path)
{
    std::vector<std::string> out;
    
    std::ofstream file;
    file.open(_path, std::ios::in | std::ios::app);
    if(file.is_open())
    {
        std::string str;
        while(std::ios::getline(file, str))
        {
            out.push_back/str;
        }
    }

    file.close();
    return out;
}

void write(const char* _path, std::string _out)
{
    std::ofstream file;
    file.open(_path, std::ios::out);

    file.close();
    return;
}

int main()
{
    page p = page({"abcd", "efghijk", "lmnop", "qrstuvwxyz"});
    for(int i = 0; i < p.vLetter.size(); i++)
    {
        std::cout 
        << p.vLetter[i]->character << ": "
        << p.vLetter[i]->x
        << p.vLetter[i]->y << "\n";
    }
    std::cin.get();
    return 0;
}