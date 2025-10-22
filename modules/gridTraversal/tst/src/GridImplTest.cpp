#include <gtest/gtest.h>

#include "GridImpl.h"
#include "Types.h"
#include "gridTraversal/CellPosition.h"

using namespace gridtraversal;

class GridImplTest : public ::testing::Test
{
 protected:
  void SetUp() override
  {
    grid = std::make_unique<GridImpl>(rows, columns, std::vector<CellPosition>{});
  }

  void TearDown() override
  {
  }

  const size_t rows{8};
  const size_t columns{8};
  std::unique_ptr<GridImpl> grid;
};

TEST_F(GridImplTest, IsWithinBoundsReturnsTrueForValidPosition)
{
  CellPosition pos{3, 3};
  EXPECT_TRUE(grid->isWithinBounds(pos));
}

TEST_F(GridImplTest, IsWithinBoundsReturnsFalseForOutOfBounds)
{
  EXPECT_FALSE(grid->isWithinBounds({-1, 0}));
  EXPECT_FALSE(grid->isWithinBounds({0, -1}));
  EXPECT_FALSE(grid->isWithinBounds({9, 0}));
  EXPECT_FALSE(grid->isWithinBounds({0, 9}));
}

TEST_F(GridImplTest, FindFirstFreeCellInWholeGrid)
{
  const GridImpl whole_grid(4, 4, std::vector<CellPosition>{{1, 1}, {2, 1}, {3, 1}});
  const CellPosition expected{1, 2};

  const auto found = whole_grid.findFirstFreeCell();
  EXPECT_EQ(found, expected);
}

TEST_F(GridImplTest, FindFirstFreeCellReturnsTopLeftIfFree)
{
  CellPosition found = grid->findFirstFreeCell();
  EXPECT_EQ(found, CellPosition(1, 1));
}
