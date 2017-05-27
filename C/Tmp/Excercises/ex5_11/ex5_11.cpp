#include <iostream>
using namespace std;

struct Sterling {
	int pounds, shilling, pence;
};

Sterling setsterling();
Sterling sumsterling(Sterling, Sterling);
void printsterling(Sterling);
char d;

int main() {
	Sterling s1, s2, s3;
	
	cout << "Enter first sterling value(xx.xx.xx): "; s1 = setsterling();
	cout << "Enter second sterling value(xx.xx.xx): "; s2 = setsterling();
	s3 = sumsterling(s1, s2);
	cout << "The sum is "; printsterling(s3);
	return 0;
}

Sterling setsterling() {
	Sterling s;
	cin >> s.pounds >> d >> s.shilling >> d >> s.pence;
	return s;
}

Sterling sumsterling(Sterling s1, Sterling s2) {
	Sterling s;
	s.pounds = s1.pounds + s2.pounds;
	s.shilling = s1.shilling + s2.shilling;
	s.pence = s1.pence + s2.pence;
	while(s.pence > 12) {
		s.shilling++;
		s.pence -= 12;
	}
	while(s.shilling > 20) {
		s.pounds++;
		s.shilling -=20;
	}
	return s;
}

void printsterling(Sterling s) {
	cout << s.pounds << '.' << s.shilling << '.' << s.pence << endl;
}