#ifndef GRID_H
#define GRID_H

#include <memory>
#include <vector>

#include "CellPosition.h"

namespace gridtraversal
{
class GridImpl;

/// @brief A class representing a Grid
class Grid
{
 public:
  /// @brief A Grid constructor that takes grid parameters along with blocked cells
  /// @param rows number of rows
  /// @param columns number of columns
  /// @param blocked_cells list of blocked cells
  Grid(size_t rows, size_t columns, const std::vector<CellPosition>& blocked_cells);
  ~Grid();

  /// @brief A method that calculates and prints the solution in the std::cout stream depending on
  /// the given number of moves
  /// @param number_of_moves
  void solveAndPrintSolution(size_t number_of_moves) const;

 private:
  std::unique_ptr<GridImpl> impl;
};
}  // namespace gridtraversal

#endif  // GRID_H
