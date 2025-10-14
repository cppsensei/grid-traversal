#include <iostream>
#include <vector>

#include "gridTraversal/Grid.h"

int main()
{
  constexpr uint16_t num_of_rows{8};
  constexpr uint16_t num_of_cols{8};
  constexpr uint16_t movementPoints{25};

  const std::list<CellPosition> blocked_cells{{0, 2}, {1, 0}, {2, 1}};

  Grid grid(num_of_rows, num_of_cols, blocked_cells);
  grid.solveAndPrintSolution(movementPoints);

  return 0;
}
