#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Employee {
public:
  static const int kMaxLen = 20;

  void SetData() {
    cout << "Enter first name: "; cin >> setw(kMaxLen-1) >> fname_;
    cout << "Enter middle name: "; cin >> setw(kMaxLen-1) >> mname_;
    cout << "Enter last name: "; cin >> setw(kMaxLen-1) >> lname_;
    cout << "Enter employee id: "; cin >> empid_;
  }

  void WriteFile(ostream &ofile) {
    ofile << fname_ << ' ' << mname_ << ' ' << lname_ << ' ' << empid_;
  }

  void PrintFile(istream &ifile) {
    while (!ifile.eof()) {
    ifile >> fname_ >> mname_ >> lname_ >> empid_;
    cout << fname_ << ' ' << mname_ << ' ' << lname_ << ' ' << empid_;
    }
  }

private:
  char fname_[kMaxLen], mname_[kMaxLen], lname_[kMaxLen];
  long empid_;
};

int main(int argc, char **argv) {
  Employee emp;
  char run;
  ofstream ofile;
  ofile.open("emp.dat");
  if (ofile.fail()) {
    cerr << "error opening file"; exit(1);
  }
  do {
    emp.SetData();
    emp.WriteFile(ofile);
    cout << "Enter another (y/n)? "; cin >> run;
  } while (run == 'y' && ofile.good());
  ofile.close();
  ifstream infile;
  infile.open("emp.dat");
  if (infile.fail()) {
    cerr << "error opening file"; exit(1);
  }
  emp.PrintFile(infile);
  infile.close();
  return 0;
}