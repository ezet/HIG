#include <iostream>

const char C = '#';

int PrintBarSegment(char c) {
  std::cout  << c << c << c << "  ";
  return 0;
}

int main(int argc, char *argv[]) {
  int values[4];
  std::cout << "Enter 4 values, separated by space: ";

  for (int i = 0; i < 4; ++i) {
    std::cin >> values[i];
  }

  int total = 0;
  for (int i = 0; i < 4; ++i) {
    total += values[i];
  }

  for (int i = 0; i < 4; ++i) {
    values[i] *= 20.0 / total;
  }

  char bars[4][20];
  
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 20; ++j) {
      bars[i][j] = (j < values[i]) ? C : ' ';
    }
  }

  for (int i = 19; i >= 0; --i) {
    for (int j = 0; j < 4; ++j) {
      PrintBarSegment(bars[j][i]);
    }
    std::cout << '\n';
  }

  std::cout << "M4F  F4M  F4F  M4M\n\n";

  for (int i = 0; i < 4; ++i) {

  }

  return 0;
}