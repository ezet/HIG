#include <iostream>
using namespace std;

class angle {
private:
	int deg;
	float min;
	char dir;
public:
	angle(int d, float m, char di) : deg(d), min(m), dir(di) { };

	void getpos() {
		cout << "Enter degrees: ";
		cin >> deg;
		cout << "Enter minutes: ";
		cin >> min;
		cout << "Enter direction (N, S, E, W): ";
		cin >> dir;
	}

	void printpos() const {
		cout << deg << '\xF8' << min << '\' ' << dir;
	}
};

int main() {
	angle a1(170, 52.23, 'W');
	char run;
	
	cout << "Last entered position was ";
	a1.printpos();
	cout << '.\n\n';

	do {
	a1.getpos();
	cout << "Last entered position was ";
	a1.printpos();
	cout << '.\n';
	cout << "Continue? ";
	cin >> run;
	} while(run == 'y');
	return 0;
}


