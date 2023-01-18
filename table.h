class table
{
private:
    int m_x = NULL;
    int m_y = NULL;
    
    char** m_ppChar = nullptr;

    int m_size(std::vector<std::vector<char>> _vector);
    int m_canFall(int _x, int _y);
    void m_printc();
    void m_print();

public:
    table(std::vector<std::vector<char>> _vector);
    ~table();
    
    void m_fall();
};