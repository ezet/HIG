#include <iostream>
using namespace std;

class Time {
public:                                                                        
  Time() : hour_(0), min_(0) {}
  Time(int h, int m) : hour_(h), min_(m) {}

  Time operator-=(int t);
  Time operator+=(int t); 
  Time operator+(Time t);
  Time operator-(Time t);
  bool operator==(Time t);
  bool operator<(Time t);
  friend ostream& operator<<(ostream& s, Time& t);

private:
  int hour_, min_;
};

int main(int argc, char *argv[]) {
  Time t1(13, 30), t2(16, 40), t3;
  cout << (t1 += 47) << '\n';
  cout << (t2 -= 16) << '\n';
  cout << (t3 = t1 + t2) << '\n';
  cout << (t3 = t1 - t2) << '\n';
  if (t1 == t2) cout << "t1 equals t2.\n";
  if (t1 < t2) cout << "t1 is less than t2.\n";
  
  return 0;
};

Time Time::operator+=(int t) {
  min_ += t;
  if (min_ > 59) {
    ++hour_;
    min_ -= 60;
  }
  return *this;
};

Time Time::operator-=(int t) {
  min_ -= t;
  if (min_ < 0) {
    --hour_;
    min_ += 60;
  }
  return *this;
};

Time Time::operator+(Time t) {
  Time tt(hour_ + t.hour_, min_ + t.min_);
  if (tt.min_ > 59) {
    ++tt.hour_;
    tt.min_ -= 60;
  }
  return tt;
};

Time Time::operator-(Time t) {
  Time tt(hour_ - t.hour_, min_ - t.min_);
  if (tt.min_ < 0) {
    --tt.hour_;
    tt.min_ += 60;
  }
  if (tt.hour_ < 0) tt.hour_ *= -1;
  return tt;
};

bool Time::operator==(Time t) {
  return !(hour_ - t.hour_ + min_ - t.min_);
}

bool Time::operator<(Time t) {
  if (hour_ * 60 + min_ < t.hour_ * 60 + t.min_) return true;
  return false;
};

ostream& operator<<(ostream& s, Time& t) {
  s << t.hour_<< ':' << t.min_;
  return s;
};