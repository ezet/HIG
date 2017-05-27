#include <iostream>
using namespace std;
	
const int MAX = 10;

class matrix {
private:
	int mat[MAX][MAX];
	int nLimit, mLimit;
public:
	matrix(int mm, int nn) : mLimit(mm), nLimit(nn) { };
	matrix() : mLimit(MAX), nLimit(MAX) { };

	void putel( int mm, int nn, int input ) {
		if( mm >= 0 && nn >= 0 && (mm < mLimit) && (nn < nLimit) )
			mat[mm][nn] = input;
		else
			cout << "ERROR: Out of bounds.";
	}

	int getel( int mm, int nn ) {
		if( mm >= 0 && nn >= 0 && (mm < mLimit) && (nn < nLimit) )
			return mat[mm][nn];
		cout << "ERROR: Out of bounds.";
		return 0;
	}
};

int main() {
	matrix m1(4, 4);
	int temp = 12345;
	m1.putel(4, 4, temp);
	cout << m1.getel(4, 4) << endl;



	return 0;
} // endmain