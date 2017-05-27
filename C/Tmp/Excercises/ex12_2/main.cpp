#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
  argc = 3;
  argv[1] = "ifile.txt";
  argv[2] = "ofile.txt";
  if (argc != 3) {
    cerr << "Argument error.";
    exit(1);
  }
  ifstream ifile(argv[1]);
  if (!ifile) {
    cerr << "Error opening ifile.";
    exit(1);
  }
  ofstream ofile(argv[2]);
  if (!ofile) {
    cerr << "Error opening ofile.";
    exit(1);
  }
  char ch;
  while (!ifile.eof()) {
    ifile.get(ch);
    ofile.put(ch);
  }
  return 0;
}