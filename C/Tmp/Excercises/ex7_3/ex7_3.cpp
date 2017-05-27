#include <iostream>
using namespace std;

class Distance {
private:
	int feet;
	double inches;
public:
	Distance() : feet(0), inches(0) { };
	void getDist() {
		cout << "Enter feet: "; cin >> feet;
		do {
			cout << "Enter inches (0 - 11): "; cin >> inches;
		} while( inches > 11 );
	}

	void printDist() {
		cout << feet << "'-" << inches << '"';
	}

	void add_dist( Distance d1, Distance d2 ) {
		feet = d1.feet + d2.feet;
		inches = d1.inches + d2.inches;
		for( inches; inches > 11; feet++ )
			inches -= 12;
	}

	void div_dist ( Distance d1, int div ) {
		double fltfeet = d1.feet + d1.inches / 12.0;
		fltfeet /= div;
		feet = int(fltfeet);
		inches = (fltfeet - feet) * 12.0;
	}
};

int main() {
	const int MAX = 100;
	Distance dist[MAX];
	Distance total, average;
	int i = 0;

	for( char run = 'y'; run == 'y' && i < 100; i++ ) {
		dist[i].getDist();
		total.add_dist(total, dist[i]);
		cout << "Enter another (y/n)? "; cin >> run;
	}
	average.div_dist(total, i);
	cout << "Average is: "; average.printDist(); cout << endl;
	return 0;
}