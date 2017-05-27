#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee {
public:
  ~Employee() {
    for (int i = 0; i < 3; ++i)
      delete[] *(name_+i);
  }

  void SetData() {
    char buffer[100];
    cout << "Enter first name: ";
    cin >> buffer;
    *(name_+1) = new char[strlen(buffer)];
    cout << "Enter middle name: ";
    cin >> buffer;
    *(name_+2) = new char[strlen(buffer)];
    cout << "Enter last name: ";
    cin >> buffer;
    *(name_+3) = new char[strlen(buffer)];
    cout << "Enter employee id: ";
    cin >> empid_;
  }

  void PrintData() {
    for (int i = 0; i < 3; ++i)
      cout << *(name_+i) << ' ';
    cout << empid_;
  }

  void PrintFile() {
    while (file.good()) {
      ReadFile();
      PrintData();
    }
  }

  static void OpenFile(char *filename) {
    file.open(filename, ios::in | ios::out | ios::app);
    if (file.fail()) {
      cerr << "error opening " << filename << endl;
    }
  }

  static void CloseFile() {
    file.close();
  }

  void WriteFile() {
    for (int i = 0; i < 3; ++i)
      file << *(name_+i) << ' ';
    file << empid_;
  }

  void ReadFile() {
    for (int i = 0; i < 3; ++i)
      delete[] *(name_+i);
    char buffer[100];
    for (int i = 0; i < 3; ++i) {
      file >> buffer;
      *(name_+i) = new char[strlen(buffer)];
    }
    file >> empid_;
  }

private:
  static fstream file;
  int empid_;
  char *name_[3];
};

int main(int argc, char *argv[]) {
  Employee emp;
  char run;

  emp.OpenFile("emp.dat");
  do {
    emp.SetData();
    emp.WriteFile();
    cout << "Enter another (y/n)? "; cin >> run;
  } while (run == 'y');

  emp.PrintFile();
  
  return 0;
}