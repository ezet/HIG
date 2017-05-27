#include <iostream>
#include <string>
using namespace std;

class Publication {
public:
  void set_title(string title) { title_ = title; }
  string title() { return title_; }
  void set_price(float price) { price_ = price; }
  float price() { return price_; }
  virtual void SetData() = 0 {
    cout << "Enter title: "; cin >> title_;
    cout << "Enter price: "; cin >> price_;
  }
  virtual void PrintData() = 0 {
    cout << "\nTitle: " << title_
         << "\nPrice: " << price_;
  }

private:
  string title_;
  float price_;
};

class Book : public Publication {
public:
  void set_pagecount(int pagecount) { pagecount_ = pagecount; }
  int pagecount() { return pagecount_; }
  void SetData() {
    Publication::SetData();
    cout << "Enter pagecount: "; cin >> pagecount_;
  }
  virtual void PrintData() {
    Publication::PrintData();
    cout << "\nPagecount: " << pagecount_;
  }

private:
  int pagecount_;
};

class Tape : public Publication {
public:
  void set_playtime(float playtime) { playtime_ = playtime; }
  float playtime() { return playtime_; }
  void SetData() {
    Publication::SetData();
    cout << "Enter playtime: "; cin >> playtime_;
  }
  virtual void PrintData() {
    Publication::PrintData();
    cout << "\nPlaytime: " << playtime_;
  }

private:
  float playtime_;
};

int main() {
  const int kSize = 100;
  Publication *publications[kSize];
  char input = 'y';
  int pub_count = 0;

  for (int i = 0; i < kSize && input == 'y'; ++i) {
    cout << "Book or tape (b/t)? "; cin >> input;
    if (input == 'b') *(publications+i) = new Book;
    if (input == 't') *(publications+i) = new Tape;
    (*(publications+i))->SetData();
    ++pub_count;
    cout << "Enter another (y/n)? "; cin >> input;
  }

  for (int i = 0; i < pub_count; ++i)
    (*(publications+i))->PrintData();

  return 0;
}








