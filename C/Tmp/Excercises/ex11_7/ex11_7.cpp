#include <iostream>
using namespace std;

class Token {
public:
  virtual ~Token() = 0 {};
  virtual double GetNumber() = 0;
  virtual char GetOperator() = 0;   
};

class Operator : public Token {
public:
  explicit Operator(char oper) : operator_(oper) {};
  virtual ~Operator() { delete this; }
  virtual char GetOperator() { return operator_; }
  virtual double GetNumber() { return 0; }

private:
  char operator_;
};

class Number : public Token {
public:
  explicit Number(double number) : number_(number) {};
  virtual ~Number() { delete this; }
  virtual double GetNumber() { return number_; }
  virtual char GetOperator() { return 0; }

private:
  double number_;
};

class Stack {
public:
  Stack() : index_(0), kSize(100) {};
  
  void push(char& input) {
    if (index_ < kSize)
      *(token+index_++) = new Operator(input);
  }

  void push(double& input) {
    if (index_ < kSize)
      *(token+index_++) = new Number(input);
  }

  double pop() {
    if (index_ > 0)
      return (*(token+--index_))->GetNumber();
    return -1;
  }

private:
  const int kSize;
  Token* token[100];
  int index_;
};

int main() {
  Stack parser;
  char input = 'y';
  double dinput;

  cout << "Enter a number: "; cin >> dinput;
  parser.push(dinput);
  do {
    cout << "Enter an operator: "; cin >> input;
    parser.push(input);
    cout << "Enter a number: "; cin >> dinput;
    parser.push(dinput);
    cout << "Add more (y/n)? "; cin >> input;
  } while (input == 'y');

  for (int i = 0; i < 10; ++i) {
    cout << parser.pop();
  }
  
  return 0;
}