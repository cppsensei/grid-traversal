#ifndef TYPES_H
#define TYPES_H

#include <vector>

enum class CellType
{
  FREE,
  BLOCKED,
};

using GridArray = std::vector<std::vector<CellType>>;

struct Solution
{
  std::list<CellPosition> road{};
  size_t numOfUniqueFields{0};
};

#endif  // TYPES_H
