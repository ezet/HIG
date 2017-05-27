#include <iostream>
using namespace std;

class String {
public:
  String() { stringarray_[0] = '\0'; }
  String(char s[]) { strncpy(stringarray_, s, kLimit-1); }  

private:
  static const int kLimit = 80;
  char stringarray_[kLimit];
};

int main() {
  String test = "test1";
  test = "test";
  return 0;
}