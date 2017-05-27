#include <iostream>
using namespace std;

class Time {
private:
  int hour, min, sec;
public:
	Time() : hour(00), min(00), sec(00) { };
	Time(int hh, int mm, int ss) : hour(hh), min(mm), sec(ss) { };
	
  void PrintTime() const;
  void add(Time time1, Time time2);
  
  Time operator+(Time time2);
  Time operator-(Time time2);
  
  Time operator++() { ++sec; return Time(*this); }
  Time operator++(int) { sec++; return Time(*this); }
  Time operator--() { --sec; return Time(*this); }
  Time operator--(int) { sec--; return Time(*this); }
};

void Time::PrintTime() const {
  cout << ((hour < 10) ? "0" : "") << hour << ':'
  << ((min < 10) ? "0" : "")<< min << ':'
  << ((sec < 10) ? "0" : "")<< sec;
}

void Time::add(Time time1, Time time2) {
	sec = (time1.hour + time2.hour) * 3600 + (time1.min + time2.min) * 60 + time1.sec + time2.sec;
	hour = sec / 3600;
	min = (sec - hour * 3600) / 60;
	sec -= (hour*3600 + min * 60);
  sec %= 60;
}

Time Time::operator+(Time time2) {
  int h = hour + time2.hour;
  int m = min + time2.min;
  int s = sec + time2.sec;
  if (s > 59) {
    s -= 60;
    ++m;
  }
  if (m > 59) {
    m -= 60;
    ++h;
  }
  return Time(h, m, s);
}

Time Time::operator-(Time time2) {
  int s = (hour - time2.hour) * 3600 + (min - time2.min) * 60 + sec - time2.sec;
  s = s < 0 ? -s : s;
  int h = s / 3600;
  int m = (s - h * 3600) / 60;
  s %= 60;
  return Time(h, m, s);
}

int main() {
  Time t1(12, 12, 12);
	Time t2(12, 50, 50);
	Time t3;

	t3.add(t1, t2);
	t3.PrintTime(); cout << '\n';
  t3 = t1 + t2;
  t3.PrintTime(); cout << '\n';
  ++t3;
  t3.PrintTime(); cout << '\n';
  t3 = t1 - t3;
  t3.PrintTime(); cout << '\n';
	return 0;
}