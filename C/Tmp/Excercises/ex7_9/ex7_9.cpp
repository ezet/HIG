#include <iostream>
using namespace std;

class queue {
private:
	static const int MAX = 20;
	int head, tail;
	int qu[MAX];
public:
	queue() : head(0), tail(0) { };
	
	void put( int input ) {
		if( tail == MAX )
			tail = 0;
		qu[tail++] = input;
	}

	int get() {
		if( head == MAX )
			head = 0;
		return qu[head++];
	}
};

int main() {
	queue q1;

	q1.put(1);
	q1.put(2);
	q1.put(3);
	cout << q1.get() << endl;
	cout << q1.get() << endl;
	q1.put(4);
	q1.put(5);
	cout << q1.get() << endl;
	cout << q1.get() << endl;
	cout << q1.get() << endl;


	return 0;
} // endmain