#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, ans1, ans2;
	char dummy, op, run;

	do {
		cout << "Enter first fraction: ";
		cin >> a >> dummy >> b;
		cout << "Enter operator: ";
		cin >> op;
		cout <<"Enter second fraction: ";
		cin >> c >> dummy >> d; 
		switch(op) {
		case '+':
			ans1 = (a*d + b*c);
			ans2 = b*d;
			break;
		case '-':
			ans1 = (a*d - b*c);
			ans2 = b*d;
			break;
		case '*':
			ans1 = a*c;
			ans2 = b*d;
			break;
		case '/':
			ans1 = a*d;
			ans2 = b*c;
			break;
		default: cout << "Operator not recognized!" << endl;
		}
		if (  % ans1 == 0 ) {
			ans1 /= ans1;
			ans2 /= ans1;
		}
		cout << "The answer = " << ans1 << '/' << ans2 << endl;
		cout << "Do you wish to continue (y/n)?" << endl;
		cin >> run;
	}
	while (run == 'y');
	return 0;
}

