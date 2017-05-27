#include <iostream>
using namespace std;

void AddArrays(float* ar1, float* ar2, float* ar3, const int kSize) {
  for (int i = 0; i < kSize; ++i)
    *(ar3+i) = *(ar1+i) + *(ar2+i);
}

int main() {
  const int kSize = 10;
  float array1[kSize], array2[kSize], array3[kSize];
  for (int i = 0; i < kSize; ++i) {
    *(array1+i) = static_cast<float>(i);
    *(array2+i) = static_cast<float>(i);
  }
  AddArrays(array1, array2, array3, kSize);

  for (int i = 0; i < kSize; ++i)
    cout << *(array3+i) << '\n';
  return 0;
}