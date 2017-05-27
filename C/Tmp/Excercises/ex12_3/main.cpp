#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
  argv[1] = "test.txt";
  if (argc != 1) {
    cerr << "Wrong number of arguments.";
    exit(1);
  }
  ifstream ifile(argv[1], ios::ate);
  cout << "\nSize is " << (ifile.tellg()) << '\n';
}