#include <iostream>
using namespace std;
#include <iomanip>

int main() {
	unsigned long num;
	cout << "Write a number: " << endl;
	cin >> num;
	for (int i=1; i<=200; i++) {
		cout << setw(5) << 7*i << " ";
		
		if(i % 10 == 0)
			cout << "\n";
	}
	return 0;
}