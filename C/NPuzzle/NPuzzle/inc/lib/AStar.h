#pragma once

#include <functional>

#include "lib/AStarNode.h"
#include "lib/Heuristic.h"
#include <queue>
#include <deque>
#include <list>

class GraphState;


class AStar {
  typedef AStarNode Node;
public:

  int CalcHeuristic(const Node& node) const {
    return heuristic_->Calculate(node);
  }

private:
  Heuristic *heuristic_;
  //std::unary_function<AStarNode, int> *heuristic_;
  std::priority_queue<Node, std::deque<Node>, std::greater<Node>> openlist_;
  std::queue<Node> closedlist_;
  GraphState *initial_, *goal_;

};