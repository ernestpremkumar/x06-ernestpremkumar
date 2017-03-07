/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TicTacToeBoard tp;

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, boardCheck)
{
	tp.placePiece(4,4);
	ASSERT_TRUE(Invalid);
}

TEST(TicTacToeBoardTest, placeCheck)
{
	tp.placePiece(0,0);  //X's turn
	ASSERT_TRUE(X);
}


TEST(TicTacToeBoardTest, placeCheck1)
{
	tp.placePiece(0,1);  //O's turn
	ASSERT_TRUE(O);
}

TEST(TicTacToeBoardTest, placeCheck3)
{
	tp.placePiece(0,2);  //X's turn
	tp.placePiece(0,2);  //O's turn
	ASSERT_TRUE(X);
}

TEST(TicTacToeBoardTest, getCheck)
{
	tp.getPiece(0,1);
	ASSERT_TRUE(O);
}

TEST(TicTacToeBoardTest, getCheck1)
{
	tp.getPiece(4,5);
	ASSERT_TRUE(Invalid);
}

TEST(TicTacToeBoardTest, getCheck2)
{
	tp.getPiece(2,2);
	ASSERT_TRUE(Blank);	
}

TEST(TicTacToeBoardTest, winTest1)
{
	tp.getWinner();
	ASSERT_TRUE(Invalid);
}

TEST(TicTacToeBoardTest, fillboardwincheck)
{
	tp.placePiece(1,0);
	tp.placePiece(1,1);
	tp.placePiece(1,2);
	tp.placePiece(2,0);
	tp.placePiece(2,1);
	tp.placePiece(2,2);
	tp.getWinner();
	ASSERT_TRUE(Blank);
}

TEST(TicTacToeBoardTest, XwinCheck)
{
	tp.clearBoard();
	tp.placePiece(0,0);
	tp.placePiece(0,0);
	tp.placePiece(0,1);
	tp.placePiece(0,1);
	tp.placePiece(0,2);
	tp.getWinner();
	ASSERT_TRUE(X);
}

TEST(TicTacToeBoardTest, OwinCheck)
{
	tp.clearBoard();
	tp.placePiece(0,0);
	tp.placePiece(0,0);
	tp.placePiece(1,0);
	tp.placePiece(1,0);
	tp.placePiece(2,0);
	tp.getWinner();
	ASSERT_TRUE(O);
}


TEST(TicTacToeBoardTest, DiagTest1)
{
	tp.clearBoard();
	tp.placePiece(0,0);
	tp.placePiece(0,1);
	tp.placePiece(1,1);
	tp.placePiece(0,2);
	tp.placePiece(2,2);
	tp.getWinner();
	ASSERT_TRUE(X);
}

TEST(TicTacToeBoardTest, DiagTest2)
{
	tp.clearBoard();
	tp.placePiece(0,2);
	tp.placePiece(0,0);
	tp.placePiece(1,1);
	tp.placePiece(2,2);
	tp.placePiece(2,0);
	tp.getWinner();
	ASSERT_TRUE(O);
}
