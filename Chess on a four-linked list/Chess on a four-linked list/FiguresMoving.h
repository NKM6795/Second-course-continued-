#pragma once


#include "BasicElement.h"

class FiguresMoving
{
private:
	void checkPosition(Cell *cell, Cell *beginCell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkPositionForKing(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkVertAndHoriz(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkDiagonal(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkPositionForKnight(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkPositionForPawn(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
public:
	void erase(Cell *cell);
	void goTo(Cell *firsCell, Cell *secondCell);
	void checkAllFunction(Cell *cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
};