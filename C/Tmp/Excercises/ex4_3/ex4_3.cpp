#include <iostream>
using namespace std;

struct Distance {
	float feet;
	float inches;
};
struct Volume {
	Distance width;
	Distance length;
	Distance height;
};

int main() {
	Volume room = { {13, 6.5}, {10, 0.0}, {7, 2} };
	float width, length, height, volume;

	width = room.width.feet+room.width.inches/12;
	length = room.length.feet+room.length.inches/12;
	height = room.height.feet+room.length.inches/12;

	volume = length*width*height;
	cout << "Volume is: " << volume << endl;
	return 0;
}


	