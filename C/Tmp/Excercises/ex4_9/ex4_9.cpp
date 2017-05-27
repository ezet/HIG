#include <iostream>
using namespace std;

struct Time {
	int hours, minutes, seconds;
};

int main() {
	Time time;
	char d;
	
	cout << "Enter a time value (xx:xx:xx): ";
	cin >> time.hours >> d >> time.minutes >> d >> time.seconds;
	cout << "Total amount in seconds: " << time.hours * 3600 + time.minutes * 60 + time.seconds << endl;
	return 0;
}