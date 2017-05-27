#include <iostream> 
using namespace std;


int main() {
  int* intarray = new int [80];
  int total = 0, count = 0;
  char run;
  
  do {
    cout << "Enter int: "; cin >> *(intarray+count); total += *(intarray+count++);
    cout << "Enter another (y/n): "; cin >> run;
  } while (run != 'n');

  cout << "Average: " << total / count;


  return 0;
}