#include <iostream>
using namespace std;

class Array {
public:
  Array(int s) {
    size_ = s;
    pointer_ = new int[size_];
  };
  Array(Array& arr) {
    size_ = arr.size_;
    pointer_ = new int[size_];
    for (int i = 0; i < size_; ++i)
      *(pointer_+i) = *(arr.pointer_+i);
  }    
  ~Array() { delete[] pointer_; }

  int& operator[](int i) { return *(pointer_+i); }
  Array& operator=(Array& arr) {
    size_ = arr.size_;
    pointer_ = new int[size_];
    for (int i = 0; i < size_; ++i)
      *(pointer_+i) = *(arr.pointer_+i);
    return *this;
  }

private:
  int *pointer_;
  int size_;
};

int main() {
  const int kSize = 20;
  Array arr1(kSize);
  Array arr2(kSize);

  for (int i = 0; i < kSize; ++i)
    arr1[i] = i;

 
 Array arr3(arr2);
 arr3 = arr2 = arr1;

  for (int i = 0; i < kSize; ++i )
  cout << arr3[i] << " ";

  cout << endl;
  return 0;
}
