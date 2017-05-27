#include <iostream>
using namespace std;

struct Fraction {
	int num, denom;
};

Fraction fadd(Fraction, Fraction);
Fraction fsub(Fraction, Fraction);
Fraction fmul(Fraction, Fraction);
Fraction fdiv(Fraction, Fraction);

int main() {
	Fraction f1, f2, res;
	char d, op;

	cout << "Enter first fraction: "; cin >> f1.num >> d >> f1.denom;
	cout << "Enter operator: "; cin >> op;
	cout << "Enter second fraction: "; cin >> f2.num >> d >> f2.denom;
	
	switch(op) {
	case '+': res = fadd(f1, f2); break;
	case '-': res = fsub(f1, f2); break;
	case '*': res = fmul(f1, f2); break;
	case '/': res = fdiv(f1, f2); break;
	default: cout << "Operator not recognized.\n";
	}

	cout << "The result is: " << res.num << '/' << res.denom << endl;
	return 0;
}

Fraction fadd(Fraction f1, Fraction f2) {
	Fraction res;
	res.num = f1.num * f2.denom + f1.denom * f2.num;
	res.denom = f1.denom * f2.denom;
	return res;
}

Fraction fsub(Fraction f1, Fraction f2) {
	Fraction res;
	res.num = f1.num * f2.denom - f1.denom * f2.num;
	res.denom = f1.denom * f2.denom;
	return res;
}

Fraction fmul(Fraction f1, Fraction f2) {
	Fraction res;
	res.num = f1.num * f2.num;
	res.denom = f1.denom * f2.denom;
	return res;
}

Fraction fdiv(Fraction f1, Fraction f2) {
	Fraction res;
	res.num = f1.num * f2.denom;
	res.denom = f1.denom * f2.num;
	return res;
}