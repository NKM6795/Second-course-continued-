#include "WorkWithBoard.h"


WorkWithBoard::WorkWithBoard()
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
			int i = (mousePosition.x - board.getOffset()) / sizeOfCell,
				j = (mousePosition.y - board.getOffset()) / sizeOfCell;
			if (i >= 0 && i < board.getSizeOfBoard() && j >= 0 && j < board.getSizeOfBoard() && mousePosition.x > board.getOffset() && mousePosition.y > board.getOffset())
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
			int i = (mousePosition.x - board.getOffset()) / sizeOfCell,
				j = (mousePosition.y - board.getOffset()) / sizeOfCell;
			if (i >= 0 && i < board.getSizeOfBoard() && j >= 0 && j < board.getSizeOfBoard() && mousePosition.x > board.getOffset() && mousePosition.y > board.getOffset())
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
		if (isPressed && mousePosition.x - board.getOffset() >= 2 * sizeOfCell && mousePosition.x - board.getOffset() < 6 * sizeOfCell && mousePosition.y - board.getOffset() >= 3 * sizeOfCell && mousePosition.y - board.getOffset() < 4 * sizeOfCell)
		{
			shared_ptr<Cell> beginOfLine = board.getHead();
			for (int i = 0; i < board.getSizeOfBoard(); ++i)
			{
				shared_ptr<Cell> cell = beginOfLine;
				for (int j = 0; j < board.getSizeOfBoard(); ++j)
				{
					if (cell->figure == Figure::Pawn && (cell->position.x == board.getSizeOfBoard() - 1 || cell->position.x == 0))
					{
						cell->figure = (Figure)((mousePosition.x - board.getOffset()) / sizeOfCell);
					}
					cell = cell->right;
				}
				beginOfLine = beginOfLine->down;
			}
			change = false;
		}
	}
}
