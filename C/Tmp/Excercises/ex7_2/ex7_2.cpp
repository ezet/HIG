#include <iostream>
#include <string>
using namespace std;

class employee {
private:
	string name;
	int empnumber;
public:
	void getData() {
		cout << "Enter name: "; cin >> name;
		cout << "Enter employee number: "; cin >> empnumber;
	}

	void printData() {
		cout << "Name: " << name
			<< "\nEmployee number: " << empnumber << endl;
	}
};

int main() {
	const int MAX = 100;
	employee emp[MAX];
	int i = 0;

	for( char run = 'y'; run == 'y' && i < 100; i++ ) {
		emp[i].getData();
		cout << "Enter another (y/n)? "; cin >> run;
	}

	for( int j = 0; j <= i; j++ )
		emp[j].printData();

	return 0;
}

	

