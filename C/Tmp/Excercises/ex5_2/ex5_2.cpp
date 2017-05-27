#include <iostream>
using namespace std;

double power(double n, int p=2);

int main() {
	int n;
	double p;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter power: ";
	cin >> p;
	cout << "The " << p << "th power of " << n << " is: " << power(n, p) << endl;
	return 0;
}

double power(double n1, int p2) {
	if(p2 > 0)
		return n1 * power(n1, p2-1);
	else
		return 1;
}