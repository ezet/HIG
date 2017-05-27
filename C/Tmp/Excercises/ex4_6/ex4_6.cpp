#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main() {
	etype emp;
	char input;

	cout << "Enter employee type (first letter only, laborer, secretary, manager, accountant, executive, researcher): ";
	cin >> input;
	switch(input) {
	case 'l': emp = laborer; break;
	case 's': emp = secretary; break;
	case 'm': emp = manager; break;
	case 'a': emp = accountant; break;
	case 'e': emp = executive; break;
	case 'r': emp = researcher; break;
	default: cout << "No such employee type\n"; exit(0);
	};

	switch(emp) {
	case 0: cout << "Employee type is laborer." << endl; break;
	case 1: cout << "Employee type is secretary." << endl; break;
	case 2: cout << "Employee type is manager." << endl; break;
	case 3: cout << "Employee type is accountant." << endl; break;
	case 4: cout << "Employee type is executive." << endl; break;
	case 5: cout << "Employee type is researcher." << endl; break;
	};

	return 0;
}


