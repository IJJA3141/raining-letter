#include "./loader/loader.hpp"
#include "matrix/matrix.hpp"

#include <iostream>
#include <string>

int main() {
  Loader loader("./test.txt");
  Matrix matrix(loader.vStr);

  std::cout << "The end!" << std::endl;
  std::cout << matrix << std::endl;

  return 0;
}
