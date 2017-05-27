#include <iostream>
using namespace std;

struct Sterling {
	int pounds, shilling, pence;
};

int main() {
	Sterling sterling;
	double decpounds, decfrac;

	cout << "Enter pounds in decimal form: ";
	cin >> decpounds;
	sterling.pounds = static_cast<int>(decpounds);
	decfrac = decpounds - sterling.pounds;
	sterling.shilling = decfrac * 20;
	decfrac = decfrac * 20 - sterling.shilling;
	sterling.pence = decfrac * 12;

	cout << "Entered value is: " << sterling.pounds << '.' << sterling.shilling << '.' << sterling.pence << endl;
	return 0;
}