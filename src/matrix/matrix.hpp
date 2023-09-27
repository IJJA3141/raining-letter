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

  void FindPath(int &_x, int &_y);

private:
#if DEBUG
public:
#endif
  struct Cell_ {
    std::string character;
    int x, y;
    bool locked;
    bool empty;

    Cell_(std::string _str, int _x, int _y, bool _locked, bool _empty)
        : character(_str), x(_x), y(_y), locked(_locked), empty(_empty){};
  };

  int width_;
  std::vector<std::vector<Cell_ *>> vVPtrCell_;
};

#if DEBUG
std::ostream &operator<<(std::ostream &_stream, Matrix &_matrix);
#endif
#endif // !MATRIX
