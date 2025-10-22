#include "gridTraversal/Grid.h"

#include "GridImpl.h"

namespace gridtraversal
{
Grid::Grid(size_t rows, size_t columns, const std::vector<CellPosition>& blocked_cells)
    : impl(std::make_unique<GridImpl>(rows, columns, blocked_cells))
{
}

Grid::~Grid() = default;

void Grid::solveAndPrintSolution(size_t number_of_moves) const
{
  impl->solveAndPrintSolution(number_of_moves);
}
}  // namespace gridtraversal
