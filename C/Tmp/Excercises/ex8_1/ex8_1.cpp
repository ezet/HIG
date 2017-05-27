#include <iostream>

class Distance {
private:
  int feet;
  float inches;
public:
  Distance() : feet(0), inches(0.0) {};
  Distance(int ft, float in) : feet(ft), inches(in) {};
  void GetDist() {
    std::cout << "\nEnter feet: "; std::cin >> feet;
    std::cout << "Enter inches: "; std::cin >> inches;
  }
  void PrintDist() {
    std::cout << feet << "\'-" << inches << '\"';
  }

    Distance operator - (Distance) const;
  };

Distance Distance::operator - (Distance d2) const {
  int f = feet - d2.feet;
  int i = inches - d2.inches;
  if (inches < 0) {
    i += 12;
    --f;
  }
  return Distance(f, i);

