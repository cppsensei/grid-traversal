#include "gridTraversal/gridTraversal.h"

using namespace gridtraversal;

int main()
{
  constexpr size_t num_of_rows{8};
  constexpr size_t num_of_cols{8};
  constexpr size_t movementPoints{25};

  // Please remember that the numbering starts from 1 and is a mutually closed interval <1,
  // numOfRows or Columns>
  const std::vector<CellPosition> blocked_cells{{3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5},
                                                {4, 4}, {5, 4}, {6, 6}, {7, 7}};

  Grid grid(num_of_rows, num_of_cols, blocked_cells);
  grid.solveAndPrintSolution(movementPoints);

  return 0;
}
