#ifndef CELL_POSITION_H
#define CELL_POSITION_H

#include <ostream>

namespace gridtraversal
{
/// @brief A structure representing single cell coordinates
struct CellPosition
{
  /// @brief row number
  int row;

  /// @brief column number
  int col;

  /// @brief CellPosition ctor
  /// @param row_ row number
  /// @param y_ col number
  CellPosition(int row_, int col_) : row(row_), col(col_)
  {
  }

  /// @brief An operator comparing two CellPosition object
  /// @param other second operand
  /// @return returns true if the positions are the same
  bool operator==(const CellPosition& other) const
  {
    return row == other.row && col == other.col;
  }

  bool operator<(const CellPosition& other) const
  {
    return (row < other.row) || (row == other.row && col < other.col);
  }

  /// @brief An operator printing positions in the style '(x,y)'
  /// @param stream
  /// @param cellPosition
  /// @return
  friend std::ostream& operator<<(std::ostream& stream, const CellPosition& cellPosition)
  {
    return stream << "(" << cellPosition.row << "," << cellPosition.col << ")";
  }
};
}  // namespace gridtraversal

#endif  // CELL_POSITION_H
