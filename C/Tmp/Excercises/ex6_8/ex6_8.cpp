#include <iostream>
using namespace std;

class serial {
private:
	const int serNo;
	static int count;
public:
	serial() : serNo(++count) { };
	
	void printSer() {
		cout << "I am object number " << serNo << endl;
	}
};

int serial::count = 0;

int main() {
	serial s1, s2, s3;

	s1.printSer();
	s2.printSer();
	s3.printSer();
	return 0;
}



