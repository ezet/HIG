#include <iostream>
using namespace std;

struct Link {
  int data;
  Link* next;
};

class LinkList {
public:
  LinkList() { first_ = NULL; }

  ~LinkList() {
    Link *current = first_;
    while (current != NULL) {
      Link *temp = current;
      current = current->next;
      delete temp;
    }
  }

private:
  Link* first_;
};

