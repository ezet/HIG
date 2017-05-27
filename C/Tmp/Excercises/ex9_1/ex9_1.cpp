#include <iostream>
using namespace std;

const int kArraySize = 50;

class Publication {
public:
  void set_title(char title[]) { strcpy_s(title_, title); }
  char title() { return title_[kArraySize]; }
  void set_price(float price) { price_ = price; }
  float price() { return price_; }

protected:
  void SetData() {
    cout << "Enter title: ";
    cin >> title_;
    cout << "Enter price: ";
    cin >> price_;
  }
  void PrintData() {
    cout << "Title: " << title_
      << "\nPrice: " << price_ << '\n';
  }

private:
  char title_[kArraySize];
  float price_;
};

class Book : private Publication {
public:
  void set_page_count(int page_count) { page_count_ = page_count; }
  int page_count() { return page_count_; }
  void SetData() {
    Publication::SetData();
    cout << "Enter page count: ";
    cin >> page_count_;
  }
  void PrintData() {
    Publication::PrintData();
    cout << "Page count: " << page_count_ << '\n';
  }

private:
  int page_count_;
};

class Tape : private Publication {
public:
  void set_playtime(float length) { length_ = length; }
  float length() { return length_; }
  void SetData() {
    Publication::SetData();
    cout << "Enter length: ";
    cin >> length_;
  }
  void PrintData() {
    Publication::PrintData();
    cout << "Length: " << length_ << '\n';
  }

private:
  float length_;
};

int main() {
  Book b1, b2;
  Tape t1, t2;

  b1.SetData();
  b2.SetData();
  t1.SetData();
  t2.SetData();

  b1.PrintData();
  b2.PrintData();
  t1.PrintData();
  t2.PrintData();

  return 0;
}