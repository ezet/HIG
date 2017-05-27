#include <iostream>
using namespace std;

double power(char);
double power(int);
double power(double);
double power(float);

int p;

int main() {
	int n;
	char c;
	double d, a;
	float f;

	cout << "Enter a CHAR value: ";
	cin >> c;
	cout << "Enter power: ";
	cin >> p;
	a = power(c);
	cout << "The result is: " << a << endl;

	cout << "Enter an INT value: ";
	cin >> n;
	cout << "Enter power: ";
	cin >> p;
	a = power(n);
	cout << "The result is: " << a << endl;

	cout << "Enter a DOUBLE value: ";
	cin >> d;
	cout << "Enter power: ";
	cin >> p;
	a = power(d);
	cout << "The result is: " << a << endl;

	cout << "Enter a FLOAT value: ";
	cin >> f;
	cout << "Enter power: ";
	cin >> p;
	a = power(f);
	cout << "The result is: " << a << endl;
	return 0;
}

double power(char c) {
	if(p>0) {
		p--;
		return c * power(c);
	}
	else
		return 1;
}

double power(int n) {
	if(p>0) {
		p--;
		return n * power(n);
	}
	else
		return 1;
}

double power(double d) {
	if(p>0) {
		p--;
		return d * power(d);
	}
	else
		return 1;
}

double power(float f) {
	if(p>0) {
		p--;
		return f * power(f);
	}
	else
		return 1;
}

