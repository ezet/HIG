#include <iostream>
using namespace std;

void fcount();

//int c;

int main() {


	for(int i=15; i>0; i--)
		fcount();
	return 0;
}

/*void fcount() {
	cout << "I have been called " << ++c << " times.\n";
}*/

void fcount() {
	static int c;
	cout << "I have been called " << ++c << " times.\n";
}

