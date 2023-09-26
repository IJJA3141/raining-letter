#include "./loader.hpp"

Loader::Loader(const char *_path) {
  this->vStr = {};

  std::ifstream stream(_path);
  if (stream.is_open()) {
#if DEBUG
    std::cout << _path << " has been open" << std::endl;
#endif
    std::string str;
    while (std::getline(stream, str))
      this->vStr.push_back(str);
  } else {
    exit(1);
  }

#if DEBUG
  std::cout << "loader:\n";

  for (int i = 0; i < this->vStr.size(); i++) {
    for (int j = 0; j < this->vStr[i].size(); j++)
      std::cout << this->vStr[i][j];
    std::cout << "\n";
  }

  std::cout << std::endl;
#endif

  return;
}
