#include "stdafx.h"

#include <iostream>
#include <string>

#include "NPuzzle.h"
#include "Tile.h"

const int DIM_MIN = 3;
const int DIM_MAX = 9;

void DisplayMotd();

int main(int argc, char *argv[]) {
  char run = 'y';

  do {
    DisplayMotd();
    std::cout << "Enter puzzle size N (NxN): ";
    int dim;
    std::cin >> dim;

    NPuzzle puzzle(dim);
    puzzle.Init();
    DisplayMotd();

    std::string errormsg = "";
    while (true) {
      //puzzle.Clear();
      puzzle.Draw();
      std::cout << "\n\n" << errormsg;

      if (puzzle.state() == NPuzzle::complete) {
        std::cout << "You won!";
        break;
      }

      std::cout << "\n\nTile to move: ";
      int tile;
      std::cin >> tile;

      if (!puzzle.Move(Tile(tile))) {
        errormsg =  "Illegal move.";
      } else {
        errormsg = "";
      }
    }

    std::cout << "\n\nPlay again (y/n)? ";
    std::cin >> run;
  } while(tolower(run) == 'y');

  return 0;
}

void DisplayMotd() {
  std::cout << "Welcome to the game of Fifteen\n";
}