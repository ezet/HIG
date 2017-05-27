#include <iostream>
using namespace std;

char dummy;

class Fraction {
public:
	int num, denom;
  char op, d;

public:
  Fraction(int n, int d) : num(n), denom(d) {};
	void calcFrac(Fraction, Fraction);
	void lowterms();
	void getFrac() { cout << "Enter Fraction (x/x): "; cin >> num >> d >> denom; }
	void getOp() { cout << "Enter operator ( +, -, *, / ): "; cin >> op; }
	void printFrac() { cout << "The result is: " << num << '/' << denom << endl; }
	Fraction fadd(Fraction, Fraction);
	void fsub(Fraction, Fraction);
	void fmul(Fraction, Fraction);
	void fdiv(Fraction, Fraction);
};

class Sterling {
public:
  void SetData() {
    cout << "Enter value(xx.xx.xx-x/x): ";
    cin >> pound_ >> dummy >> shilling_ >> dummy >> pence_ >> dummy >> Fraction_.num >> dummy >> Fraction_.denom;
  }
  void PrintData() {
    Fraction_.lowterms();
    cout << "Value: " << pound_ << '.' << shilling_ << '.' << pence_ << '-'; Fraction_.printFrac();
  }

  void AddSterling(Sterling s1, Sterling s2) {
    pound_ = s1.pound_ + s2.pound_;
    shilling_ = s1.shilling_ + s2.shilling_;
    pence_ = s1.pence_ + s2.pence_;
    Fraction_.fadd(s1.Fraction_, s2.Fraction_);
    if (Fraction_.num >= Fraction_.denom) { ++pence_; Fraction_.num -= Fraction_.denom; }
    if (pence_ > 8) { ++shilling_; pence_ -= 8; }
    if (shilling_ > 12 ) { ++pound_; shilling_ -= 12; }
  }

private:
  int pound_, shilling_, pence_;
  Fraction Fraction_;
};



void Fraction::calcFrac(Fraction f1, Fraction f2) {
	switch(op) {
	case '+': fadd(f1, f2); break;
	case '-': fsub(f1, f2); break;
	case '*': fmul(f1, f2); break;
	case '/': fdiv(f1, f2); break;
	default: cout << "Operator not recognized.\n";
	}
}

Fraction Fraction::fadd(Fraction f1, Fraction f2) {
	num = f1.num * f2.denom + f1.denom * f2.num;
	denom = f1.denom * f2.denom;
  return Fraction(num, denom);
}

void Fraction::fsub(Fraction f1, Fraction f2) {
	num = f1.num * f2.denom - f1.denom * f2.num;
	denom = f1.denom * f2.denom;
}

void Fraction::fmul(Fraction f1, Fraction f2) {
	num = f1.num * f2.num;
	denom = f1.denom * f2.denom;
}

void Fraction::fdiv(Fraction f1, Fraction f2) {
	num = f1.num * f2.denom;
	denom = f1.denom * f2.num;
}

void Fraction::lowterms() {
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

int main() {
  return 0;
}


