#include <iostream>
#include <conio.h>
using namespace std;

class tollBooth {
private:
	unsigned int totalcars;
	double totalmoney;
public:
	tollBooth() : totalcars(0), totalmoney(0.0) { };
	void paycar() { totalcars++; totalmoney += 0.5; }
	void nopaycar() { totalcars++; }
	void echo() const { cout << "Total cars: " << totalcars << endl << "Total money: " << totalmoney << endl; }
};

int main() {
	tollBooth toll;
	char c = 1;

	while((c = _getch()) != 27) {
		switch(c) {
		case 'q':
			toll.paycar(); break;
		case 'w':
			toll.nopaycar(); break;
		}
	}
	toll.echo();
	return 0;
}