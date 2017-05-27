#include <iostream>
using namespace std;

class fraction {
private:
	int num, denom;
	static char op, d;
public:
	void calcFrac(fraction, fraction);
	void lowterms();
	void getFrac() { cout << "Enter fraction (x/x): "; cin >> num >> d >> denom; }
	void getOp() { cout << "Enter operator ( +, -, *, / ): "; cin >> op; }
	void printFrac() { cout << "The result is: " << num << '/' << denom << endl; }
	void fadd(fraction, fraction);
	void fsub(fraction, fraction);
	void fmul(fraction, fraction);
	void fdiv(fraction, fraction);
};

void fraction::calcFrac(fraction f1, fraction f2) {
	switch(op) {
	case '+': fadd(f1, f2); break;
	case '-': fsub(f1, f2); break;
	case '*': fmul(f1, f2); break;
	case '/': fdiv(f1, f2); break;
	default: cout << "Operator not recognized.\n";
	}
}

void fraction::fadd(fraction f1, fraction f2) {
	num = f1.num * f2.denom + f1.denom * f2.num;
	denom = f1.denom * f2.denom;
}

void fraction::fsub(fraction f1, fraction f2) {
	num = f1.num * f2.denom - f1.denom * f2.num;
	denom = f1.denom * f2.denom;
}

void fraction::fmul(fraction f1, fraction f2) {
	num = f1.num * f2.num;
	denom = f1.denom * f2.denom;
}

void fraction::fdiv(fraction f1, fraction f2) {
	num = f1.num * f2.denom;
	denom = f1.denom * f2.num;
}

void fraction::lowterms() {
	long tnum, tden, temp, gcd;

	tnum = labs(num);
	tden = labs(denom);
	if( tden == 0 ) {
		cout << "Illegal fraction: division by 0"; exit(1); }
	else if( tnum == 0 ) {
		num = 0; denom = 1; return; }

	while( tnum != 0 ) {
		if( tnum < tden ) {
			temp = tnum; tnum = tden; tden = temp; }
		tnum -= tden;
	}
	gcd = tden;
	num /= gcd;
	denom /= gcd;
}

char fraction::op;
char fraction::d;

int main() {
	fraction f1, f2, res;
	char run = 'y';

	do {
	f1.getFrac();
	f1.getOp();
	f2.getFrac();
	res.calcFrac(f1, f2);
	res.lowterms();
	res.printFrac();
	cout << "Run again (y/n)? "; cin >> run;
	} while( run == 'y');

	return 0;
}


