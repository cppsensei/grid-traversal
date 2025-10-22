#include "GridImpl.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

#include "Types.h"
#include "gridTraversal/CellPosition.h"

namespace gridtraversal
{
namespace
{
void printSolution(std::ostream& stream, const gridtraversal::Solution& solution)
{
  for (const auto& cellPosition : solution.path)
  {
    stream << cellPosition << ", ";
  }

  stream << solution.numOfUniqueFields << std::endl;
}

CellPosition getPositionAfterMove(const CellPosition& cell_position, Direction direction)
{
  auto after_move_position = cell_position;
  switch (direction)
  {
    case Direction::NORTH:
      --after_move_position.row;
      break;
    case Direction::EAST:
      ++after_move_position.col;
      break;
    case Direction::WEST:
      --after_move_position.col;
      break;
    case Direction::SOUTH:
      ++after_move_position.row;
      break;
  }

  return after_move_position;
}
}  // namespace

GridImpl::GridImpl(size_t rows, size_t columns, const std::vector<CellPosition>& blocked_cells)
    : numOfRows(rows),
      numOfColumns(columns),
      gridArray(rows + 1, std::vector<CellType>(columns + 1, CellType::FREE))
{
  for (const auto& cell_position : blocked_cells)
  {
    if (isWithinBounds(cell_position) == false)
    {
      throw std::out_of_range("Blocked cell position is outside the grid boundaries");
    }

    gridArray[cell_position.row][cell_position.col] = CellType::BLOCKED;
  }
}

void GridImpl::solveAndPrintSolution(size_t number_of_moves) const
{
  // here we can decide about our output
  std::ostream& stream = std::cout;
  printSolution(stream, solve(number_of_moves));
}

bool GridImpl::isWithinBounds(const CellPosition& cell_position) const
{
  return (cell_position.row >= 1 && cell_position.row <= numOfRows && cell_position.col >= 1 &&
          cell_position.col < numOfColumns)
             ? true
             : false;
}

bool GridImpl::isCellFree(const CellPosition& cell_position) const
{
  return gridArray[cell_position.row][cell_position.col] == CellType::FREE;
}

bool GridImpl::isValidMove(const CellPosition& cell_position) const
{
  return isWithinBounds(cell_position) && isCellFree(cell_position);
}

CellPosition GridImpl::findFirstFreeCell() const
{
  for (int row = 1; row <= numOfRows; ++row)
  {
    for (int col = 1; col <= numOfColumns; ++col)
    {
      if (CellPosition cell{row, col}; isCellFree(cell))
      {
        return cell;
      }
    }
  }

  return CellPosition{0, 0};
}

CellPosition GridImpl::findBestStartingCell() const
{
  return findFirstFreeCell();
}

Solution GridImpl::maxUniqueCells(const CellPosition& cell_position, size_t number_of_moves) const
{
  size_t max_unique{0};
  std::vector<CellPosition> best_path{};

  // A map that contains the best partial solutions (dynamic programming)
  std::map<StateKey, size_t> visited_dp{};

  std::queue<State> q;
  State start_state{};
  start_state.stateKey.cellPosition = cell_position;
  start_state.stateKey.numOfMovesMade = 0;
  start_state.visited.insert(cell_position);
  start_state.path.push_back(cell_position);
  q.push(start_state);

  while (!q.empty())
  {
    auto curr = q.front();
    q.pop();

    if (curr.stateKey.numOfMovesMade == number_of_moves)
    {
      if (curr.visited.size() > max_unique)
      {
        max_unique = curr.visited.size();
        best_path = curr.path;
      }
      continue;
    }

    for (const auto& direction : allDirection)
    {
      const auto cell_position_after_move =
          getPositionAfterMove(curr.stateKey.cellPosition, direction);

      if (isValidMove(cell_position_after_move) == false)
      {
        continue;
      }

      auto new_visited = curr.visited;
      new_visited.insert(cell_position_after_move);

      StateKey state_key{};
      state_key.cellPosition = cell_position_after_move;
      state_key.numOfMovesMade = curr.stateKey.numOfMovesMade + 1;

      if (visited_dp.count(state_key) > 0 && visited_dp[state_key] >= new_visited.size())
      {
        continue;
      }

      visited_dp[state_key] = new_visited.size();

      State next{};
      next.stateKey.cellPosition = cell_position_after_move;
      next.stateKey.numOfMovesMade = curr.stateKey.numOfMovesMade + 1;
      next.visited = new_visited;
      next.path = curr.path;
      next.path.push_back(cell_position_after_move);
      q.push(next);
    }
  }

  Solution solution{};
  solution.numOfUniqueFields = max_unique;
  solution.path = best_path;

  return solution;
}

Solution GridImpl::solve(size_t number_of_moves) const
{
  const auto starting_cell = findBestStartingCell();
  return maxUniqueCells(starting_cell, number_of_moves);
}
}  // namespace gridtraversal
