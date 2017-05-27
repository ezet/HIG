#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
// from 2 to 10 are integers without names
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
///////////////////////////////////////////////
class card {
private:
	int number;
	Suit suit;
public:
	card() { };
	void set(int n, Suit s) {
		suit = s; number = n;
	}
	void display();
};

//-----------------------------------------------
void card::display() {
	if( number >= 2 && number <= 10 )
		cout << number;
	else
		switch(number) {
		case jack: cout << 'J'; break;
		case queen: cout << 'Q'; break;
		case king: cout << 'K'; break;
		case ace: cout << 'A'; break;
	}
	switch(suit) {
	case clubs: cout << static_cast<char>(5); break;
	case diamonds: cout << static_cast<char>(4); break;
	case hearts: cout << static_cast<char>(3); break;
	case spades: cout << static_cast<char>(6); break;
	}
}
///////////////////////////////////////////////////

int main() {
	card deck[52];
	card h1[13], h2[13], h3[13], h4[13];
	int j;

	cout << endl;
	for( j=0; j < 52; j++ ) {		// make an ordered deck
		int num = (j % 13) + 2;		// cycles through 2 to 14, 4 times
		Suit su = Suit(j / 13);		// cycles through 0 to 3, 13 times
		deck[j].set(num, su);		// set card
	}
	
	/*cout << "\nOrdered deck:\n";
	for( j = 0; j < 52; j++ ) {		// display ordered deck
		deck[j].display();
		cout << "  ";
		if( !( (j+1) % 13) )		// newline every 13 cards
			cout << endl;
	}*/
	
	srand( time(NULL) );			// seed random numbers with time
	for( j = 0; j < 52; j++ ) {		// for each card in the deck,
		int k = rand() % 52;		// pick another card at random,
		card temp = deck[j];		// and swap them
		deck[j] = deck[k];
		deck[k] = temp;
	}

	for(int i = 0, j = 0; j < 52; j += 4, i++ ) {
		h1[i] = deck[j];
		h2[i] = deck[j+1];
		h3[i] = deck[j+2];
		h4[i] = deck[j+3];
	}

	cout << "\n--- Hand 1 ---\n";
	for( j = 0; j < 13; j++ ) {
		h1[j].display();
		cout << ", ";
	}
	cout << "\n\n--- Hand 2 ---\n";
	for( j = 0; j < 13; j++ ) {
		h2[j].display();
		cout << ", ";
	}
	cout << "\n\n--- Hand 3 ---\n";
	for( j = 0; j < 13; j++ ) {
		h3[j].display();
		cout << ", ";
	}
	cout << "\n\n--- Hand 4 ---\n";
	for( j = 0; j < 13; j++ ) {
		h4[j].display();
		cout << ", ";
	}
	cout << endl;

	/*cout << "\nSHuffled deck:\n";
	for ( j = 0; j < 52; j++ ) {	// display shuffled deck
		deck[j].display();
		cout << ", ";
		if( !( (j+1) % 13) )		// newline every 13 cards
			cout << endl;
	}*/
	return 0;
}	// end main