#include <iostream>
#include <iomanip>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

class date {
private:
	int d, m, y;
	char dum;
public:
	void getdate() {
		cin >> d >> dum >> m >> dum >> y;
	}
	void printdate() const {
		cout << d << '/' << m << '/' << y;
	}
};

class employee {
private:
	date date;
	etype etype;
	int id;
	double sal;
public:
	void getetype() {
		char c;
		cin >> c;
		switch(c) {
		case 'l': etype = laborer; break;
		case 's': etype = secretary; break;
		case 'm': etype = manager; break;
		case 'a': etype = accountant; break;
		case 'e': etype = executive; break;
		case 'r': etype = researcher; break;
		}
	}
	void getemploy() {
		cout << "Enter ID: "; cin >> id;
		cout << "Enter salary: "; cin >> sal;
		cout << "Enter employee type (first letter only; laborer, secretary, manager, accountant, executive, researcher): "; getetype();
		cout << "Enter date of hire (dd/mm/yyyy): "; date.getdate();
	}
	void printemploy() const {
		cout << setw(3) << id << setw(10) << sal << setw(9) << etype << setw(13); date.printdate(); cout << endl;
	}
};

int main() {
	employee emp1, emp2, emp3;

	cout << "Enter information for Employee 1\n"; emp1.getemploy();
	cout << "Enter information for Employee 2\n"; emp2.getemploy();
	cout << "Enter information for Employee 3\n"; emp3.getemploy();

	cout << "ID\tSalary\tEmp. type\tDate of hire\n";
	emp1.printemploy();
	emp2.printemploy();
	emp3.printemploy();
	return 0;
}