#include <iostream>
#include <iomanip>
using namespace std;

struct Employee {
	int no;
	float comp;
};

int main() {
	Employee emp1, emp2, emp3;

	cout << "Fill in ID number and compensation, separated by space, for employee 1: ";
	cin >> emp1.no >> emp1.comp;
	cout << "Fill in ID number and compensation, separated by space, for employee 2: ";
	cin >> emp2.no >> emp2.comp;
	cout << "Fill in ID number and compensation, separated by space, for employee 3: ";
	cin >> emp3.no >> emp3.comp;

	cout << "ID   " << "Compensation" << endl;
	cout << emp1.no << setw(8) << emp1.comp << endl;
	cout << emp2.no << setw(8) << emp2.comp << endl;
	cout << emp3.no << setw(8) << emp3.comp << endl;
	return 0;
}