#include <iostream>
using namespace std;

class Full {};
class Empty{};

template<class T>
class Queue {
public:
  Queue() : head_(0), tail_(0) {}

  void Push(T data) {
    if (count_ == kMax) throw Full();
    data_[head_++] = data;
    if (head_ == kMax) head_ = 0;
    ++count_;
  }

  T Pop() {
    if (count_ == 0) throw Empty();
    if (tail_ == kMax) tail_ = 0;
    --count_;
    return data_[tail_++];
  }

private:
  static int count_;
  static const int kMax = 5;
  T data_[kMax];
  int head_, tail_;

};

template<class T>
int Queue<T>::count_ = 0;


int main(int argc, char *argv[]) {
  Queue<int> q;
  char command;

  while (true) {
    cout << "\n(P)ush or P(o)p ?";
    cin >> command;
    tolower(command);
    try {
      switch (command) {
      case 'p':
        int buffer;
        cout << "Enter integer to push: ";
        cin >> buffer;
        q.Push(buffer);
        break;
      case 'o':
        cout << q.Pop();
        break;
      default:
        cout << "Unknown command.\n";
      } // endswitch
    } // endtry
    catch(Full) {
      cout << "Stack is full, pop something first.";
    }
    catch(Empty) {
      cout << "Stack is empty, you need to push something first.";
    }
  } // endwhile

  return 0;
} // endmain