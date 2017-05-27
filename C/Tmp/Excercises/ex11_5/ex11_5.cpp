#include <iostream>
#include <string>
using namespace std;

class Money {
public:
  void SetData() {
    char input[20];
    cout << "Enter an amount: "; cin >> input;
    mstold(input);
  };
  void PrintData() {
    cout << ldtoms(money_);
  };

private:
  double mstold( char input[] ) {
	char output[40];
	for( int i = 0, j = 0; i < int(strlen(input)); ++i )
		if( 48 <= input[i] && input[i] <= 57 ) {
			output[j++] = input[i];
		}
    money_ = atof(output);
  }

  char ldtoms(long mlong) {
	char mstring[40];
	int i = 0;
	mstring[i] = mlong;
  }

  double money_;
};

int main() {

  return 0;
}