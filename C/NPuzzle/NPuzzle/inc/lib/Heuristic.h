#pragma once

class Heuristic {
public:

  virtual int Calculate(const AStarNode& node) const =0;

private:
};