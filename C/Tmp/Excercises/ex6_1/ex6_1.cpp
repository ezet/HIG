#include <iostream>
using namespace std;

class Int {
private:
	int num;
public:
	Int() : num(0) { };
	Int(int n) : num(n) { };
	void echo() { cout << num; }
	void add(Int n1, Int n2) { num = n1.num + n2.num; }
};

int main() {
	Int int1(2);
	Int int2(3);
	Int int3;
	
	int3.add(int1, int2);
	int3.echo(); cout << endl;

	return 0;
}


