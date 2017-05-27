#include <iostream>
using namespace std;

int main() {
	float pound = 1.487, franc = 0.172, mark = 0.584, yen = 0.00955, dollar;
	cout << "Input amount in dollars: " << endl;
	cin >> dollar;
	cout << dollar << " US dollars equals " << dollar * pound << " British pounds, " << dollar * franc << " French franc, " << dollar * mark << " German mark and " << dollar * yen << " Japanese yen." << endl;
	return 0;
}

