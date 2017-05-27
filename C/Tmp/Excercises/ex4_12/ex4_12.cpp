#include <iostream>
using namespace std;

struct Fraction {
	int num, denom;
};

int main() {
	Fraction f1, f2, res;
	char d, op;

	cout << "Enter first fraction, operator, second fraction: ";
	cin >> f1.num >> d >> f1.denom >> op >> f2.num >> d >> f2.denom;
	switch(op) {
	case '+':
		res.num = f1.num * f2.denom + f1.denom * f2.num;
		res.denom = f1.denom * f2.denom;
		break;
	case '-':
		res.num = f1.num * f2.denom - f1.denom * f2.num;
		res.denom = f1.denom * f2.denom;
		break;
	case '*':
		res.num = f1.num * f2.num;
		res.denom = f1.denom * f2.denom;
		break;
	case '/':
		res.num = f1.num * f2.denom;
		res.denom = f1.denom * f2.num;
		break;
	default: cout << "Operator not recognized.\n";
	}

	cout << "The result is: " << res.num << '/' << res.denom << endl;
	return 0;
}