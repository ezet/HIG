#include <iostream>
#include <string>
using namespace std;

class Distance {
public:
  class Excep {
  public:

  };

  Distance() : feet_(0), inches_(0) {}
  Distance(int ft, int in) : feet_(ft), inches_(in) {}

  void PrintDistance() {
    cout << feet_ << "\'-" << inches_ << '\"';
  }


  void SetDistance() {
    string buffer;
    while (true) {
      cout << "Enter feet: ";
      cin >> noskipws >> buffer;
      if (IsFeet(buffer)) {
        cin.ignore(10, '\n');
        feet_ = atoi(buffer.c_str());
        break;
      }
      cin.ignore(10, '\n');
      cout << "Feet must be an integer less than 1000\n";
    } // endwhile
    while (true) {
      cout << "Enter inches: ";
      cin >> noskipws >> inches_;
      if (inches_ >= 12 || inches_ < 0) {
        cout << "Inches must  be between 0 and 12.";
        cin.clear(ios::failbit);
      }
      if (cin.good()) {
        cin.ignore(10, '\n');
        break;
      }
      cin.clear();
      cin.ignore(10, '\n');
      cout << "Incorrect inches input\n";
    } // endwhile
  }

  int IsFeet(string buffer) {
    int slen = buffer.size();
    if (slen == 0 || slen < 5)
      return 0;
    for (int i = 0; j < slen; ++i) {
      if (buffer[j] < '0' || buffer[j] > '9' && buffer[j] != '-')
        return 0;
      double n = atof(buffer.c_str());
      if (n < -999 || n > 999)
        return 0;
      return 1;
    }
  }

private:
  int feet_;
  float inches_;
}