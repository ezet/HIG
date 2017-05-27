#include <iostream>
#include <cctype>
using namespace std;

class String {
public:
  String(char* s) {
    int length = strlen(s);
    string_ = new char[length+1];
    strncpy_s(string_, length+1, s, _TRUNCATE);
  }

  ~String() { delete[] string_; }
  void PrintString() {
    cout << string_ << '\n';
  }

  void ToUpper() {
    int i = 0;
    while (*(string_+i)) {
      *(string_+i) = toupper(*(string_+i));
      i++;
    }
  }

private:
  char* string_;
};

int main() {
  String test("i love the way you jazz.");

  test.ToUpper();
  test.PrintString();
return 0;
}