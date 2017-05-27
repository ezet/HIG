#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
  void SetData() {
    cout << "\nEnter last name_: "; cin >> name_;
    cout << "Enter number_: "; cin >> number_;  
  }

  void PrintData() const {
  cout << "\nName: " << name_
    << "\nNumber: " << number_;
  }

private:
  string name_;
  unsigned int number_;
};

class Compensation {
public:
  enum Period { hourly = 1, weekly, monthly };
  void SetData() {
    int input;
    cout << "Enter compensation: "; cin >> compensation_;
    cout << "Enter period (1 = hourly, 2 = weekly, 3 = monthly): "; cin >> input;
    period_ = static_cast<Period>(input);
  }
  void PrintData() {
    cout << "Compensation: " << compensation_;
    string period = "Hourly.";
    switch (static_cast<int>(period_)) {
    case 2: period = "Weekly." ; break;
    case 3: period = "Monthly." ; break;
    }
    cout << "Period: " << period;
  }

private:
  double compensation_;
  Period period_;
};

class Manager : public Employee {
public:
  void SetData() {
    Employee::SetData();
    cout << "Enter title: "; cin >> title_;
    cout << "Enter dues "; cin >> dues_;
    Compensation_.SetData();
  }

  void PrintData() {
    Employee::PrintData();
    cout << "Title: " << title_
      << "\nDues: " << dues_;
    Compensation_.PrintData();
  }

private:
  string title_;
  double dues_;
  Compensation Compensation_;
 };

class Scientist : private Employee {
public:
  void SetData() {
    Employee::SetData();
    cout << "Enter number of publications: "; cin >> publications_;
    Compensation_.SetData();
  }

  void PrintData() {
    Employee::PrintData();
    cout << "Publications: " << publications_;
    Compensation_.PrintData();
  }

private:
  int publications_;
  Compensation Compensation_;
};

class Laborer : private Employee {
public:
  void SetData() {
    Employee::SetData();
    Compensation_.SetData();
  }

  void PrintData() {
  Employee::PrintData();
  Compensation_.SetData();}

private:
  Compensation Compensation_;

};

class Executive : public Manager {
public:
  void SetData() {
    Manager::SetData();
    cout << "Enter bonus: "; cin >> bonus_;
    cout << "Enter number of shares: "; cin >> shares_;
  }

  void PrintData() {
    Manager::PrintData();
    cout << "Bonus: " << bonus_
      << "\nShares: " << shares_;
  }

private:
  double bonus_;
  int shares_;
};

int main() {

  return 0;
}