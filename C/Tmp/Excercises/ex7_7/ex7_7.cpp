#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
using namespace std;

double mstold( char input[] ) {
	char output[40];
	int i = 0;
	for( int j = 0; j < int(strlen(input)); j++ )
		if( 48 <= input[j] && input[j] <= 57 ) {
			output[i] = input[j];
			i++;
		}
	double doubleMoney =  atof(output);
	return doubleMoney;
}


int main() {
	char money[40];
	char c;

	do {
	cout << setiosflags(ios::fixed) << setprecision(2) << "Enter a money value: ";
	cin.getline(money, 40);
	cout << mstold(money);
	} while( (c = _getch()) != 27 );


	return 0;
} // endmain