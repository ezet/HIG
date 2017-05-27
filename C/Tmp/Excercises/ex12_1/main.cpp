#include <iostream>
#include <fstream>
using namespace std;

class Distance {
 public:
  Distance() : feet_(0), inches_(0.0) {}
  Distance(int feet, float inches) : feet_(feet), inches_(inches) {}
  void GetData() {
    cout << "\nEnter feet: "; cin >> feet_;
    cout << "Enter inches: "; cin >> inches_;
  }
  void PrintData() {
    cout << "Distance: " << feet_ << "\'-" << inches_ << "\"\n";
  }

 private:
  int feet_;
  float inches_;
};

int main(int argc, char *argv[]) {
  Distance d1;
  char run;

  fstream file;
  file.open("data.dat", ios::binary | ios::app | ios::in | ios:: out); 
  
  do {
    d1.GetData();
    file.write(reinterpret_cast<char*>(&d1), sizeof(d1));
    cout << "Enter another (y/n)?"; cin >> run;
  } while(run == 'y');

  file.seekg(0);
  while(file.good()) {
    file.read(reinterpret_cast<char*>(&d1), sizeof(d1));
    d1.PrintData();
    file.peek();
  }
  return 0;    
}
