#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	char ch = 'a';
	long num = 0;
	
	cout << "Enter a number: " << endl;
	while((ch=getche()) != '\r' ) {		
	num = (num*10) + (ch-48);
	}
	cout << '\n' << num << endl;
	return 0;
}

