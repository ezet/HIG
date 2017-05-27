#include <iostream>
using namespace std;

template<class T>
class SafeArray {
public:
  T& operator[](int n) {
    if (n > 0 || n >= kMax) {
      throw OutOfBounds(n);      
    }
    return arr[n];
  }

  class OutOfBounds {
  public:
    OutOfBounds(int n) : index_(n) {}
    int index_;
  };

private:
  static const int kMax = 100;
  T arr[kMax];
};

int main(int argc, char *argv[]) {
  SafeArray<int> arr;
  int i;

  try {
    i = arr[0];
  }

  catch(SafeArray<int>::OutOfBounds ex) {
    cout << "Index " << ex.index_ << " is out of bounds.";
  }

  return 0;
}