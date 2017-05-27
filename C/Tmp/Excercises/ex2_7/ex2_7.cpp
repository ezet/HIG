#include <iostream>
using namespace std;

int main() {
	float celsius;
	cout << "Input temperature as Celsius: ";
	cin >> celsius;
	cout << celsius << " degrees Celsius equals " << celsius * (9/5) + 32  << " Fahrenheit." << endl;
	return 0;
}