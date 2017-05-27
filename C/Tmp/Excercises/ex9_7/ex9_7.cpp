#include <iostream>
using namespace std;

class Counter {
public:
  Counter() : count_() {}
  Counter(int c) : count_(c) {}
  unsigned int count() { return count_; }
  Counter operator++() { return Counter(++count_); }
protected:
  unsigned int count_;
};

class CountDown : public Counter {
public:
  CountDown() : Counter() {};
  CountDown(int c) : Counter(c) {};
  CountDown operator--() {
    return CountDown(--count_);
  }
};

  class CountPostfix : private CountDown {
    CountPostfix() : CountDown() {}
    CountPostfix(int c) : CountDown(c) {}
    CountPostfix operator++(int) {
      return CountPostfix(count_++);
    }
    CountPostfix operator--(int) {
      return CountPostfix(count_--);
    }
  };
