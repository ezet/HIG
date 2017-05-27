#include <iostream>
#include <iomanip>
using namespace std;

class employee {
private:
	int id;
	float comp;
public:
	void setdata() {
		cin >> id >> comp;
	}
	void printdata() const {
		cout << id << '\t' << comp << endl;
	}
};

int main() {
	employee e1, e2, e3;

	cout << "Enter data for employee 1 (id compensation): "; e1.setdata();
	cout << "Enter data for employee 2 (id compensation): "; e2.setdata();
	cout << "Enter data for employee 3 (id compensation): "; e3.setdata();

	cout << "ID   " << "Compensation" << endl;
	e1.printdata();
	e2.printdata();
	e3.printdata();
	return 0;
}