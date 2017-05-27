#include <iostream>
using namespace std;

template <class T>
float Average(T arr[], int size) {
  float total = 0;
  for (int i = 0; i < size; ++i) {
    total += arr[i];
  }
  return total / size;
}