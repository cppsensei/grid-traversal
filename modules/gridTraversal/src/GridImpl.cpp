#include "GridImpl.h"

#include <iostream>
#include <vector>

#include "Types.h"
#include "gridTraversal/CellPosition.h"

namespace
{
void printSolution(std::ostream& stream, const Solution& solution)
{
  for (const auto& cellPosition : solution.road)
  {
    stream << cellPosition << ", ";
  }

  stream << solution.numOfUniqueFields << std::endl;
}
}  // namespace

GridImpl::GridImpl(uint16_t rows, uint16_t columns, const std::list<CellPosition>& blocked_cells)
    : numOfRows(rows),
      numOfColumns(columns),
      gridArray(numOfRows, std::vector<CellType>(numOfColumns, CellType::FREE))
{
  for (const auto& cell_position : blocked_cells)
  {
    if (isWithinBounds(cell_position) == false)
    {
      blockedCellContainsInGridArray = false;
      return;
    }

    gridArray[cell_position.x][cell_position.y] = CellType::BLOCKED;
  }

  blockedCellContainsInGridArray = true;
}

void GridImpl::solveAndPrintSolution(uint16_t number_of_moves) const
{
  // here we can decide about our output
  std::ostream& stream = std::cout;

  if (blockedCellContainsInGridArray == false)
  {
    stream << "The specified blocked cells were outside the grid range\n";
    return;
  }

  for (const auto& solution : solve())
  {
    printSolution(stream, solution);
  }
}

bool GridImpl::isWithinBounds(const CellPosition& cell_position) const
{
  return (cell_position.x >= numOfColumns || cell_position.y >= numOfRows) ? false : true;
}

std::list<Solution> GridImpl::solve(bool onlyOneSolution) const
{
  Solution s;
  s.numOfUniqueFields = 23;
  s.road = {{0, 2}, {0, 3}};

  return {s};
}
