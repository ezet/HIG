#include <iostream>
using namespace std;

int main() {
	char var1;
	int var2;
	cout << "Type an upper- or lowercase letter: ";
	cin >> var1;
	var2 = islower(var1);
	cout << var2 << endl;
	return 0;
}
