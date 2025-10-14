#include "gridTraversal/Grid.h"

#include "GridImpl.h"

Grid::Grid(uint16_t rows, uint16_t columns, const std::list<CellPosition>& blocked_cells)
    : impl(std::make_unique<GridImpl>(rows, columns, blocked_cells))
{
}

Grid::~Grid() = default;

void Grid::solveAndPrintSolution(uint16_t number_of_moves) const
{
  impl->solveAndPrintSolution(number_of_moves);
}
