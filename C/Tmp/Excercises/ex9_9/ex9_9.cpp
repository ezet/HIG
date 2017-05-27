#include <iostream>
using namespace std;

char dummy;

const int kArraySize = 50;

class Date {
public:
  void SetDate() {
    cout << "Enter date (dd.mm.yyyy): ";
    cin >> date_ >> dummy >> month_ >> dummy >> year_;
  }
  void PrintDate() const {
    cout << "Date: " << date_ << '.' << month_ << '.' << year_;
  }

private:
  int date_, month_, year_;
};

class Sales {
public:
  void set_month1(float month1) { month1_ = month1; }
  void set_month2(float month2) { month2_ = month2; }
  void set_month3(float month3) { month3_ = month3; }
  float month1() const { return month1_; }
  float month2() const { return month2_; }
  float month3() const { return month3_; }

  void SetData() {
    cout << "Enter sales for last month: "; cin >> month1_;
    cout << "Enter sales for second to last month: "; cin >> month2_;
    cout << "Enter sales for third to last month: "; cin >> month3_;
  }
  void PrintData() const {
    cout << "Sales for last month: " << month1_
      << "\nSales for second to last month: " << month2_
      << "\nSales for third to last month: " << month3_ << '\n';
  }

private:
  float month1_, month2_, month3_;
};

class Publication {
public:
  void set_title(char title[]) { strcpy_s(title_, title); }
  void set_price(float price) { price_ = price; }
  float price() const { return price_; }
  char title() const { return title_[kArraySize]; }  

protected:
  void SetData() {
    cout << "Enter title: ";
    cin >> title_;
    cout << "Enter price: ";
    cin >> price_;
    Date_.SetDate();
  }
  void PrintData() const {
    cout << "Title: " << title_
      << "\nPrice: " << price_ << '\n';
    Date_.PrintDate();
  }

private:
  char title_[kArraySize];
  float price_;
  Date Date_;
};

class Book : private Publication, private Sales {
public:
  void set_page_count(int page_count) { page_count_ = page_count; }
  int page_count() const { return page_count_; }
  
  void SetData() {
    Publication::SetData();
    Sales::SetData();
    cout << "Enter page count: ";
    cin >> page_count_;
  }
  void PrintData() const {
    Publication::PrintData();
    Sales::PrintData();
    cout << "Page count: " << page_count_ << '\n';
  }

private:
  int page_count_;
};

class Tape : private Publication, private Sales {
public:
  void set_playtime(float length) { length_ = length; }
  float length() const { return length_; }
  
  void SetData() {
    Publication::SetData();
    Sales::SetData();
    cout << "Enter length: ";
    cin >> length_;
  }
  void PrintData() const {
    Publication::PrintData();
    Sales::PrintData();
    cout << "Length: " << length_ << '\n';
  }

private:
  float length_;
};

class Disk : private Publication, private Sales {
public:
  enum DiskType { kCD = 1, kDVD };
  void set_disk_type(DiskType disk_type) {
    disk_type_ = disk_type;   
  }
  DiskType disk_type() { return disk_type_; }
  void SetData() {
    Publication::SetData();
    cout << "Enter disk type (1 = CD, 2 = DVD): ";
    int disk_type;
    cin >> disk_type;
    disk_type_ = static_cast<DiskType>(disk_type);
    Sales::SetData();
  }
  void PrintData() {
    Publication::PrintData();
    cout << "Disk type: " << (disk_type_ == 1) ? "CD\n" : "DVD\n";
    Sales::PrintData();
  }

private:
  DiskType disk_type_;
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