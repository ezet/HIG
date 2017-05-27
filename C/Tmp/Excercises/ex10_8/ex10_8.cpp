#include <iostream>
using namespace std;

struct Link {
  int data;
  Link* next;
};

class LinkedList {
public:
  LinkedList() { First_ = NULL; }

/*  void AddData(int data) {
    Link* newlink = new Link;
    newlink->data = data;
    newlink->next = First_;
    First_ = newlink;
  }*/

  void AddData(int data) {
    Link* temp = new Link;
    temp->data = data;
    temp->next = NULL;
    if (First_ == NULL)
      First_ = temp;
    else
      Current_->next = temp;
    Current_ = temp;
  }

  void PrintData() {
    Link* current = First_;
    while (current != NULL) {
      cout << current->data << '\n';
      current = current->next;
    }
  }
  void DeleteData() {
    Link* current = First_;
    if (current->next == NULL) {
      delete current;
      First_ = NULL;
    }
    else {
      while (current->next->next != NULL) {
      current = current->next;
      }
      delete current->next->next;
      current->next = NULL;
    }
  }

private:
  Link* First_;
  Link* Current_;
};

int main() {
  LinkedList test;
  test.AddData(10);
  test.AddData(20);
  test.AddData(30);
  test.AddData(40);
  test.DeleteData();

  test.PrintData();
  return 0;
}