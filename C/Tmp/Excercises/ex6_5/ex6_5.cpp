#include <iostream>
using namespace std;

class date {
private:
	int d, m, y;
	static char dum;
public:
	void getdate() {
		cin >> d >> dum >> m >> dum >> y;
	}
	void printdate() const {
		cout << d << '/' << m << '/' << y;
	}
};

int main() {
	return 0;
}