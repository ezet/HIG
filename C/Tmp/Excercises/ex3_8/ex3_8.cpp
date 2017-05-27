#include <iostream>
using namespace std;

int main() {
	float am1, am2, sp;
	int pound, shilling, pence;
	int pound1, pound2, shilling1, shilling2, pence1, pence2;
	char run = 'y', dummy;

	do {
		cout << "Enter first amount: ";
		cin >> pound1 >> dummy >> shilling1 >> dummy >> pence1;
		cout << "Enter second amount: ";
		cin >> pound2 >> dummy >> shilling2 >> dummy >> pence2;
		pound = pound1 + pound2;
		shilling = shilling1 + shilling2;
		pence = pence1 + pence2;
		while( pence >= 12 ) {
			pence -= 12;
			shilling++;
		}
		while( shilling >= 20 ) {
			shilling -= 20;
			pound++;
		}				
		cout << "Total is: " << pound << "." << shilling << "." << pence << endl;
		cout << "Do you wish to continue (y/n)? ";
		cin >> run;		
	}
	while (run == 'y');
	return 0;
}