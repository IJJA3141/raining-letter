#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "table.h"

std::vector<std::vector<char>> read(const char* _path)
{
    std::vector<std::vector<char>> out = {};
    std::fstream file;

    file.open(_path, std::ios::in);
    if(file.is_open())
    {
        int j = 0;
        std::string str;
        std::vector<char> t_out = {};
        
        while (std::getline(file, str))
        {
            t_out = {};
            for (size_t i = 0; i < str.length(); i++)
            {
                char l = str[i];
                t_out.push_back(l);
            }
            
            out.push_back(t_out);
            j++;
        }
    }

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

int main()
{
    const char* t_path = ".txt";

    std::vector<std::vector<char>> o = read(t_path);
    table a = table(o);
    
    a.trunOnGravity();
    

    std::cin.get();
    return 0;
}