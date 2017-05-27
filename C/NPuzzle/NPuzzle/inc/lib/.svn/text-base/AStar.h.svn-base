#pragma once

#include <functional>

#include "lib/AStarNode.h"
#include "lib/Heuristic.h"

class AStar {
public:

  int CalcHeuristic(const AStarNode& node) const {
    return heuristic_->Calculate(node);
  }

private:
  Heuristic *heuristic_;
  //std::unary_function<AStarNode, int> *heuristic_;

};