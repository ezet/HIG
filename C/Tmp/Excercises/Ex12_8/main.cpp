#include <iostream>
#include <fstream>
using namespace std;

struct Node {
  explicit Node(int n) : data(n), next(NULL) {};
  Node *next;
  int data;
};

class LinkedList {
public:
  LinkedList() : head_(NULL) {}
  explicit LinkedList(int n) {
    head_ = new Node(n);
  }

  ~LinkedList() {
    while (head_ != NULL) {
      Node *temp = head_;
      head_ = head_->next;
      delete temp;      
    }
  }

  void AddNodeEnd(int n) {
    Node *temp = new Node(n);
    if (head_ == NULL) {
      head_ = temp;
    } else {
      Node *current = head_;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = temp;
    }
  }

  void AddNodeBeg(int n) {
    Node *temp = new Node(n);
    temp->next = head_;
    head_ = temp;
  }

  void PrintList() {
    Node *current = head_;
    while (current != NULL) {
      cout << '\n' << current->data;
      current = current->next;
    }
    cout << '\n' << "End of list\n";
  }

  void DeleteNode(int n) {
    Node *current = head_;
    Node *temp;
    for (int i = 0; i < n; ++i) {
      if (current == NULL) {
        cout << "Node " << n << " does not exist, aborting.";
        return;
      }
      if (i == n-1) temp = current;
      current = current->next;
    }
    temp->next = current->next;
    delete current;
  }

  void WriteFile(char *filename = "list.dat") {
    ofstream ofile;
    ofile.open(filename);
    if (ofile.fail()) {
      cerr << "Error opening " << filename << endl;
      return;
    }
    Node *current = head_;
    while (current != NULL) {
      ofile << current->data << ' ';
      current = current->next;
    }
    ofile.close();
  }

  void ReadFile(char *filename = "list.dat") {
    ifstream ifile;
    ifile.open(filename);
    if (ifile.fail()) {
      cerr << "Error opening " << filename << endl;
      return;
    }
    int buffer;
    ifile >> buffer;
    while (ifile.good()) {
      AddNodeEnd(buffer);
      ifile >> buffer;
    }
    ifile.close();
  }

private:
  Node *head_;
};

int main(int argc, char *argv[]) {
  char command, filename[256];
  int buffer;
  LinkedList list;

  while (true) {
    cout << "\n\nULTIMATE LINKED LIST APPLICATION!\n";
    cout << "\n(A)dd node" << "\n(P)rint node data" << "\n(W)rite data to disk"
      << "\n(R)ead data from disk" << "\n(D)elete a specific node"
      << "\n(Q)uit\n";
    cout << "Select an option: ";
    cin >> command;
    tolower(command);
    switch(command) {
    case 'a':
      cout << "Enter integer to store: ";
      cin >> buffer;
      list.AddNodeEnd(buffer);
      break;
    case 'p':
      list.PrintList();
      break;
    case 'w':
      cout << "Enter filename (default: list.dat): ";
      cin >> filename;
      list.WriteFile(filename);
      break;
    case 'r':
      cout << "Enter filename (default: list.dat): ";
      cin >> filename;
      list.ReadFile(filename);
      break;
    case 'd':
      cout << "Enter node to delete: ";
      cin >> buffer;
      list.DeleteNode(buffer);
      break;
    case 'q':
      cout << "Have a nice day!\n";
      exit(0);
      break;
    default:
      cout << "Unknown command\n";
    } // endswitch
  } // endwhile

  return 0;
}