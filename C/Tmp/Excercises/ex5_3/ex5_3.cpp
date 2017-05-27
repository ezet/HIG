#include <iostream>
using namespace std;

void zeroSmaller(int&, int&);

int main() {
	int int1, int2;

	cout << "Enter first number: ";
	cin >> int1;
	cout << "Enter second number: ";
	cin >> int2;
	zeroSmaller(int1, int2);
	cout << int1 << endl << int2 << endl;
	return 0;
}

void zeroSmaller(int& i1, int& i2) {
	if(i1 < i2)
		i1 = 0;
	else
		i2 = 0;
}

	

