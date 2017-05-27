#include <iostream>

class String {
public:
  String() { strcpy(str, ""); }
  String(char s[]) { strcpy(str, s); }
  void PrintString() const { std::cout << str; }
  String operator + (String ss);
  String operator += (String ss);
private:
  static const int kSize = 80;
  char str[kSize];
};

String String::operator + (String ss) {
  String temp;
  if (strlen(str) + strlen(ss.str) < kSize) {
    strcpy(temp.str, str);
    strcat(temp.str, ss.str);
  }
  else {
    std::cout << "\nERROR: string overflow"; exit(1); }
  return temp;
}

String String::operator + (String ss) {
  if (strlen(str) + strlen(ss.str) < kSize)
    strcat(str, ss.str);
  else
    std::cout << "\nERROR: string overflow"; exit (1);
  return String(str);
}





