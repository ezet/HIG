#include <iostream>
using namespace std;

int Strlen(const char *s) {
  int i = 0;
  while (*(s+i) != '\0')
    ++i;
  return i;
}

char* Strcpy(char *s, const char *t) {
  int i;
  for (i = 0; *(t+i) != '\0'; ++i)
    *(s+i) = *(t+i);
  *(s+i+1) = '\0';
  return s;
}

char* Strcat(char *s, const char *t) {
  int i, length = Strlen(s);
  for (i = 0; *(t+i) != '\0'; ++i)
    *(s+length+i) = *(t+i);
  *(s+length+i) = '\0';
  return s;
}

int Strcmp(const char *s, const char *t) {
  int slen = Strlen(s);
  for (int i = 0; i < slen; ++i) {
    if (*(s+i) < *(t+i))
      return *(s+i) - *(t+i);
    if (*(s+i) > *(t+i))
      return (*(s+i) - *(t+i));
  }
  if (slen != Strlen(t))
    return slen - Strlen(t);
  return 0;
}

int main(int argc, char *argv[]) {
  char texta[40] = "test text";
  char textb[40] = "test text nummer 2";
  cout << "Strlen: " << Strlen(texta) << '\n';
  cout << "Strcpy: " << Strcpy(texta, textb) << '\n';
  cout << "Strcat: " << Strcat(texta, textb) << '\n';
  cout << "Strcmp: " << Strcmp(texta, textb) << '\n';
  cout << strcmp(texta, textb) << '\n';




  cout << endl;
  return 0;
}