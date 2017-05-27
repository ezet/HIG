#include <iostream>
using namespace std;

class Customer {
public:
  Customer(int n) : count_(n) {
    accounts_ = new float[n];
  }
  ~Customer() {
    delete[] accounts_;
  }

void SetStanding(float standing, int index) {
    *(accounts_+index) = standing;
  }

  void PrintAccounts() {
    for (int i = 0; i < count_; ++i) {
      cout << "Account number: " << i << "\nStanding: " << *(accounts_+i) << "\n\n";
    }
  }

private:
  float *accounts_;   //array of accounts
  int count_;         // keeps track of size of array
};

int main(int argc, char *argv[]) {
  const int kMax = 1;
  Customer **customers = new Customer*[kMax];
  int max = kMax, index = 0;
  char cmd;
  do {
    if (index == max) {                   // expands array if necessary
      cout << "Expanding array" << endl;
      Customer **newcustomers = new Customer*[max*2];
      for (int i = 0; i <= index; ++i)
        *(newcustomers+i) = *(customers+i);
      delete[] customers;
      customers = newcustomers;
      max = max*2;
    }
    int numaccounts;
    cout << "How many accounts? ";
    cin >> numaccounts;
    *(customers+index) = new Customer(numaccounts); // instantiates customer
    float standing;
    for (int i = 0; i < numaccounts; ++i) {
      cout << "Enter amount on account number " << i << ": ";
      cin >> standing;
      (*(customers+index))->SetStanding(standing, i);
    }
    ++index;
    cout << "Add another (y/n)? ";
    cin >> cmd;
  } while ( tolower(cmd) != 'n');

  for (int i = 0; i < index; ++i) {
    cout << "Customer number: " << i << '\n';
    (*(customers+i))->PrintAccounts();
  }
  return 0;
}