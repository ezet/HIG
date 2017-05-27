#include <iostream>
using namespace std;

struct Date {
	int d;
	int m;
	int y;
};

int main() {
	Date date1;
	char dummy;

	cout << "Enter date (xx/xx/xxx): ";
	cin >> date1.d  >> dummy >> date1.m >> dummy >> date1.y;
	cout << "The date you entered was: " << date1.d << '/' << date1.m << '/' << date1.y << endl;
	return 0;
}