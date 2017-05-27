#include <iostream>
using namespace std;

int main() {
	int guests, c = 1, chairs = 4;
	
	cout << "Insert number of guests: " << endl;
	cin >> guests;
	for( int j = guests; j >= 3; j-- ) c *= j;
	cout << "Number of possible combinations is: " << c << endl;
	return 0;
}
