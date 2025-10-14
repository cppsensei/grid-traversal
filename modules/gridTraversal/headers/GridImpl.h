#ifndef GRID_IMPL_H
#define GRID_IMPL_H

#include <cstdint>
#include <list>

#include "Types.h"
#include "gridTraversal/CellPosition.h"

class GridImpl
{
 public:
  GridImpl(uint16_t rows, uint16_t columns, const std::list<CellPosition>& blocked_cells);
  void solveAndPrintSolution(uint16_t number_of_moves) const;

 private:
  bool isWithinBounds(const CellPosition& cell_position) const;
  std::list<Solution> solve(bool onlyOneSolution = true) const;

  bool blockedCellContainsInGridArray{};

  const uint16_t numOfRows;
  const uint16_t numOfColumns;

  GridArray gridArray;
};

#endif  // GRID_IMPL_H
