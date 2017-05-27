#include <iostream>
using namespace std;

int main() {
	double years = 0;
	double r, iamount, famount;

	cout << "Enter initial amount: ";
	cin >> iamount;
	cout << "Enter final amount: ";
	cin >> famount;
	cout << "Enter interest rate (percent per year): ";
	cin >> r;
	while( iamount < famount ) {
		iamount += iamount*(r/100);
		years++;
	}
	cout << years << endl;
	for (iamount; iamount<famount; years++)
		iamount += iamount*(r/100);
	cout << years << endl;
	return 0;
}