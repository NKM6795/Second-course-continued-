#include "Board.h"


Board::Board(int sizeOfBoard, string addressOfBeginingPosition) : sizeOfBoard(sizeOfBoard)
{
	turn = ColorFigures::White;
	moveThroughOne = -1;
	allotment = { -1, -1 };

	ifstream fileIn(addressOfBeginingPosition);
	int figure, color;
	shared_ptr<Cell> cell = head;
	for (int i = 0; i < sizeOfBoard; ++i)
	{
		shared_ptr<Cell> temp = make_shared<Cell>();
		fileIn >> figure >> color;
		temp->setInformation(figure, color, 0, i);

		if (i == 0)
		{
			head = temp;
			cell = head;
		}
		else
		{
			temp->left = cell;
			cell->right = temp;
			cell = cell->right;
		}
	}
	
	shared_ptr<Cell> beginOfLine = head;
	shared_ptr<Cell> cellUp = head->right;
	for (int i = 1; i < sizeOfBoard; ++i)
	{
		cellUp = beginOfLine->right;
		cell = beginOfLine;

		for (int j = 0; j < sizeOfBoard; ++j)
		{
			shared_ptr<Cell> temp = make_shared<Cell>();

			fileIn >> figure >> color;
			temp->setInformation(figure, color, i, j);
			if (j == 0)
			{
				temp->up = cell;
				cell->down = temp;
				cell = cell->down;
			}
			else
			{
				temp->left = cell;
				cell->right = temp;
				temp->up = cellUp;
				cellUp->down = temp;
				cell = cell->right;
				cellUp = cellUp->right;
			}
		}
		beginOfLine = beginOfLine->down;
	}
}


bool Board::moveCheck(int i, int j)
{
	bool check = false;

	shared_ptr<SinglyNode<Cell> > node = getFreeCellList().getHead();
	for (int k = 0; k < getFreeCellList().getSize(); ++k)
	{
		if (node->data.position.y == i && node->data.position.x == j)
		{
			check = true;
		}
		node = node->next;
	}
	node = getEnemyList().getHead();
	for (int k = 0; k < getEnemyList().getSize(); ++k)
	{
		if (node->data.position.y == i && node->data.position.x == j)
		{
			check = true;
		}
		node = node->next;
	}
	return check;
}

bool Board::moveCheck(int i, int j, int beginI, int beginJ)
{
	newMoves(beginI, beginJ);

	return moveCheck(i, j);
}


void Board::makeAMove(int i, int j)
{
	shared_ptr<Cell> first = getCell(allotment.x, allotment.y);
	shared_ptr<Cell> second = getCell(i, j);
	if (first->figure == Figure::Pawn)
	{
		first->firstUnique = false;
		if (allotment.y - j == 2 || allotment.y - j == -2)
		{
			first->moveThroughOne = true;
			moveThroughOne = turn;
		}
		if ((allotment.x - i == 1 || allotment.x - i == -1) && (allotment.y - j == 1 || allotment.y - j == -1) && second->color == ColorFigures::NoColor)
		{
			if ((allotment.x - i == 1 && allotment.y - j == 1) || (allotment.x - i == 1 && allotment.y - j == -1))
			{
				FiguresMoving::erase(first->left);
			}
			else if ((allotment.x - i == -1 && allotment.y - j == 1) || (allotment.x - i == -1 && allotment.y - j == -1))
			{
				FiguresMoving::erase(first->right);
			}
		}
	}
	else if (first->figure == Figure::King)
	{
		first->firstUnique = false;
		if (allotment.x - i == -2)
		{
			FiguresMoving::goTo(first->right->right->right, first->right);
		}
		if (allotment.x - i == 2)
		{
			FiguresMoving::goTo(first->left->left->left->left, first->left);
		}
	}
	else if (first->figure == Figure::Rook)
	{
		first->firstUnique = false;
	}

	FiguresMoving::goTo(first, second);
	allotment = { -1, -1 };
	enemy.clear();
	freeCell.clear();

	turn = (ColorFigures)(2 - (turn + 1) % 2);

	if (moveThroughOne == turn)
	{
		shared_ptr<Cell> beginOfLine = head;
		for (int i = 0; i < sizeOfBoard; ++i)
		{
			shared_ptr<Cell> cell = beginOfLine;
			for (int j = 0; j < sizeOfBoard; ++j)
			{
				if (cell->moveThroughOne)
				{
					cell->moveThroughOne = false;
				}

				cell = cell->right;
			}
			beginOfLine = beginOfLine->down;
		}
		moveThroughOne = -1;
	}
}


void Board::newMoves()
{
	newMoves(allotment.x, allotment.y);
}

void Board::newMoves(int i, int j)
{
	enemy.clear();
	freeCell.clear();
	shared_ptr<Cell> cell = getCell(i, j);

	FiguresMoving::checkAllFunction(cell, freeCell, enemy);
}


shared_ptr<Cell> Board::getCell(int i, int j)
{
	shared_ptr<Cell> cell = head;
	for (int k = 0; k < j; ++k)
	{
		cell = cell->down;
	}
	for (int k = 0; k < i; ++k)
	{
		cell = cell->right;
	}
	return cell;
}


int Board::getSizeOfBoard()
{
	return sizeOfBoard;
}

shared_ptr<Cell> Board::getHead()
{
	return head;
}

Vector2int Board::getAllotment()
{
	return allotment;
}

Vector2int &Board::accessToAllotment()
{
	return allotment;
}

SinglyLinked<Cell> Board::getFreeCellList()
{
	return freeCell;
}

SinglyLinked<Cell> Board::getEnemyList()
{
	return enemy;
}