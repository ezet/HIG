#include <iostream>
using namespace std;

template<typename T>
class Vector {
public:
  Vector();
  ~Vector();
  int Size();
  T GetAt(int index);
  void SetAt(int index, T t);
  void InsertAt(int index, T t);

private:
  T *arr;
  int used_, alloc_;
  void DoubleCapacity();
};

int main(int argc, char *argv[]) {

  return 0;
};