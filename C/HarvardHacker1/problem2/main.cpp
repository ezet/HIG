#include <iostream>
#include <string>

long long ExtractLastDigit(long long *n) {
  int digit = *n % 10;
  *n /= 10;
  return digit;
}

int SumDigits(int n) {
  int sum = 0;
  while (n) {
    sum += ExtractLastDigit((long long*)&n);
  }
  return sum;
}

int main(int argc, char *argv[]) {
  long long cardno, remaining;

  do {
    int sum = 0, twosum = 0;
    std::printf("Enter card number: ");
    std::cin >> cardno;

    remaining = cardno;
    while (remaining) {
      sum += ExtractLastDigit(&remaining);
      if (remaining) {
        twosum += SumDigits(ExtractLastDigit(&remaining) * 2);
      }
    }
    std::cout << (((sum + twosum) % 10) ? "\nINVALID" : "\nVALID") << std::endl;
  } while (cardno);


  return 0;
}