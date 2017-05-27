#include <iostream>
using namespace std;
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&);

class Distance {
public:
  explicit Distance() : feet_(0), inches_(0.0) {}
  explicit Distance(float distance) {
    feet_ = int(distance);
    inches_ = 12*(distance-feet_);
  }
  explicit Distance(int feet, float inches) : feet_(feet), inches_(inches) {}
 
  void PrintDist() const {
    cout << feet_ << "'-" << inches_ << '"';
  }
  friend Distance& operator*(const Distance &d1, Distance &d2) {
    float distance = (d2.feet_ + d2.inches_ / 12) * (d1.feet_ + d1.inches_ / 12);
    return static_cast<Distance>(distance);
  }

private:
  int feet_;
  float inches_;
  //DISALLOW_COPY_AND_ASSIGN(Distance);
};

int main() {
  Distance d1, d2;
  
  Distance d3 = static_cast<Distance>(7) * d2;

  d3.PrintDist();
  return 0;
}