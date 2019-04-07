#include "pch.h"
#include "../Chess on a four-linked list/Board.h"


TEST(BoardTest, correctData)
{
	//arrange
	string fileName = "../Chess on a four-linked list/Date/Date for board.dat";

	int sizeOfBoard = 8;
	Board board(sizeOfBoard, 25, fileName);

	ifstream fileIn(fileName);


	for (int i = 0; i < sizeOfBoard; ++i)
	{
		for (int j = 0; j < sizeOfBoard; ++j)
		{
			//action
			shared_ptr<Cell> cell = board.getCell(j, i);
			shared_ptr<Cell> check = make_shared<Cell>();
			fileIn >> check->figureId >> check->colorId;

			//assert
			EXPECT_EQ(check->figure, cell->figure);
			EXPECT_EQ(check->color, cell->color);
		}
	}
}

TEST(BoardTest, erase)
{
	//arrange
	string fileName = "../Chess on a four-linked list/Date/Date for board.dat";

	int sizeOfBoard = 8;
	Board board(sizeOfBoard, 25, fileName);

	shared_ptr<Cell> check = make_shared<Cell>();


	for (int i = 0; i < sizeOfBoard; ++i)
	{
		for (int j = 0; j < sizeOfBoard; ++j)
		{
			//action
			shared_ptr<Cell> cell = board.getCell(j, i);
			FiguresMoving::erase(cell);

			//assert
			EXPECT_EQ(check->figure, cell->figure);
			EXPECT_EQ(check->color, cell->color);
		}
	}
}

TEST(BoardTest, newMoves)
{
	//arrange
	string fileName = "../Chess on a four-linked list/Date/Date for board.dat";

	int sizeOfBoard = 8;
	Board board(sizeOfBoard, 25, fileName);

	for (int i = 0; i < sizeOfBoard; ++i)
	{
		for (int j = 0; j < sizeOfBoard; ++j)
		{
			//action
			shared_ptr<Cell> cell = board.getCell(j, i);
			board.accessToAllotment() = { j, i };
			board.newMoves();

			//assert
			if (cell->figure == Figure::Pawn || cell->figure == Figure::Knight)
			{
				EXPECT_LT(0, board.getFreeCellList().getSize());
			}
			else
			{
				EXPECT_EQ(0, board.getFreeCellList().getSize());
			}

			EXPECT_EQ(0, board.getEnemyList().getSize());
		}
	}
}

TEST(BoardTest, moveCheck)
{
	//arrange
	string fileName = "../Chess on a four-linked list/Date/Date for board.dat";

	int sizeOfBoard = 8;
	Board board(sizeOfBoard, 25, fileName);

	shared_ptr<Cell> firstCell, secondCell;

	//assert
	EXPECT_TRUE(board.moveCheck(1, 3, 1, 1));
	EXPECT_FALSE(board.moveCheck(3, 1, 2, 1));
	EXPECT_FALSE(board.moveCheck(4, 1, 6, 1));
	EXPECT_TRUE(board.moveCheck(0, 2, 1, 0));
	EXPECT_FALSE(board.moveCheck(0, 0, 1, 0));
}

TEST(BoardTest, makeAMove)
{
	//arrange
	string fileName = "../Chess on a four-linked list/Date/Date for board.dat";

	int sizeOfBoard = 8;
	Board board(sizeOfBoard, 25, fileName);

	shared_ptr<Cell> firstCell, secondCell;

	{
		//action
		board.accessToAllotment() = { 1, 1 };
		board.makeAMove(1, 3);

		firstCell = board.getCell(1, 1);
		secondCell = board.getCell(1, 3);

		//assert
		EXPECT_EQ(Figure::Pawn, secondCell->figure);
		EXPECT_EQ(ColorFigures::Black, secondCell->color);

		EXPECT_EQ(Figure::Nothing, firstCell->figure);
		EXPECT_EQ(ColorFigures::NoColor, firstCell->color);
	}

	{
		//action
		board.accessToAllotment() = { 1, 6 };
		board.makeAMove(1, 4);

		firstCell = board.getCell(1, 6);
		secondCell = board.getCell(1, 4);

		//assert
		EXPECT_EQ(Figure::Pawn, secondCell->figure);
		EXPECT_EQ(ColorFigures::White, secondCell->color);

		EXPECT_EQ(Figure::Nothing, firstCell->figure);
		EXPECT_EQ(ColorFigures::NoColor, firstCell->color);
	}
}