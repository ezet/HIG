#include <iostream>
using namespace std;

struct Time {
	int h, m, s;
};

int main() {
	Time time1, time2, sum;
	int time1s, time2s, sums;
	char d;

	cout << "Enter the first time value (xx:xx:xx): ";
	cin >> time1.h >> d >> time1.m >> d >> time1.s;
	cout << "Enter the second time value (xx:xx:xx): ";
	cin >> time2.h >> d >> time2.m >> d >> time2.s;
	time1s = time1.h * 3600 + time1.m * 60 + time1.s;
	time2s = time2.h * 3600 + time2.m * 60 + time2.s;
	sums = time1s + time2s;
	sum.h = sums / 3600;
	sum.m = (sums - sum.h * 3600) / 60;
	sum.s = sums - sum.h * 3600 - sum.m * 60;
	cout << "The sum is: " << sum.h << ':' << sum.m << ':' << sum.s << endl;
	return 0;
}

