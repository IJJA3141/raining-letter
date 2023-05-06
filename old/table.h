class table
{
private:
    int m_x = NULL;
    int m_y = NULL;
    
    char** m_ppChar = nullptr;

    bool m_fall(int _offset);
    int m_canFall(int _x, int _y, int _offest);
    int m_size(std::vector<std::vector<char>> _vector);

public:
    table(std::vector<std::vector<char>> _vector);
    ~table();
    
    void print();
    void printc();
    void trunOnGravity();
};