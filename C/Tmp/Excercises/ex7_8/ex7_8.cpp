#include <iostream>
using namespace std;

const int LIMIT = 80;

class safearray {
private:
	int arr[LIMIT];
public:
	void putel(int index, int input) {
		if( index >= 0 && index < LIMIT )
			arr[index] = input;
		else
			cout << "ERROR: Index is out of array bounds.";
	}
	int getel(int index) {
		if( index >=0 && index < LIMIT )
			return arr[index];
		else
			cout << "ERROR: Index is out of array bounds.";
		return 0;
	}
};

int main() {
	safearray sa1;
	int temp = 12345;
	sa1.putel(80, temp);
	cout << sa1.getel(80);
	
	return 0;
} // endmain