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
    std::cout << "\n\n";
    printVector(_vector);
    std::cout << "\n\n";
    std::cout << "-1 :";
    for (int i = _vector.size() - 2; i >= 0; i--)
    {
        std::cout << "0 ";
        for (size_t j = 0; j < _vector[i].size(); j++)
        {
            if(j == 0 || j == _vector[i].size() - 1)
            {
                std::cout << "0.5 ";
                if(j == 0)
                {
                    if(_vector[i + 1][j] == " "[0])
                    {
                        std::cout << "1 ";
                        _vector[i + 1][j] = _vector[i][j];
                        _vector[i][j] = " "[0];
                    } else if(_vector[i + 1][j + 1] == " "[0]) {
                        std::cout << "2 ";
                        _vector[i + 1][j + 1] = _vector[i][j];
                        _vector[i][j] = " "[0];
                    }
                } else {
                    if(_vector[i + 1][_vector[i].size() - 1] == " "[0])
                    {
                        std::cout << "3 ";
                        _vector[i + 1][_vector[i].size() - 1] = _vector[i][_vector[i].size() - 1];
                        _vector[i][_vector[i].size() - 1] = " "[0];
                    } else if(_vector[i + 1][_vector[i].size() - 2] == " "[0]) {
                        std::cout << "4 ";
                        _vector[i + 1][_vector[i].size() - 2] = _vector[i][_vector[i].size() - 1];
                        _vector[i][_vector[i].size() - 1] = " "[0];
                    }
                }
            } else {

            }
        }
    }

    std::cout << "\n\n";
    return _vector;
}

int main()
{
    const char* t_path = ".js";

    std::vector<std::vector<char>> o = read(t_path);
    printVector(drop(drop(drop(drop(drop(drop(normalize(o))))))));
    
    std::cin.get();
    return 0;
}