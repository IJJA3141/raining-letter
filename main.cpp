#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int xMaxSize(std::vector<std::vector<char>> _vector)
{
    int out = 0;

    for(int i = 0; i < _vector.size(); i++)
    {
        if(_vector[i].size() > out)
        {
            out = _vector[i].size();
        }
    }

    return out;
}

std::vector<std::vector<char>> normalize(std::vector<std::vector<char>> _vector)
{
    int maxSize = xMaxSize(_vector);

    for(size_t i = 0; i < _vector.size(); i++)
    {
        for (size_t j = _vector[i].size(); j < maxSize; j++)
        {
            char l = " "[0];
            _vector[i].push_back(l);
        }        
    }

    return _vector;
}

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

std::vector<std::vector<char>> drop(std::vector<std::vector<char>> _vector)
{
    for (size_t i = _vector.size() - 2; i <= 0; i--)
    {
        if(_vector[i + 1][0] == " "[0])
        {
            _vector[i + 1][0] = _vector[i][0];
        } else if (_vector[i + 1][1] == " "[0]){
            _vector[i + 1][1] = _vector[i][0];
        }

        if(_vector[i + 1][_vector[i].size() - 1] == " "[0])
        {
            _vector[i + 1][_vector[i].size() - 1] = _vector[i][_vector[i].size() - 1];
        } else if (_vector[i + 1][_vector[i].size() - 2] == " "[0]){
            _vector[i + 1][_vector[i].size() - 2] = _vector[i][_vector[i].size() - 1];
        }

        /*
        for (size_t j = 1; j < _vector[i].size() - 2; j++)
        {
            
        }
        */
    }

    return _vector;
}

int main()
{
    const char* t_path = ".txt";

    std::vector<std::vector<char>> o = read(t_path);
    printVector(drop(normalize(o)));
    
    std::cin.get();
    return 0;
}