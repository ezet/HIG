#include <iostream>
using namespace std;

int maxInt(int inta[], int SIZE) {
	int indexLargest = 0;
	for( int i = 0; i < SIZE - 1; i++ ) {
		if (inta[i] > inta[indexLargest])
			indexLargest = i;
	}
	return indexLargest;
}

int main() {
	const int SIZE = 5;
	int intarray[SIZE];
	int indexLargest;

	for( int i = 0; i < SIZE; i++ ) {
		cout << "Enter an integer: "; cin >> intarray[i];
	}

	indexLargest = maxInt(intarray, SIZE);
	cout << "The largest int is " << intarray[indexLargest] <<
		".\nAnd the index no. is: " << indexLargest << endl;


	return 0;
}