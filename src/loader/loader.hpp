#ifndef LOADER
#define LOADER

#if DEBUG
#include <iostream>
#endif

#include <fstream>
#include <string>
#include <vector>

class Loader {
public:
  std::vector<std::string> vStr;
  Loader(const char *_path);
};

#endif // !LOADER
