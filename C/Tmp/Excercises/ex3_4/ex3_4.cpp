#include <iostream>
using namespace std;

int main() {
	float num1, num2;
	char op, run;


	do {
		cout << "Enter first number, operator, second number: " << endl;
		cin >> num1 >> op >> num2;
		cout << "Answer: ";
		switch(op) {
			case '+': cout << num1 + num2 << endl; break;
			case '-': cout << num1 - num2 << endl; break;
			case '*': cout << num1 * num2 << endl; break;
			case '/': cout << num1 / num2 << endl; break;
			default: cout << "Unrecognized operator" << endl;
		}
		cout << "Do another (y/n)?" << endl;
		cin >> run;		 
	}
	while (run == 'y');
	return 0;
}
