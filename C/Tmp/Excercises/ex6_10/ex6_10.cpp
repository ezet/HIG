#include <iostream>
using namespace std;

class angle {
private:
	int deg;
	float min;
	char dir;
public:
	void getP() {
		cout << "Enter degrees: ";
		cin >> deg;
		cout << "Enter minutes: ";
		cin >> min;
		cout << "Enter direction (N, S, E, W): ";
		cin >> dir;
	}

	void printPos() const {
		cout << deg << '\xF8' << min << '\' ' << dir;
	}
};

class ship {
private:
	static int count;
	angle lon, lat;
	int shipNo;
public:
	ship() : shipNo(++count) { };
	
	void getPos() {
		cout << "Enter longitude values\n";
		lon.getP();
		cout << "Enter latitude valuesn\n";
		lat.getP();
	}

	void printPos() const {
		cout << "Ship number " << shipNo << " is located at ";
		lon.printPos();
		cout << ', ';
		lat.printPos();
		cout << '.';
	}
};

int ship::count = 0;

int main() {
	ship ship1, ship2, ship3;

	ship1.getPos();
	ship2.getPos();
	ship3.getPos();

	ship1.printPos();
	ship2.printPos();
	ship3.printPos();
	return 0;
}