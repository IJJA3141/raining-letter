#ifndef MATRIX
#define MATRIX

#if DEBUG
#include <iostream>
#endif
#include <string>
#include <vector>

class Matrix {
public:
  Matrix(std::vector<std::string> &_vStr);

private:
#if DEBUG
public:
#endif
  struct Cell_ {
    const char *character;
    int x, y;
    bool locked;

    Cell_(const char *_char, int _x, int _y, bool _locked)
        : character(_char), x(_x), y(_y), locked(_locked){};
    ~Cell_();
  };

  int width_;
  std::vector<std::vector<Cell_ *>> vVPtrCell_;
};

#if DEBUG
#endif
std::ostream &operator<<(std::ostream &_stream, Matrix &_matrix);
#endif // !MATRIX
