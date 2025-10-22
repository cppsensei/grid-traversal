#ifndef GRID_IMPL_H
#define GRID_IMPL_H

#include <vector>

#include "Types.h"
#include "gridTraversal/CellPosition.h"

namespace gridtraversal
{
class GridImpl
{
 public:
  GridImpl(size_t rows, size_t columns, const std::vector<CellPosition>& blocked_cells);

  void solveAndPrintSolution(size_t number_of_moves) const;
  bool isWithinBounds(const CellPosition& cell_position) const;
  bool isCellFree(const CellPosition& cell_position) const;
  bool isValidMove(const CellPosition& cell_position) const;
  CellPosition findFirstFreeCell() const;
  CellPosition findBestStartingCell() const;
  Solution maxUniqueCells(const CellPosition& cell_position, size_t number_of_moves) const;
  Solution solve(size_t number_of_moves) const;

 private:
  const size_t numOfRows;
  const size_t numOfColumns;

  GridArray gridArray;
};
}  // namespace gridtraversal

#endif  // GRID_IMPL_H
