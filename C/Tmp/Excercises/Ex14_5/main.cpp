#include <iostream>
using namespace std;

template<class T>
T Max(T arr[], int size) {
  T max = arr[0];
  for (int i = 0; i < size; ++i) {
    if (arr[i] > max) max = arr[i];
  }
  return max;
}

int main(int argc, char *argv[]) {

  return 0;
}