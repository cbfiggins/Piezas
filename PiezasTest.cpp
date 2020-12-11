/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, pieceAt_empty)
{
  Piezas board;
  Piece actual = board.pieceAt(1,2);
	ASSERT_EQ(actual, Blank);
}

TEST(PiezasTest, pieceAt_overRow)
{
  Piezas board;
  Piece actual = board.pieceAt(5,2);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, pieceAt_underRow)
{
  Piezas board;
  Piece actual = board.pieceAt(-1,2);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, pieceAt_overColumn)
{
  Piezas board;
  Piece actual = board.pieceAt(2,6);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, pieceAt_underColumn)
{
  Piezas board;
  Piece actual = board.pieceAt(2,-3);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, dropPiece_underColumn)
{
  Piezas board;
  Piece actual = board.dropPiece(-3);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, dropPiece_overColumn)
{
  Piezas board;
  Piece actual = board.dropPiece(6);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, dropPiece_emptyColumn)
{
  Piezas board;
  Piece actual = board.dropPiece(2);
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, dropPiece_fullColumn)
{
  Piezas board;
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(2);
  Piece actual = board.dropPiece(2);
	ASSERT_EQ(actual, Blank);
}

TEST(PiezasTest, pieceAt_threePlacedColumn)
{
  Piezas board;
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(2);
  Piece actual = board.pieceAt(2, 2);
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, pieceAt_twoPlacedColumn)
{
  Piezas board;
  board.dropPiece(2);
  board.dropPiece(2);
  Piece actual = board.pieceAt(1, 2);
	ASSERT_EQ(actual, O);
}

TEST(PiezasTest, pieceAt_onePlacedColumn)
{
  Piezas board;
  board.dropPiece(2);
  Piece actual = board.pieceAt(0, 2);
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, pieceAt_placedCorrectPositions)
{
  Piezas board;
  board.dropPiece(2);
  Piece actual = board.pieceAt(2, 2);
	ASSERT_EQ(actual, Blank);
}

TEST(PiezasTest, pieceAt_placedDifferentColumns)
{
  Piezas board;
  board.dropPiece(2);
  board.dropPiece(3);
  Piece actual = board.pieceAt(0, 3);
	ASSERT_EQ(actual, O);
}

TEST(PiezasTest, reset_fullboard)
{
  Piezas board;
  for(int i = 0; i < BOARD_COLS; i++){
    for(int j = 0; j < BOARD_ROWS; j++){
      board.dropPiece(BOARD_COLS);
    }
  }
  board.reset();
  Piece actual = board.pieceAt(0, 3);
	ASSERT_EQ(actual, Blank);
}

TEST(PiezasTest, gameState_empty)
{
  Piezas board;
  Piece actual = board.gameState();
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, gameState_unfinished)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(2);

  Piece actual = board.gameState();
	ASSERT_EQ(actual, Invalid);
}

//Drew games by hand to make sure wins were correct

TEST(PiezasTest, gameState_X_win_horizontal)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(1);

  Piece actual = board.gameState();
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, gameState_O_win_horizontal)
{
  Piezas board;
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(2);
  board.dropPiece(1);

  Piece actual = board.gameState();
	ASSERT_EQ(actual, O);
}

TEST(PiezasTest, gameState_X_win_vertical)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(1);
  board.dropPiece(1);

  Piece actual = board.gameState();
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, gameState_O_win_vertical)
{
  Piezas board;
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(1);

  Piece actual = board.gameState();
	ASSERT_EQ(actual, O);
}


TEST(PiezasTest, gameState_tie_horizontal)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(3);
  board.dropPiece(1);
  board.dropPiece(2);

  Piece actual = board.gameState();
	ASSERT_EQ(actual, Blank);
}

TEST(PiezasTest, gameState_tie_vertical)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(3);

  Piece actual = board.gameState();
	ASSERT_EQ(actual, Blank);
}
