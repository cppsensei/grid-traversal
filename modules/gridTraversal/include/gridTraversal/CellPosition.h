#ifndef CELL_POSITION_H
#define CELL_POSITION_H

#include <cstdint>
#include <ostream>

/// @brief
struct CellPosition
{
  /// @brief x coordinate position
  uint16_t x;

  /// @brief y coordinate position
  uint16_t y;

  /// @brief CellPosition ctor
  /// @param x_ x coordinate position
  /// @param y_ y coordinate position
  CellPosition(uint16_t x_, uint16_t y_) : x(x_), y(y_)
  {
  }

  /// @brief An operator comparing two CellPosition object
  /// @param other second operand
  /// @return returns true if the positions are the same
  bool operator==(const CellPosition& other) const
  {
    return x == other.x && y == other.y;
  }

  /// @brief An operator printing positions in the style '(x,y)'
  /// @param stream
  /// @param cellPosition
  /// @return
  friend std::ostream& operator<<(std::ostream& stream, const CellPosition& cellPosition)
  {
    return stream << "(" << cellPosition.x << "," << cellPosition.y << ")";
  }
};

#endif  // CELL_POSITION_H
