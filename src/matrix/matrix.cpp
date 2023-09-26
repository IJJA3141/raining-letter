#include "./matrix.hpp"

Matrix::Matrix(std::vector<std::string> &_vStr) {
  this->width_ = 0;

  for (std::string _str : _vStr) {
    if (this->width_ < _str.size())
      this->width_ = _str.size();
  }

  for (int i = 0; i < _vStr.size(); i++) {
    this->vVPtrCell_.push_back(std::vector<Matrix::Cell_ *>(this->width_));

    for (int j = 0; j < this->width_; j++) {
      if (j < _vStr[i].size() && _vStr[i].compare(j, 1, " ") != 0)
        this->vVPtrCell_[i][j] =
            new Matrix::Cell_(_vStr[i].substr(1, j).c_str(), j, i, false);
      else
        this->vVPtrCell_[i][j] = new Matrix::Cell_(nullptr, j, i, false);
    }
  }

#if DEBUG
  std::cout << "height: " << this->vVPtrCell_.size()
            << "\nwidth: " << this->vVPtrCell_[0].size() << std::endl;
#endif

  bool slash = false;
  bool pointSlash = false;

  for (int i = 0; i < this->vVPtrCell_.size(); i++) {
#if DEBUG
    std::cout << "i: " << i << "\n";
#endif
    for (int j = 0; j < this->width_; j++) {
#if DEBUG
      std::cout << "j: " << j << "\n";
#endif
      if (slash || pointSlash) {
        this->vVPtrCell_[i][j]->locked = true;

        if (strcmp(this->vVPtrCell_[i][j]->character, "*") == 0 &&
            j + 1 < this->width_)
          if (strcmp(this->vVPtrCell_[i][++j]->character, "/") == 0) {
            this->vVPtrCell_[i][j]->locked = true;
            pointSlash = false;
          }

      } else if (strcmp(this->vVPtrCell_[i][j]->character, "/") == 0 &&
                 j + 1 < this->width_) {
        if (strcmp(this->vVPtrCell_[i][++j]->character, "/") == 0) {
          this->vVPtrCell_[i][j - 1]->locked = true;
          slash = true;
        } else if (strcmp(this->vVPtrCell_[i][j]->character, "*") == 0) {
          this->vVPtrCell_[i][j - 1]->locked = true;
          pointSlash = true;
        }
      }
    }
    slash = false;
  }

#if DEBUG
  std::cout << "\nThe end\n" << std::endl;
#endif
  return;
}

#if DEBUG

std::ostream &operator<<(std::ostream &_stream, Matrix &_matrix) {
  std::string str;

  for (int i = 0; i < _matrix.vVPtrCell_.size(); i++) {
    str = "";

    for (int j = 0; j < _matrix.width_; j++) {
      if (_matrix.vVPtrCell_[i][j]->locked) {
        str += "\033[1;31m";
        str += _matrix.vVPtrCell_[i][j]->character;
        str += "\033[0m";
        _stream << str;
      } else {
        str += "\033[1;32m";
        str += _matrix.vVPtrCell_[i][j]->character;
        str += "\033[0m";
        _stream << str;
      }
    }
    _stream << "\n";
  }

  return _stream;
}

#endif
