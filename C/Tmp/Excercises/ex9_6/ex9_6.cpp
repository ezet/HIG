#include <iostream>
using namespace std;

const int kLimit = 100;

class SafeArray {
public:
  int& operator[](int n) {
    if (n < 0 || n >= kLimit) {
      cout << "\nIndex is out of bounds"; exit(1);
    }
  return array_[n];
  }

protected:
  int array_[kLimit];
};

class SaferArray : private SafeArray {
public:
  SaferArray(int lowerlimit, int upperlimit) : kLowerLimit(lowerlimit), kUpperLimit(upperlimit) {
  }

  int& operator[](int n) {
    if (n < kLowerLimit || n >= kUpperLimit) {
      cout << "\nIndex is out of bounds"; exit(1);
    }
    return array_[n-kLowerLimit];
  }

private:
  const int kUpperLimit, kLowerLimit;
};

int main() {
  SaferArray test(100, 200);
  for (int i = 100; i <= 200-1; ++i){
    test[i] = i;
  }

  cout << test[200] << '\n';
  return 0;
}