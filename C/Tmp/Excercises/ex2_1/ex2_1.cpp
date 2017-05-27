#include <iostream>
using namespace std;

int main() {
	const float x = 7.481;
	float gallons, feet;
	cout << "Input gallons: ";
	cin >> gallons;
	cout << gallons << " gallons equals " << gallons / x << " feet." << endl;
	return 0;
}