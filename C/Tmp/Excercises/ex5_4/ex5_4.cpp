#include <iostream>
using namespace std;

struct Distance {
	int feet;
	int inches;
};

Distance sortd(Distance, Distance);
void printd(Distance);

int main() {
	Distance d1, d2, d3;

	cout << "Enter first distance: ";
	cin >> d1.feet >> d1.inches;
	cout << "Enter second distance: ";
	cin >> d2.feet >> d2.inches;

	d3 = sortd(d1, d2);
	printd(d3);
	return 0;
}

Distance sortd(Distance d1, Distance d2) {
	int dd1 = d1.feet * 12 + d1.inches;
	int dd2 = d2.feet * 12 + d2.inches;
	if(dd1>dd2) return d1;
	else return d2;
}

void printd(Distance d) {
	cout << "Distance is: " << d.feet << "\'-" << d.inches << "\"" << endl;
}