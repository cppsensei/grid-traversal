#ifndef TYPES_H
#define TYPES_H

#include <set>
#include <tuple>
#include <vector>

#include "gridTraversal/CellPosition.h"

namespace gridtraversal
{
enum class CellType
{
  FREE,
  BLOCKED,
};

enum class Direction
{
  NORTH,
  EAST,
  WEST,
  SOUTH
};

constexpr Direction allDirection[]{Direction::NORTH, Direction::EAST, Direction::WEST,
                                   Direction::SOUTH};

using GridArray = std::vector<std::vector<CellType>>;

// The StateKey contains the cell position and the number of moves made
struct StateKey
{
  CellPosition cellPosition{0, 0};
  size_t numOfMovesMade{};

  bool operator<(const StateKey& other) const
  {
    return std::tie(cellPosition.row, cellPosition.col, numOfMovesMade) <
           std::tie(other.cellPosition.row, other.cellPosition.col, other.numOfMovesMade);
  }
};

struct State
{
  StateKey stateKey{};
  std::set<CellPosition> visited{};
  std::vector<CellPosition> path{};
};
struct Solution
{
  std::vector<CellPosition> path{};
  size_t numOfUniqueFields{0};
};
}  // namespace gridtraversal

#endif  // TYPES_H
