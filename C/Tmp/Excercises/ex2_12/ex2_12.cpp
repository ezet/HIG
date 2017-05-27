#include <iostream>
using namespace std;

int main() {
	float decpounds, decfrac, decshillings;
	int pounds, pence, shillings;
	
	cout << "Enter decimal pounds: ";
	cin >> decpounds;
	
	pounds = static_cast<int>(decpounds);
	decfrac = decpounds - pounds;
	decshillings = decfrac * 20;
	
	shillings = static_cast<int>(decshillings);
	decfrac = decshillings - shillings;
	pence = decfrac * 12;
	
	cout << "Equivalent in old notion is: " << char(156) << pounds << "." << shillings << "." << pence << endl;
	return 0;
}