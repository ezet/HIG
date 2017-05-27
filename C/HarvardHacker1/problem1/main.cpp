#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
  srand(time(NULL));

  int num = rand() % 1024;
  int guess;
  char text[6];
  std::cout << num;

  std::cout << "\nO'Hai! I'm thinking of a number between 0 and 1023, what is it? ";
  do {
    strcpy(text, "fewer");
    std::cin >> guess;

    if (guess < num) {
      strcpy(text, "more");
    }

    if (guess != num) {
      std::cout << "There are " << text << " skittles than that. Guess again: ";
    }
  } while (guess != num);
  std::cout << "That's right! Nom nom nom.\n";


  return 0;
}