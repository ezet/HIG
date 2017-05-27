#pragma once

/**
* A basic terminal implementation of the N Puzzle game
*
* author     Lars Kristian Dahl <http://www.krisd.com>
* version    $Id$  
* copyright  Copyright (c) 2011 Lars Kristian Dahl <http://www.krisd.com>
* license    http://www.apache.org/licenses/LICENSE-2.0
*/

#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <queue>

#include "Tile.h"
#include "NPuzzleSolver.h"


class NPuzzle {
public:
  enum Status { inprogress, complete };

  /**
  * Constructor
  */
  NPuzzle(int dim) : BLANK(dim*dim) {
    dim_ = dim;
    tiles_ = new Tile**[dim_];
    endstate_ = new int*[dim_];
    pos_ = new int[dim*dim+1];
    pos_[0] = -1;

  }

  /**
  * Destructor
  */
  ~NPuzzle() {
    delete[] endstate_;
    delete[] pos_;
    for (int i = 0; i < dim_; ++i) {
      for (int j = 0; j < dim_; ++j) {
        delete tiles_[i][j];
      }
      delete[] tiles_[i];
    }
    delete[] tiles_;
  }

  /**
  * Accessor for state
  */
  Status status() const {
    return status_;
  }

  /**
  * Accessor for permutes
  */
  std::queue<int> permutes() const {
    return permutes_;
  }

  /**
  * Initiates the puzzle
  */
  void Init(const int shuffles = 50) {
    shuffles_ = shuffles;
    status_ = inprogress;
    Generate();
    Shuffle();
  }

  /**
  * Tries to perform a requested move, returns true if successful
  */
  bool Move(Tile& tile) {
    bool retval = false;
    Tile blank(BLANK);
    if (ValidTile(tile) && IsAdjacent(tile, blank)) {
      Swap(tile, blank);
      permutes_.push(tile.num());
      UpdateState();
      retval = true;
    }
    return retval;
  }

  /**
  * Clears the terminal screen
  */
  void Clear() const {
    system("cls"); // windows

    //std::cout << "/033[2J" << "/033[0;0"; // ansi
  }

  /**
  * Draws the puzzle in a terminal
  */
  void Draw() const {
    for (int i = 0; i < dim_; ++i) {
      std::cout << "\n\n";
      for (int j = 0; j < dim_; ++j) {
        int num = tiles_[i][j]->num();
        std::cout << '\t';
        if (num == BLANK) {
          std::cout << ' ';
        } else {
          std::cout << num;
        }
      }
    }
  }


  /**
  * Attempts to solve the puzzle, returns a statuscode
  */
  int Solve() {
    NPuzzleSolver solver(this);
    return solver.Solve();
  }

private:
  /**
  * Generates the NPuzzle in a completed state, storing it in two
  * different arrays.
  */ 
  void Generate() {
    for (int i = 0; i < dim_; ++i) {
      tiles_[i] = new Tile*[dim_];
      endstate_[i] = new int[dim_];
      for (int j = 0; j < dim_; ++j) {
        tiles_[i][j] = new Tile(i*dim_ + j + 1);
        endstate_[i][j] = i*dim_ + j + 1;
        pos_[tiles_[i][j]->num()] = (i*dim_ + j);
      }
    }
  }

  /**
  * Shuffles the NPuzzle tiles
  */
  void Shuffle() {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < shuffles_ || !Solvable(); ++i) {
      Swap(Tile(rand()%BLANK + 1), Tile(rand()%BLANK + 1));
    }
  }

  /**
  * Returns if the two tiles sent as arguments as adjacent to eachother
  */
  bool IsAdjacent(const Tile& t1, const Tile& t2) const {
    int pos1 = pos_[t1.num()];
    int pos2 = pos_[t2.num()];
    return pos1 + dim_ == pos2 || pos1 - dim_ == pos2
      || (pos1/dim_ == pos2/dim_ && (pos1+1 == pos2 || pos1-1 == pos2));
  }

  /**
  * Swaps the values of two tiles
  */
  bool Swap(const Tile& t1, const Tile& t2) {
    Find(t1).set_num(t2.num());
    Find(t2).set_num(t1.num());
    int pos = pos_[t1.num()];
    pos_[t1.num()] = pos_[t2.num()];
    pos_[t2.num()] = pos;
    return true;
  }

  /**
  * Finds and returns a reference to a tile
  */
  Tile& Find(const Tile& tile) const {
    int pos = pos_[tile.num()];
    return *tiles_[pos/dim_][(pos)%dim_];
  }

  /**
  * Calculates and returns the number of inversions in current puzzle 
  */
  int CalculateInversions() {
    int *arr = new int[BLANK];
    for (int i = 0; i < dim_; ++i)
      for (int j = 0; j < dim_; ++j)
        arr[i*dim_+j] = tiles_[i][j]->num();

    int inv = 0;
    for (int i = 0; i < BLANK; ++i)
      for (int j = i; j < BLANK; ++j)
        if (arr[i] > arr[j] && arr[i] != BLANK && arr[j] != BLANK)
            ++inv;
    delete[] arr;
    return inv;
  }

  /**
  * Returns true if the number of inversions in current puzzle is even
  */
  bool EvenInversions() {
    return CalculateInversions() % 2 ? false : true;
  }

  /**
  * Returns true if the current puzzle gridsize is even
  */
  bool EvenSize() {
    return dim_ % 2 ? false : true;
  }

  /**
  * Returns true if the current puzzle is solvable
  */
  bool Solvable() {
    bool solvable = false;
    if (!EvenSize() && EvenInversions()) {
      solvable = true;
    } else if (EvenSize() && (BlankOnEvenRow() == !EvenInversions())) {
      solvable = true;
    }
    return solvable;
  }

  /**
  * Returns true if the blank tile is on an even row, counting from the last one
  */
  bool BlankOnEvenRow() {
    return (dim_ - (pos_[BLANK] / dim_)) % 2 ? false : true; 
  }

  bool ValidTile(Tile& tile) {
    return tile.num() > 0 && tile.num() < BLANK;
  }

  /**
  * Updates the state of the current puzzle
  */
  void UpdateState() {
    for(int i = 0; i < dim_; ++i) {
      for (int j = 0; j < dim_; ++j) {
        if (tiles_[i][j]->num() != endstate_[i][j]) {
          return;
        }
      }
    }
    status_ = complete;
  }


  /**
  * Current state of the current puzzle
  */
  Tile ***tiles_;

  /**
  * Goal state of the current puzzle
  */
  int **endstate_;

  /**
  * Absolute positions in the grid for each tile
  */
  int *pos_;

  /**
  * Dimension N in the current NxN puzzle
  */
  int dim_;

  /**
  * Current state of the puzzle, can be 'progress' or 'complete'
  */
  Status status_;

  /**
  * All the performed permutes/moves
  */
  std::queue<int> permutes_;

  /**
  * Value of the current blank tile
  */
  const int BLANK;

  /**
  * Times to shuffle the tiles when shuffling a puzzle
  */
  int shuffles_;
};