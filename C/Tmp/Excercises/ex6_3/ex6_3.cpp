#include <iostream>
using namespace std;

class time {
private:
	int h, m, s;
public:
	time() : h(00), m(00), s(00) { };
	time(int hh, int mm, int ss) : h(hh), m(mm), s(ss) { };
	void echo() const { cout << h << ':' << m << ':' << s; }
	void add(time time1, time time2) {
		s = (time1.h + time2.h) * 3600 + (time1.m + time2.m) * 60 + time1.s + time2.s;
		h = s / 3600;
		m = (s - h * 3600) / 60;
		s -= (h*3600 + m * 60);
	}
};

int main() {
	const time t1(12, 12, 12);
	const time t2(12, 50, 50);
	time t3;

	t3.add(t1, t2);
	t3.echo(); cout << endl;
	return 0;
}



