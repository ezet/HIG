#include <iostream>
using namespace std;

class Vector {
public:
  Vector() : x_(0), y_(0) {}
  Vector(int x, int y) : x_(x), y_(y) {}

  Vector operator+(Vector v);
  Vector operator-(Vector v);
  Vector operator*(int n);
  Vector operator/(int n);
  friend ostream& operator<<(ostream& s, Vector& v);

  void PrintTime() {
    cout << *this;
  }

private:
  int x_, y_;
};

int main(int argc, char *argv[]) {
  Vector v1(3,4), v2(4,2);
  cout << (v1 + v2) << '\n';
  cout << (v1 - v2) << '\n';
  cout << (v1 * 3) << '\n';
  cout << (v2 / 2) << '\n';
  v1.PrintTime();
  v2.PrintTime();
  return 0;
};

Vector Vector::operator+(Vector v) {
  return Vector(x_ + v.x_, y_ + v.y_);
};

Vector Vector::operator-(Vector v) {
  return Vector(x_ - v.x_, y_ - v.y_);
};

Vector Vector::operator*(int n) {
  return Vector(x_ * n, y_ * n);
};

Vector Vector::operator/(int n) {
  if (x_ % n != 0 || y_ % n != 0) {
    cout << "Cannot perform division.";
    return Vector();
  }
  return Vector(x_ / n, y_ / n);
};

ostream& operator<<(ostream& s, Vector& v) {
  s << v.x_ << ',' << v.y_;
  return s;
};