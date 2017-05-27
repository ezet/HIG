#include <iostream>
using namespace std;

int main() {
	struct coords {
		int x;
		int y;
	};
	coords p1, p2;

	cout << "Enter coordinates for p1 :";
	cin >> p1.x >> p1.y;
	cout << "Enter coordinates for p2 :";
	cin >> p2.x >> p2.y;
	cout << "Coordinates for p1+p2 are: " << p1.x + p2.x << ", " << p1.y + p2.y << endl;
	return 0;
}