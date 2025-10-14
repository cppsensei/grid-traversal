#ifndef GRID_H
#define GRID_H

#include <cstdint>
#include <list>
#include <memory>

#include "CellPosition.h"

class GridImpl;

/// @brief A class representing a Grid
class Grid
{
 public:
  /// @brief A Grid constructor that takes grid parameters along with blocked cells
  /// @param rows number of rows
  /// @param columns number of columns
  /// @param blocked_cells list of blocked cells
  Grid(uint16_t rows, uint16_t columns, const std::list<CellPosition>& blocked_cells);
  ~Grid();

  /// @brief A method that calculates and prints the solution in the std::cout stream depending on
  /// the given number of moves
  void solveAndPrintSolution(uint16_t number_of_moves) const;

 private:
  std::unique_ptr<GridImpl> impl;
};

#endif  // GRID_H
