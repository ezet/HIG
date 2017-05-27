#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  float *arr = new float[5];
  int index = 0, max = 5;
  char run;
  
  do {
    if (index == max-1) {
      float *newarr = new float[max*2];
      memcpy(newarr, arr, max*sizeof(float));
      delete[] arr;
      arr = newarr;
      max *= 2;
    }
    cout << "Enter number: ";
    cin >> arr[index++];
    cout << "Enter another (y/n)? ";
    cin >> run;
  } while (run == 'y');

  float sum = 0.0F;
  for (int i = 0; i < index; ++i) {
    sum += *(arr+i);
  }
  cout << "Average is: " << sum / index-1 << endl;

  return 0;
}