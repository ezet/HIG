#include <iostream>
#include <string>
using namespace std;

class Person {
public:
  string name() { return name_; }
  void set_name(string name) { name_ = name; }
  float salary() {return salary_; }
  void set_salary(float salary) { salary_ = salary; }  

  void SetData() {
    cout << "Enter name: "; getline(cin, name_);
    cout << "Enter salary: "; cin >> salary_;
  }

  void PrintData() {
    cout << "Name: " << name_ << '\n'
         << "Salary: " << salary_;
  }

protected:

private:
  string name_;
  float salary_;

};

void InsertionSort(Person** person, int kSize) {  
  for (int i = 1, j; i < kSize; ++i) {
    Person* value = *(person+i);
    for (j = i; j > 0 && (*(person+(j-1)))->salary() < value->salary(); --j) {
      *(person+j) = *(person+(j-1)); 
    }
    *(person+j) = value;
  }
}

int main() {
  const int kSize = 10;
  Person* persons[kSize];

  for (int i = 0; i < kSize; ++i) {
    *(persons+i) = new Person;
    (*(persons+i))->set_name("Lars");
    (*(persons+i))->set_salary(200+static_cast<float>(i));
  }
  
  for (int i = 0; i < kSize; ++i) {
    (*(persons+i))->PrintData();
    cout << '\n';
  }

  InsertionSort(persons, kSize);

  for (int i = 0; i < kSize; ++i) {
    (*(persons+i))->PrintData();
    cout << '\n';
  }
  return 0;
}
