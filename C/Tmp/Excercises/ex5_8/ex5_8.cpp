#include <iostream>
using namespace std;

void swap(int&, int&);

int main() {
	int n1, n2, test;

	cout << "Enter first number: ";
	cin >> n1;
	test = n1;
	cout << "Enter second number: ";
	cin >> n2;
	swap(n1, n2);
	if(test == n2)
		cout << "Values are sucessfully swapped.\n";
	else
		cout << "Swap failed.\n";
	return 0;
}

void swap(int& n1, int& n2) {
	int temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}