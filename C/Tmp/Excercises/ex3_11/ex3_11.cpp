#include <iostream>
using namespace std;

int main() {
	int pounds1, pounds2, shilling1, shilling2, pence1, pence2;
	char d, op, run = 'y';
	double m;

	do {	// enable repeat
		cout << "Enter first value, operator, second value or multiplier: ";
		cin >> pounds1 >> d >> shilling1 >> d >> pence1 >> op;
		if (op == '*') // enable multiplier mode
			cin >> m;
		else			// else use normal mode
			cin >> pounds2 >> d >> shilling2 >> d >> pence2;
		switch(op) {
		case '+':
			pounds1 += pounds2;
			shilling1 += shilling2;
			pence1 += pence2;
			cout << pounds1 << shilling1 << pence1;
			while( pence1 >= 12 ) { pence1 -= 12; shilling1++; }
			while( shilling1 >= 20 ) { shilling1 -= 20; pounds1++; }
			break;
		case '-':
			pounds1 -= pounds2;
			shilling1 -= shilling2;
			pence1 -= pence2;
			for( pence1; pence1 < 0; pence1 += 12, shilling1-- );
			for( shilling1; shilling1 < 0; shilling1 += 20, pounds1-- );
			break;
		case '*':
			pounds1 *= m;
			shilling1 *= m;
			pence1 *= m;
			for( pence1; pence1 >= 12; pence1 -= 12, shilling1++ );
			for( shilling1; shilling1 >= 20; shilling1 -= 20, pounds1++ );
			break;
		default:
			cout << "No such operator!" << endl;
		}
		cout << "The answer is: " << pounds1 << "." << shilling1 << "." << pence1 << endl;
		cout << "Do you wish to continue (y/n)?: ";
		cin >> run;
	}
	while (run == 'y');
	return 0;
}


