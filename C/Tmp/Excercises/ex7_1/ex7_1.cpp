#include <iostream>
#include <cstring>
using namespace std;

 void reverseit( char s[] ) {
	int len = strlen(s);
	char newstr[80];	
	for (int i = 0; i < len; i++)
		newstr[i] = s[len-i-1];
	newstr[len] = '\0';
	strcpy(s, newstr);
}

int main() {
	const int MAX = 80;
	char str[MAX];

	cout << "Enter a string: ";
	cin.get(str, MAX);
	reverseit(str);
	cout << "Reversed: " << str << endl;
	return 0;
}