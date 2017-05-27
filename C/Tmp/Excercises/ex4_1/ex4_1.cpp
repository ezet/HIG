#include <iostream>
using namespace std;

int main() {
	struct phone {
		int acode;
		int exc;
		int no;
	};
	phone no1 = {212, 767, 8900}, no2;

	cout << "Enter your area code, exchange, and number: ";
	cin >> no2.acode >> no2.exc >> no2.no;
	cout << "My number is: (" << no1.acode << ") " << no1.exc << '-' << no1.no << endl;
	cout << "Your number is: (" << no2.acode << ") " << no2.exc << '-' << no2.no << endl;

	return 0;
}


