#include <iostream>
#include <fstream>
using namespace std;


template<class T>
class Fractal {
public:
  Fractal() : num_(0), denom_(0) {}
  Fractal(T n, T d) : num_(n), denom_(d) {};
  ~Fractal() {}

  class OutOfBounds {
  public:
    OutOfBounds(int n) : index_(n) {}
  private:
    index_;
  };

  template<class T>
  friend istream& operator>> (istream& is, Fractal<T>& frac) {
    char d;
    int isbad = 1;
    while (isbad) {
      isbad = 0;
      is >> frac.num_ >> d >> frac.denom_;
      if (frac.denom_ == 0) {
        cout << "Denominator cannot be 0";
        isbad = 1;
      }
      if (d != '/') {
        cout << "Unknown divider " << d << ", please use '/'.\n";
        isbad = 1;
      }
      if (!isdigit(frac.num_) || !isdigit(frac.denom_)) {
        cout << "Input error: Only numerical digits are allowed.";
        isbad = 1;
      }
      if (isbad) cout << "\tEnter fraction again: ";
    }    
    return is;
  }

  template<class T>
  friend ostream& operator<< (ostream& os, Fractal& frac) {
    return os << frac.num_ << '/' << frac.denom_;
  }

  template<class T>
  friend Fractal operator+ (Fractal& frac1, Fractal& frac2) {
    return Fractal(frac1.num_ * frac2.denom_ + frac1.denom_ * frac2.num_,
      frac1.denom_ * frac2.denom_).LowerTerms();
  }

  template<class T>
  friend Fractal operator- (Fractal& frac1, Fractal& frac2) {
    return Fractal(frac1.num_ * frac2.denom_ - frac1.denom_ * frac2.num_,
      frac1.denom_ * frac2.denom_).LowerTerms();
  }

  template<class T>
  friend Fractal operator* (Fractal& frac1, Fractal& frac2) {
    return Fractal(frac1.num_ * frac2.num_, frac1.denom_ * frac2.denom_).LowerTerms();
  }

  template<class T>
  friend Fractal operator/ (Fractal &frac1, Fractal& frac2) {
    return Fractal(frac1.num_ * frac2.denom_, frac1.denom_ * frac2.num_).LowerTerms();
  }

  Fractal& LowerTerms() {
    T tnum, tden, temp, gcd;
    tnum = labs(num_);
    tnum = labs(denom_);
    if (tden == 0) {
      cout << "Illegal Fractal: division by 0";
      exit(1);
    }
    else if (tnum == 0) {
      num_ = 0;
      denom_ = 1;
      return;
    }
    while (tnum != 0) {
      if (tnum < tden) {
        temp = tnum;
        tnum = tden;
        tden = temp;
      }
      tnum -= tden;
    }
    gcd = tden;
    num_ /= gcd;
    denom_ /= gcd;
    return *this;
  }

private:
  T num_, denom_;

};

int main(int argc, int *argv[]) {
  Fractal<int> frac1, frac2;
  char run, oper;

  do {
    cout << "Enter first fractal: ";
    cin >> frac1;
    cout << "Enter operator: ";
    cin >> oper;
    cout << "Enter second fractal: ";
    cin >> frac2;

    switch(oper) {
    case '+': cout << frac1 + frac2; break;
    case '-': cout << frac1 - frac2; break;
    case '*': cout << frac1 * frac2; break;
    case '/': cout << frac1 / frac2; break;
    default: cout << "No such operator.\n";
    }
    cout << "Enter another (y/n)? ";
    cin >> run;
  } while (run == 'y');

  return 0;
}