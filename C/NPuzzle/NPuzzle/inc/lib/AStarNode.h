#pragma once

class AStarNode {
public:
  AStarNode() {
    parent = child = NULL;
    curcost_ = estcost_ = totalcost_ = 0;
  }

  double totalcost() const {
    return totalcost_;
  }

  bool operator>(const AStarNode& node) {
    return totalcost() > node.totalcost();
  }

  void CalculateEstimatedCost() {

  }

  void CalculateCurrentCost() {

  }

  void CalculateTotalCost() {

  }

private:
  int x_;
  int y_;
  int val_;
  AStarNode *parent;
  AStarNode *child;
  double curcost_, estcost_, totalcost_;

};

struct NodeGreaterThan : public std::binary_function<AStarNode, AStarNode, bool> {
  bool operator()(const AStarNode& lhs, const AStarNode& rhs)  {
    return lhs.totalcost() > rhs.totalcost();
  }
};