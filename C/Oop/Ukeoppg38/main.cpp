#include <iostream>
using namespace std;

void InitArray(int *arr, int kLen, int value) {
  for (int i = 0; i < kLen; ++i)
    *arr = value;
}

void PrintArray(int *arr, int kLen) {
  for (int i = 0; i < kLen; ++i)
    cout << '\n' << *arr;
}

int main(int argc, char *argv[]) {
  const int kLen = 5;
  int intarray[kLen];
  InitArray(intarray, kLen, 2);
  PrintArray(intarray, kLen);
  return 0;
}