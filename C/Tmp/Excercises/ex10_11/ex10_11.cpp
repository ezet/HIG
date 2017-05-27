#include <iostream>
using namespace std;

const int kSize = 10;

class MultiArray {
public:
  
  void MakeArray() {    
    int value = 0;
    for (int i = 0; i < kSize; ++i) {
      *(intarray+i) = new int[kSize];
      for (int j = 0; j < kSize; ++j )
      *(*(intarray+i)+j) = value++*kSize;
    }
  }

  int operator[] (int index) {
    int i = index / 10;
    int j = index % 10;
    return *(*(intarray+i)+j);
  }


private:
  int* intarray[kSize];


};

int main() {
  MultiArray test;
  test.MakeArray();
  cout << test[100];


  return 0;
}