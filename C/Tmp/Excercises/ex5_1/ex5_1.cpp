#include <iostream>
using namespace std;

float circarea(float);
const float PI = 3.14159F;

int main() {
	const float PI = 3.14159F;
	float rad;
	
	cout << "Enter radius of circle: ";
	cin >> rad;
	cout << "The area of the circle is: " << circarea(rad) << endl;
	return 0;
}

float circarea(float rad1) {
	return rad1 * rad1 * PI;
}
