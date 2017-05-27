#include <iostream>
using namespace std;

// mergesort
void MergeSort() {
  if (size() > 1) {
    int n1 = v.size() / 2;
    int n2 = v.size() - n1;
    MergeSort(n1);
    MergeSort(n2);
  }
}