#include <iostream>
using namespace std;

int main() {
	double amount, ans;
	int years;
	float i;
	

	cout << "Enter initial amount: ";
	cin >> amount;
	cout << "Enter number of years: ";
	cin >> years;
	cout << "Enter interest rate (percent per year): ";
	cin >> i;
	for(int j=0; j<years; j++) amount += + (amount * (i/100));
	cout << "At the end of " << years << " years, you will have " << amount << " dollars." << endl;
	return 0;
}
