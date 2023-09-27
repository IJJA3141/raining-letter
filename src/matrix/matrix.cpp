#include "./matrix.hpp"

Matrix::Matrix(std::vector<std::string> &_vStr) {
  this->width_ = 0;
  Matrix::Cell_ *border = new Matrix::Cell_("", 0, 0, true, true);

  for (std::string _str : _vStr) {
    if (this->width_ < _str.size()) {
      this->width_ = _str.size();
    }
  }

  this->vVPtrCell_.push_back(std::vector<Matrix::Cell_ *>(this->width_ + 2));
  for (int i = 0; i < this->width_ + 2; i++)
    this->vVPtrCell_[this->vVPtrCell_.size() - 1][i] = border;

  for (int i = 0; i < _vStr.size(); i++) {
    this->vVPtrCell_.push_back(std::vector<Matrix::Cell_ *>(this->width_ + 2));

    this->vVPtrCell_[i][0] = border;
    this->vVPtrCell_[i][this->width_ + 1] = border;

    for (int j = 1; j <= this->width_; j++) {
      if (j < _vStr[i].size() && _vStr[i].compare(j, 1, " ") != 0) {
        this->vVPtrCell_[i][j] =
            new Matrix::Cell_(_vStr[i].substr(j, 1), j, i, false, false);
      } else {
        this->vVPtrCell_[i][j] = new Matrix::Cell_(" ", j, i, false, true);
      }
    }
  }

  this->vVPtrCell_.push_back(std::vector<Matrix::Cell_ *>(this->width_ + 2));
  for (int i = 0; i < this->width_ + 2; i++)
    this->vVPtrCell_[this->vVPtrCell_.size() - 1][i] = border;

  bool slash = false;
  bool pointSlash = false;

  for (int i = 0; i < this->vVPtrCell_.size() - 1; i++) {
    for (int j = 1; j <= this->width_; j++) {
      if ((slash || pointSlash) && !this->vVPtrCell_[i][j]->empty) {
        this->vVPtrCell_[i][j]->locked = true;

        if (this->vVPtrCell_[i][j]->character == "*" && j + 1 <= this->width_) {
          if (this->vVPtrCell_[i][++j]->character == "/") {
            this->vVPtrCell_[i][j]->locked = true;
            pointSlash = false;
          }
        }
      } else if (this->vVPtrCell_[i][j]->character == "/" &&
                 j + 1 <= this->width_) {
        if (this->vVPtrCell_[i][++j]->character == "/") {
          this->vVPtrCell_[i][j - 1]->locked = true;
          this->vVPtrCell_[i][j]->locked = true;
          slash = true;
        } else if (this->vVPtrCell_[i][j]->character == "*") {
          this->vVPtrCell_[i][j - 1]->locked = true;
          this->vVPtrCell_[i][j]->locked = true;
          pointSlash = true;
        }
      }
    };

    slash = false;
  }

  return;
};

#if DEBUG
std::ostream &operator<<(std::ostream &_stream, Matrix &_matrix) {
  std::string str;
  for (int i = 0; i < _matrix.vVPtrCell_.size(); i++) {

    for (int j = 0; j <= _matrix.width_; j++) {
      str = "";
      if (_matrix.vVPtrCell_[i][j]->locked) {
        str += "[\033[1;31m";
        str += _matrix.vVPtrCell_[i][j]->character;
        str += "\033[0m]";
        _stream << str;
      } else {
        str += "[\033[1;32m";
        str += _matrix.vVPtrCell_[i][j]->character;
        str += "\033[0m]";
        _stream << str;
      }
    }
    _stream << "\n";
  }

  return _stream;
}
#endif
