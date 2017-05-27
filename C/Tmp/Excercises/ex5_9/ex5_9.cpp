#include <iostream>
using namespace std;

struct Time {
	int h, m, s;
};

void swap(Time&, Time&);

int main() {
	char d;
	Time t1, t2, test;

	cout << "Enter first time value (xx:xx:xx): ";
	cin >> t1.h >> d >> t1.m >> d >> t1.s;
	cout << "Enter second time value (xx:xx:xx): ";
	cin >> t2.h >> d >> t2.m >> d >> t1.s;
	test = t1;
	swap(t1, t2);
	if(test.h == t2.h && test.m == t2.m && test.s == t2.s)
		cout << "Values successfully swapped!\n";
	else
		cout << "Swap failed.\n";
	return 0;
}

void swap(Time& t1, Time& t2) {
	Time temp = t1;
	t1 = t2;
	t2 = temp;
}