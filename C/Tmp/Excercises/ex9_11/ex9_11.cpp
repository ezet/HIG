#include <iostream>
using namespace std;

const int kLimit = 100;

struct Coordinates {
  Coordinates(int xx, int yy) : x(xx), y(yy) {};
  int x, y;
};

class Stack {
public:
  Stack() : index_(0) {};
  void Push(int n) {
    stack_[++index_] = n;
  }
  int Pop() {
    return stack_[--index_];
  }

private:
  char stack_[kLimit];
  int index_;
};

class PairStack : public Stack {
public:
  PairStack(int x, int y) : Coords_(x, y) {};
  void Push(Coordinates coords) {
    Stack::Push(coords.x);
    Stack::Push(coords.y);
  }

  Coordinates Pop() {
    int y = Stack::Pop();
    return Coordinates(Stack::Pop(), y);
  }

private:
  Coordinates Coords_;
};