#include <iostream>
using namespace std;

struct Node {
  Node() : data(0), next(NULL) {};
  Node(int datain, Node* nextin) : data(datain), next(nextin) {}
  int data;
  Node* next;
};

class LinkList {
public:
  LinkList() : head_(NULL) {}
  
  LinkList(LinkList &linklist) : head_(NULL) {
    Node *current = linklist.head_;
    while (current != NULL) {
      Node* temp = new Node(current->data, head_);
      head_ = temp;
      current = current->next;
    }
  }

  ~LinkList() {
    Node *current = head_;
    while (current != NULL) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  };

  LinkList& operator=(LinkList &linklist) {
    head_ = NULL;
    Node *current = linklist.head_;
    while (current != NULL) {
      Node* temp = new Node(current->data, head_);
      head_ = temp;
      current = current->next;
    }
    return *this;
  }


  void PushFront(int data) {
    Node *temp = new Node(data, head_);
    head_ = temp;
  }

  void PrintNodes() {
    Node *current = head_;
    while (current != NULL) {
      cout << current->data << ' ';
      current = current->next;
    }
    cout << '\n';
  }

private:
  Node* head_;
};

int main() {
  LinkList *list1 = new LinkList;

  LinkList *list3 = new LinkList;


  
  for (int i = 0; i < 5; ++i)
    list1->PushFront(i);
  list1->PrintNodes();
  LinkList list2(*list1);
  delete list1;

  list2.PrintNodes();
  *list3 = list2;
  //delete &list2;
  list3->PrintNodes();

  return 0;
}

