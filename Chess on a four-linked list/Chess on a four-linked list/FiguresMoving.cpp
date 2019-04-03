#include "FiguresMoving.h"

void FiguresMoving::checkAllFunction(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy)
{
	if (cell->figure == Figure::King)
	{
		checkPositionForKing(cell, freeCell, enemy);
	}
	else if (cell->figure == Figure::Queen)
	{
		checkDiagonal(cell, freeCell, enemy);
		checkVertAndHoriz(cell, freeCell, enemy);
	}
	else if (cell->figure == Figure::Rook)
	{
		checkVertAndHoriz(cell, freeCell, enemy);
	}
	else if (cell->figure == Figure::Bishop)
	{
		checkDiagonal(cell, freeCell, enemy);
	}
	else if (cell->figure == Figure::Knight)
	{
		checkPositionForKnight(cell, freeCell, enemy);
	}
	else if (cell->figure == Figure::Pawn)
	{
		checkPositionForPawn(cell, freeCell, enemy);
	}
}

void FiguresMoving::checkPosition(Cell *cell, Cell *beginCell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy)
{
	if (cell != nullptr && cell->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*cell);
	}
	else if (cell != nullptr && cell->color != ColorFigures::NoColor && cell->color != beginCell->color)
	{
		enemy.pushBack(*cell);
	}
}

void FiguresMoving::checkPositionForKing(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy)
{
	Cell *temp = cell->right;
	checkPosition(temp, cell, freeCell, enemy);
	if (cell->right != nullptr)
	{
		temp = cell->right->down;
		checkPosition(temp, cell, freeCell, enemy);
	}
	temp = cell->down;
	checkPosition(temp, cell, freeCell, enemy);
	if (cell->left != nullptr)
	{
		temp = cell->left->down;
		checkPosition(temp, cell, freeCell, enemy);
	}
	temp = cell->left;
	checkPosition(temp, cell, freeCell, enemy);
	if (cell->left != nullptr)
	{
		temp = cell->left->up;
		checkPosition(temp, cell, freeCell, enemy);
	}
	temp = cell->up;
	checkPosition(temp, cell, freeCell, enemy);
	if (cell->right != nullptr)
	{
		temp = cell->right->up;
		checkPosition(temp, cell, freeCell, enemy);
	}
	if (cell->firstUnique)
	{
		if (cell->right->color == ColorFigures::NoColor && cell->right->right->color == ColorFigures::NoColor && cell->right->right->right->firstUnique)
		{
			freeCell.pushBack(*(cell->right->right));
		}
		if (cell->left->color == ColorFigures::NoColor && cell->left->left->color == ColorFigures::NoColor && cell->left->left->left->color == ColorFigures::NoColor && cell->left->left->left->left->firstUnique)
		{
			freeCell.pushBack(*(cell->left->left));
		}
	}
}

void FiguresMoving::checkVertAndHoriz(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy)
{
	Cell *temp = cell;
	while (temp->right != nullptr && temp->right->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*(temp->right));
		temp = temp->right;
	}
	checkPosition(temp->right, cell, freeCell, enemy);
	temp = cell;
	while (temp->left != nullptr  && temp->left->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*(temp->left));
		temp = temp->left;
	}
	checkPosition(temp->left, cell, freeCell, enemy);
	temp = cell;
	while (temp->up != nullptr  && temp->up->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*(temp->up));
		temp = temp->up;
	}
	checkPosition(temp->up, cell, freeCell, enemy);
	temp = cell;
	while (temp->down != nullptr  && temp->down->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*(temp->down));
		temp = temp->down;
	}
	checkPosition(temp->down, cell, freeCell, enemy);
}

void FiguresMoving::checkDiagonal(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy)
{
	Cell *temp = cell;
	while (temp->up != nullptr && temp->up->right != nullptr && temp->up->right->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*(temp->up->right));
		temp = temp->up->right;
	}
	if (temp->up != nullptr && temp->up->right != nullptr && temp->up->right->color != ColorFigures::NoColor && temp->up->right->color != cell->color)
	{
		enemy.pushBack(*(temp->up->right));
	}
	temp = cell;
	while (temp->up != nullptr && temp->up->left != nullptr && temp->up->left->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*(temp->up->left));
		temp = temp->up->left;
	}
	if (temp->up != nullptr && temp->up->left != nullptr && temp->up->left->color != ColorFigures::NoColor && temp->up->left->color != cell->color)
	{
		enemy.pushBack(*(temp->up->left));
	}
	temp = cell;
	while (temp->down != nullptr && temp->down->right != nullptr && temp->down->right->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*(temp->down->right));
		temp = temp->down->right;
	}
	if (temp->down != nullptr && temp->down->right != nullptr && temp->down->right->color != ColorFigures::NoColor && temp->down->right->color != cell->color)
	{
		enemy.pushBack(*(temp->down->right));
	}
	temp = cell;
	while (temp->down != nullptr && temp->down->left != nullptr && temp->down->left->color == ColorFigures::NoColor)
	{
		freeCell.pushBack(*(temp->down->left));
		temp = temp->down->left;
	}
	if (temp->down != nullptr && temp->down->left != nullptr && temp->down->left->color != ColorFigures::NoColor && temp->down->left->color != cell->color)
	{
		enemy.pushBack(*(temp->down->left));
	}
}

void FiguresMoving::checkPositionForKnight(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy)
{
	Cell *temp = cell;
	if (cell->position.y > 1)
	{
		temp = cell->left->left;
		checkPosition(temp->up, cell, freeCell, enemy);
		checkPosition(temp->down, cell, freeCell, enemy);

	}
	if (cell->right != nullptr && cell->right->right != nullptr)
	{
		temp = cell->right->right;
		checkPosition(temp->up, cell, freeCell, enemy);
		checkPosition(temp->down, cell, freeCell, enemy);
	}
	if (cell->position.x > 1)
	{
		temp = cell->up->up;
		checkPosition(temp->right, cell, freeCell, enemy);
		checkPosition(temp->left, cell, freeCell, enemy);
	}
	if (cell->down != nullptr && cell->down->down != nullptr)
	{
		temp = cell->down->down;
		checkPosition(temp->right, cell, freeCell, enemy);
		checkPosition(temp->left, cell, freeCell, enemy);
	}
}

void FiguresMoving::checkPositionForPawn(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy)
{
	Cell *temp = cell->color == ColorFigures::White ? cell->up : cell->down;
	if (temp->color == ColorFigures::NoColor)
	{
		if (cell->firstUnique && (cell->color == ColorFigures::White ? temp->up : temp->down)->color == ColorFigures::NoColor)
		{
			checkPosition(cell->color == ColorFigures::White ? temp->up : temp->down, cell, freeCell, enemy);
		}

		checkPosition(temp, cell, freeCell, enemy);
	}
	if (temp->right != nullptr && temp->right->color != ColorFigures::NoColor && temp->right->color != cell->color)
	{
		checkPosition(temp->right, cell, freeCell, enemy);
	}
	if (temp->left != nullptr && temp->left->color != ColorFigures::NoColor && temp->left->color != cell->color)
	{
		checkPosition(temp->left, cell, freeCell, enemy);
	}
	if (cell->right != nullptr && cell->right->color != ColorFigures::NoColor && cell->right->color != cell->color && cell->right->moveThroughOne)
	{
		freeCell.pushBack(*(temp->right));
	}
	if (cell->left != nullptr && cell->left->color != ColorFigures::NoColor && cell->left->color != cell->color && cell->left->moveThroughOne)
	{
		freeCell.pushBack(*(temp->left));
	}
}

void FiguresMoving::erase(Cell *cell)
{
	cell->firstUnique = false;
	cell->figure = Figure::Nothing;
	cell->color = ColorFigures::NoColor;
	cell->moveThroughOne = false;
}

void FiguresMoving::goTo(Cell *firsCell, Cell *secondCell)
{
	secondCell->firstUnique = firsCell->firstUnique;
	secondCell->figure = firsCell->figure;
	secondCell->color = firsCell->color;
	secondCell->moveThroughOne = firsCell->moveThroughOne;
	erase(firsCell);
}
