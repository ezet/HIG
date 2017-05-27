#include "stdafx.h"

#include <iostream>
#include <string>

#include "NPuzzle.h"
#include "Tile.h"
#include "lib\IoHelper.h"


void DisplayMotd();

int main(int argc, char *argv[]) {
const int DIM_MIN = 3;
const int DIM_MAX = 9;
  char run = 'y';

  do {
    DisplayMotd();
    int dimension = IoHelper::GetIntInRange("Enter puzzle size N (NxN) (2-9): ", 2, 9);
    NPuzzle puzzle(dimension);
    puzzle.Init();

    std::string errormsg = "";
    while (true) {
      puzzle.Clear();
      puzzle.Draw();
      std::cout << "\n\n" << errormsg;

      if (puzzle.status() == NPuzzle::complete) {
        std::cout << "You won!";
        break;
      }

      std::string tile = IoHelper::GetLine("\n\nTile to move: ");

      if (tile == "GOD") {
        errormsg = "GOD mode enabled.";
        puzzle.Solve();
      }
       else if (!puzzle.Move(Tile(atoi(tile.c_str())))) {
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
  std::cout << "\nThis is a traditional NPuzzle game."
    << "\nThe goal is to arrange the numbers from top to bottom, \nleft to right, in ascending order."
    << "\nThe bottom left corner should be blank when completed.\n\n";
}