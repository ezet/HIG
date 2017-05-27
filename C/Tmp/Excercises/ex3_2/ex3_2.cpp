#include <iostream>
using namespace std;

int main() {
	int mode;
	float temp;
	cout << "Select mode:" << endl << "1 - Fahrenheit to Celsius" << endl << "2 - Celsius to Fahrenheit" << endl;
	cin >> mode;
	if (mode == (1 || 2) ) {
		cout << "Enter temperature value: ";
		cin >> temp;
	}
	switch(mode) {
	case 1:
		cout << temp << " Fahrenheit equals " << (temp - 32) * 5/9 << " Celsius." << endl;
		break;
	case 2:
		cout << temp << " Celsius equals " << temp * (9/5) + 32 << " Fahrenheit." << endl;
		break;
	default:
		cout << "No such mode!" << endl;
	}
	return 0;
}