#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int n1 = 111, n2 = 222, n3 = 333, n4 = 444, n5 = 555;
  int intarray[5] = {111, 222, 333, 444, 555};
  int *arrptr = intarray;
  int *ptr = &n3;
  char cmd;

  do {
    cout << "Enter command: ";
    cin >> cmd;
    switch (cmd) {
    case 'i': ++ptr; ++arrptr; break;
    case 'd': --ptr; --arrptr; break;
    case '!': break;
    default: cout << "Unknown command";
    }
    cout << ptr << ": " << *ptr << endl;
    cout << arrptr << ": " << *arrptr << endl;
  } while (cmd != '!');


  return 0;
}