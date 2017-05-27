#include <iostream>
using namespace std;

void test(int &ref, int ref2, int *ptr) {
  cout << &ref;
  cout << ref2;
  cout << &ptr;
}

int global = 2;

int main(int argc, char *argv[]) {
 int n = 1;
 int n2[5];
char str1[1000000] = "test";
char *str2 = "test";
char *str3 = new char[5];
cout << &global << &n << n2 << str1 << &str1 << str2 << &str2 << str3 << &str3;
}