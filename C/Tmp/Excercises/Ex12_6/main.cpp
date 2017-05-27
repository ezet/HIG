#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee {
public:
  static const int kMaxLen = 20;
  Employee() : empid_(-1) {};

  void SetData() {
    cout << "Enter first name: "; cin >> setw(kMaxLen-1) >> fname_;
    cout << "Enter middle name: "; cin >> setw(kMaxLen-1) >> mname_;
    cout << "Enter last name: "; cin >> setw(kMaxLen-1) >> lname_;
    cout << "Enter employee id: "; cin >> empid_;
  }

  void PrintData() {
    cout << fname_ << ' ' << mname_ << ' ' << lname_ << ' ' << empid_ << endl;
  }

  bool WriteFile(char *filename) {
    ofstream ofile;
    ofile.open(filename, ios::app);
    if (ofile.fail()) return 0;
    ofile << fname_ << ' ' << mname_ << ' ' << lname_ << ' ' << empid_;
    ofile.close();
    return 1;
  }

  bool ReadFile(char *filename, int n) {
    ifstream ifile;
    ifile.open(filename);
    if (ifile.fail()) return 0;
    for (int i = 0; i <= n; ++i) {
      ifile >> fname_ >> mname_ >> lname_ >> empid_;
    }
    ifile.close();
    return 1;
  }

private:
  int empid_;
  char fname_[kMaxLen], mname_[kMaxLen], lname_[kMaxLen];
};

  int main(int argc, char *argv[]) {
    //char run;
    char *filename = "emp.dat";
    Employee emp[2];

    for (int i = 0; i < 2; ++i) {
      emp[i].SetData();
      emp[i].WriteFile(filename);
    }

    for (int i = 0; i < 2; ++i) {
      emp[i].ReadFile(filename, 1-i);
      emp[i].PrintData();
    }

    return 0;
  }