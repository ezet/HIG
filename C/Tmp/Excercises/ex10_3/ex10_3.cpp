#include <iostream>
using namespace std;

void Order(const char** n1, const char** n2) {
  if (**n1 > **n2) {
    const char* temp = *n1;
    *n1 = *n2;
    *n2 = temp;
  }
}

void BubbleSort(const char** pointer, const int n) {
  int j, k;
  for (j = 0; j < n-1; ++j) {
    for (k = j+1; k < n; ++k)
      Order(pointer+j, pointer+k);
  }
 }


int main() {
  const char* days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
  const int N = 7;
  BubbleSort(days, N);

  for (int i = 0; i < N; ++i) {
    cout << *(days+i) << ' ';
  }
 
  
  
  return 0;
}