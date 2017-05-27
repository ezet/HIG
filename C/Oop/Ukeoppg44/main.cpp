#include <iostream>
using namespace std;

class Customers {
public:
  static const int kMax = 40;
  Customers() : head_(NULL) {}

  void NewCustomer() {
    Node *current = new Node;
    SetData(*current);
    current->next = head_;
    head_ = current;
  }

  // Initialize with data, for testing
  void NewCustomer(char fname[], char lname[], char addr[], int pho) {
    Node *newnode = new Node;
    Node *current = head_;
    SetData(newnode, fname, lname, addr, pho);
    while (current != NULL && current->next != NULL && newnode->firstname < current->next->firstname)
        current = current->next;
    if (current == NULL)
      head_ = newnode;
    else if (current->next == NULL)
      current->next = newnode;
    else {
      newnode->next = current->next;
      current->next = newnode;
    }
  }

  void PrintList() {
    Node *current = head_;
    while (current != NULL) {
      cout << *current << '\n';
      current = current->next;
    }
  }

private:
  struct Node {
    Node() : next(NULL) {};
    char firstname[kMax], lastname[kMax], address[kMax];
    int phone;
    Node *next;
  };

  Node *head_;

  // overloaded << for Node
   friend ostream& operator<<(ostream& s, Node& node) {
    s << "\nFirstname: " << node.firstname
      << "\nLastname: " << node.lastname
      << "\nAddress: " << node.address
      << "\nPhone: " << node.phone;
    return s;
  }

   Node& operator<(Node& node) {
   //  return strcmp(node.lastname, this->lastname);
   }

  void SetData(Node &node) {
    cout << "Enter firstname: ";
    cin.getline(node.firstname, kMax);
    cout << "Enter lastname: ";
    cin.getline(node.lastname, kMax);
    cout << "Enter address: ";
    cin.getline(node.address, kMax);
    cout << "Enter phone number: ";
    cin >> node.phone;
    node.next = head_;
  }

  // initialize with data, for testing
   void SetData(Node *node, char fname[], char lname[], char addr[], int pho) {
     strcpy_s(node->firstname, fname);
     strcpy_s(node->lastname, lname);
     strcpy_s(node->address, addr);
     node->phone = pho;
    }

};

int main(int argc, char *argv[]) {
  Customers c;
  char cmd = 'y';
  for (int i = 0; i < 10; ++i)
    c.NewCustomer("lars", "kristian", "dahl", 53416267);
  /*do {
    c.NewCustomer();
    cout << "Add another (y/n)?";
    cin >> cmd;
  } while (tolower(cmd) != 'n');*/
  c.PrintList();
  return 0;
}