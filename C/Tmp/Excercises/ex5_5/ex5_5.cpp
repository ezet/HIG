#include <iostream>
#include <conio.h>
using namespace std;

struct Time {
	int h, m, s;
};

Time settime();
int totalsec(Time);

int main() {
	Time t;

	do {
	t = settime();
	cout << "Total time in seconds is: " << totalsec(t) << endl;
	}
	while(_getch() != 's');
	return 0;
}

Time settime() {
	char d;
	Time t;
	cout << "Enter time value (xx:xx:xx): ";
	cin >> t.h >> d >> t.m >> d >> t.s;
	return t;
}

int totalsec(Time t) {
	return t.h * 3600 + t.m * 60 + t.s;
}