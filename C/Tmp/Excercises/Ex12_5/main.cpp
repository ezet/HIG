#include <iostream>
using namespace std;

class Time {
public:

  void SetTime() {
    hours_ = GetValidInput(0, 23, "Enter hours");
    min_ = GetValidInput(0, 59, "Enter minutes");
    sec_ = GetValidInput(0, 59, "Enter seconds");
  }

  void PrintTime() {
    cout << "Time: " << hours_ << ':' << min_ << ':' << sec_ << endl;
  }

private:
  int GetValidInput(int min, int max, char *text) {
    int input;
    do {
      if (!cin) {
        cin.clear();
        cin.ignore();
      }
      cout << text << " (" << min << " - " << max << "): ";
      cin >> noskipws >> input;
      cin.ignore();
    } while(input < min || input > max);
    return input;
  }

  int hours_, min_, sec_;
};

int main(int argc, char *argv[]) {
  Time time;
  char run;
  do {
    time.SetTime();
    time.PrintTime();
    cout << "Enter another (y/n)? ";
    cin >> run;
    cin.ignore();
  } while (run == 'y');

  return 0;
}