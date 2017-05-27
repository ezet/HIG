#include <iostream>
using namespace std;

struct Fraction {
	int num;
	int denom;
};

int main() {
	Fraction f1, f2, sum;
	char d;

	cout << "Enter first fraction: ";
	cin >> f1.num >> d >> f1.denom;
	cout << "Enter second fraction: ";
	cin >> f2.num >> d >> f2.denom;
	sum.num = f1.num * f2.denom + f1.denom * f2.num;
	sum.denom = f1.denom * f2.denom;
	cout << "Sum = " << sum.num << '/' << sum.denom << endl;
	return 0;
}