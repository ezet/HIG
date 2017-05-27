// Recursion, Lecture 8, 9
// Common patterns
// Handle first and/or last, recur on remaining
// Divide in half, recur on one/both halves
// Make a choice among options, recur on updated state


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Raise(int base, int exp) {
  int result = 1;
  for (int i = 1; i < exp; ++i)
    result *= base;
  return result;
}

int RaiseRec(int base, int exp) {
  if (exp == 0)
    return 1;
  else
    return base * RaiseRec(base, exp-1);
}

int RaiseRec2(int base, int exp) {
  if (exp == 0)
    return 1;
  else {
    int half = RaiseRec2(base, exp/2);
    if (exp % 2) return half * half;
    else return base * half * half;
  }
}

bool IsPalindrome(string s) {
  if (s.length() <= 1) return true;
  return s[0] == s[s.length()-1] && IsPalindrome(s.substr(1, s.length()-2));
}

const int NotFound = -1;
int BSearch(vector<string> &v, int start, int stop, string key) {
  if (start > stop) return NotFound;
  int mid = (start + stop)/2;
  if (key == v[mid])
    return mid;
  else if (key < v[mid])
    return BSearch(v, start, mid-1, key);
  else
    return BSearch(v, mid+1, stop, key);
}

void RecPermute(string sofar, string rest) {
  if (rest == "") {
    cout << sofar << endl;
  }
  else {
    for (int i = 0; i < rest.length(); ++i) {

    }
  }
}

int main(int argc, char *argv[]) {

}