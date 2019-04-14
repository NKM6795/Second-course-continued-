#include "WorkWithBoard.h"


WorkWithBoard::WorkWithBoard(int offset) : offset(offset)
{
	change = false;

	needDoing = false;
	keyIsPressed = false;

	figureIsAllotment = false;
}


void WorkWithBoard::work(Board &board, Vector2int mousePosition, bool isPressed, int sizeOfCell)
{
	if (!change)
	{
		if (isPressed)
		{
			keyIsPressed = true;
			int i = (mousePosition.x - offset) / sizeOfCell,
				j = (mousePosition.y - offset) / sizeOfCell;
			if (i >= 0 && i < board.getSizeOfBoard() && j >= 0 && j < board.getSizeOfBoard() && mousePosition.x > offset && mousePosition.y > offset)
			{
				shared_ptr<Cell> cell = board.getCell(i, j);

				if (cell->figure != 0 && cell->color == board.turn)
				{
					board.accessToAllotment() = { i, j };
					if (board.accessToAllotment() != allotmentPast)
					{
						figureIsAllotment = true;
						allotmentPast = board.accessToAllotment();
					}
				}
			}
		}

		if (!isPressed && keyIsPressed)
		{
			needDoing = true;
			keyIsPressed = false;
		}

		if (needDoing && board.getAllotment().x != -1)
		{
			needDoing = false;
			int i = (mousePosition.x - offset) / sizeOfCell,
				j = (mousePosition.y - offset) / sizeOfCell;
			if (i >= 0 && i < board.getSizeOfBoard() && j >= 0 && j < board.getSizeOfBoard() && mousePosition.x > offset && mousePosition.y > offset)
			{
				if (board.moveCheck(i, j))
				{
					board.makeAMove(i, j);
				}
			}
		}

		if (figureIsAllotment)
		{
			board.newMoves();

			figureIsAllotment = false;
		}
	}
	else
	{
		if (isPressed && mousePosition.x - offset >= 2 * sizeOfCell && mousePosition.x - offset < 6 * sizeOfCell && mousePosition.y - offset >= 3 * sizeOfCell && mousePosition.y - offset < 4 * sizeOfCell)
		{
			shared_ptr<Cell> beginOfLine = board.getHead();
			for (int i = 0; i < board.getSizeOfBoard(); ++i)
			{
				shared_ptr<Cell> cell = beginOfLine;
				for (int j = 0; j < board.getSizeOfBoard(); ++j)
				{
					if (cell->figure == Figure::Pawn && (cell->position.x == board.getSizeOfBoard() - 1 || cell->position.x == 0))
					{
						cell->figure = (Figure)((mousePosition.x - offset) / sizeOfCell);
					}
					cell = cell->right;
				}
				beginOfLine = beginOfLine->down;
			}
			change = false;
		}
	}
}
