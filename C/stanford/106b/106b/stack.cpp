#include <iostream>
using namespace std;

template<typename T>
class Stack {
public:
  Stack() {
    head = NULL;
};
  ~Stack();

  void Push(T t) {
    Node *temp = new Node;
    temp->val = t;
    temp->next = head;
    head = temp;
  };

private:
  struct Node {
    T val;
    Node *next;
  };
  Node head;
};