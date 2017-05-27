#include <iostream>
using namespace std;

class String {
public:
  String() { stringarray_[0] = '\0'; }
  String(char s[]) { strncpy_s(stringarray_, s, kLimit-1); }
  operator char*() { return stringarray_; }

protected:
  static const int kLimit = 80;
  char stringarray_[kLimit];
};

class StringAssign : public String {
public:
  StringAssign(String string) { strcpy_s(stringarray_, string); }
  StringAssign() : String() {};
  StringAssign(char s[]) : String(s) {};
  
  StringAssign& Left(StringAssign string, int n) {
    strncpy_s(stringarray_, string, n);
    return *this;
  }
  
  StringAssign& Mid(StringAssign string, int s, int n) {
    for (int i = 0; i < n; i++) 
      stringarray_[i] = string[++s];
    return *this;
  }

  StringAssign& Right(StringAssign string, int n) {
    for (int i = (strlen(string) - n), j = 0; j < n; ++j, ++i)
      stringarray_[j] = string[i];
    return *this;
  }

private:

};

int main() {
  StringAssign test = "There is nothing like the jazz in you.";
  StringAssign target;
  target.Left(test, 10);
  cout << target << endl;
  target.Mid(test, 10, 10);
  cout << target << endl;
  target.Right(target, 10);
  cout << target << endl;

  return 0;
}
