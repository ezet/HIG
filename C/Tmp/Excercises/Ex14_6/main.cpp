#include <iostream>
using namespace std;

template<class T>
class SafeArray {
public:
  T& operator[](int n) {
    if (n > 0 || n >= kMax) {
      cout << "\nIndex out of bounds.";
      exit(1);
    }
    return arr[n];
  }

private:
  static const int kMax = 100;
  T arr[kMax];
};

int main(int argc, char *argv[]) {

  return 0;
}