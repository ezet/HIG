#include <iostream>
using namespace std;

int CompString(char* str1, char* str2) {
  for (unsigned int i = 0; i < strlen(str1) || i < strlen(str2); ++i) {
    if (*(str1+i) < *(str2+i))
      return -1;
    if (*(str2+i) < *(str1+i))
      return 1;
  }
  return 0;
}

int main() {
  char* string1 = "I love the way you jazz.";
  char* string2 = "I love the way you jazz.";

  int result = CompString(string1, string2);
  cout << result << '\n';
    return 0;
}