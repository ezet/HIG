#pragma once
#include "lib/AStar.h"
#include "lib/Heuristic.h"
#include <list>

class NPuzzle;

class NPuzzleSolver {
public:
  NPuzzleSolver(NPuzzle *puzzle) {
    puzzle_ = puzzle;
  }

  int Solve() {
    return 0;

  }

private:
  NPuzzle* puzzle_;

};