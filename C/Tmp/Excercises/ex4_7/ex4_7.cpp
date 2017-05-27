#include <iostream>
using namespace std;

	struct Date {
		int day;
		int month;
		int year;
	};

	enum Etype {laborer, secretary, manager, accountant, executive, researcher};

	struct Info {
		int id;
		int comp;
	};

	struct Employee {
		Date date;
		Etype etype;
		Info info;
	};

int main() {
	Employee emp1, emp2, emp3;
	Etype empt1, empt2, empt3;
	int num;
	char dummy, type;

	cout << "Enter number of employees: ";
	cin >> num;
	for (int i = 1; i < num; i++) {
		cout << "EMPLOYEE NO: " << i << "Enter employee ID and compensation, seperated by space: ";
		switch(i) {
			case 1: cin >> emp1.info.id >> emp1.info.comp; break;
			case 2: cin >> emp2.info.id >> emp2.info.comp; break;
			case 3: cin >> emp3.info.id >> emp3.info.comp; break;
		}
		cout << "EMPLOYEE NO: " << i << "Enter employee type (first letter only\nlaborer, secretary, manager, accountant, executive, researcher: ";
		cin >> type;
		switch(i) {
		case 1: 
			switch(type) {
			case 'l': emp1.etype = laborer; break;
			case 's': emp1.etype = secretary; break;
			case 'm': emp1.etype = manager; break;
			case 'a': emp1.etype = accountant; break;
			case 'e': emp1.etype = executive; break;
			case 'r': emp1.etype = researcher; break;
			};
			break;
		case 2:
			switch(type) {
			case 'l': emp1.etype = laborer; break;
			case 's': emp1.etype = secretary; break;
			case 'm': emp1.etype = manager; break;
			case 'a': emp1.etype = accountant; break;
			case 'e': emp1.etype = executive; break;
			case 'r': emp1.etype = researcher; break;
			};
			break;
		case 3:
			switch(type) {
			case 'l': emp1.etype = laborer; break;
			case 's': emp1.etype = secretary; break;
			case 'm': emp1.etype = manager; break;
			case 'a': emp1.etype = accountant; break;
			case 'e': emp1.etype = executive; break;
			case 'r': emp1.etype = researcher; break;
			};
			break;
		};
		cout << "EMPLOYEE NO: " << i << "Enter the date of employment (xx/xx/xxxx): ";
		switch(i) {
			case 1: cin >> emp1.date.day >> dummy >> emp1.date.month >> dummy >> emp1.date.year; break;
			case 2: cin >> emp2.date.day >> dummy >> emp2.date.month >> dummy >> emp2.date.year; break;
			case 3: cin >> emp3.date.day >> dummy >> emp3.date.month >> dummy >> emp3.date.year; break;
		}
	}
	return 0;
}
	




