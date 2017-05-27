#include <iostream>
using namespace std;

int main() {
  const int kSize = 10;
  int* intarray[kSize];
  int value = 0;
  for (int i = 0; i < kSize; ++i) {
    *(intarray+i) = new int[kSize];
    for (int j = 0; j < kSize; ++j )
    intarray[i][j] = value++*kSize;
  }

  for (int i = 0; i < kSize; ++i) {
    for (int j = 0; j < kSize; ++j)
      cout << intarray[i][j] << ' ';
  }

  return 0;
}