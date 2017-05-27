#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	char numb=1;
	unsigned long fact;	
	
	while (numb != '0') {
		fact = 1;
		cout << "Enter a number: ";
		numb = getche();
		for(int j = numb - '0'; j>0; j--)
			fact *=j;
		cout << "\nFactorial is " << fact << endl << endl;
	}
	return 0;
}
