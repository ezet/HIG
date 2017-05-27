#pragma once

struct Tile {
public:
  Tile() {

  }

  Tile(const int num) {
    num_ = num;
  }

  void set_num(const int num) {
    num_ = num;
  }

  int num() const {
    return num_;
  }


private:
  int num_;

};