#include <iostream>
using namespace std;

int main() {
	float pound, shilling, pence;
	float dpound, dpence;
	float test = 0.8875;
	cout << "Enter pounds: ";
	cin >> pound;
	cout << "Enter shilling: ";
	cin >> shilling;
	cout << "Enter pence: ";
	cin >> pence;
	dpence = ((shilling) * 100 / 20) + (pence * 100) / (12*20);
	cout << "Decimal pounds: " << pound << "." << int(dpence) << endl;
	cout << int(test) << endl;
	return 0;
}