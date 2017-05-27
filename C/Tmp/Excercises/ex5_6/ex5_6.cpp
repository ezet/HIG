#include <iostream>
using namespace std;

struct Time {
	int h, m, s;
};

Time settime();
Time addtime(Time, Time);
int ttos(Time);
Time stot(int);


int main() {
	Time t1, t2, t3;
	int s;

	t1 = settime();
	t2 = settime();
	t3 = addtime(t1, t2);
	
	cout << "Total time in seconds is: " << ttos(t3) << endl;
	s = ttos(t3);
	t3 = stot(s);
	cout << "Total time is: " << t3.h << ':' << t3.m << ':' << t3.s << endl;
	return 0;
}

Time settime() {
	Time t;
	char d;
	cout << "Enter time value (xx:xx:xx): "; cin >> t.h >> d >> t.m >> d >> t.s;
	return t;
}

Time addtime(Time t1, Time t2) {
	Time t3;
	t3.s = (t1.h + t2.h) * 3600 + (t1.m + t2.m) * 60 + t1.s + t2.s;
	t3.h = t3.s / 3600;
	t3.m = (t3.s - t3.h * 3600) / 60;
	t3.s -= t3.h * 3600 - t3.m * 60;
	return t3;
}

int ttos(Time t) {
	return t.h * 3600 + t.m * 60 + t.s;
}

Time stot(int s) {
	Time t3;
	t3.h = s / 3600;
	t3.m = (s - t3.h * 3600) / 60;
	t3.s = s - t3.h * 3600 - t3.m * 60;
	return t3;
}