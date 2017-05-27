#include <iostream>
using namespace std;

int main() {
	float a, b, c, d, sum, sumtop, sumbot;
	char dummy;
	cout << "Enter first fraction: ";
	cin >> a >> dummy >> b;
	cout << "Enter second fraction: ";
	cin >> c >> dummy >> d;
	//sum = (a*d+b*c) / (b*d);
	//cout << "Sum /= " << sum << endl;
	sumtop = a*d+b*c;
	sumbot = b*d;
	cout << "Sum = " << sumtop << " / " << sumbot << endl;
	return 0;
}
