#pragma once


#include "BasicElement.h"

class FiguresMoving
{
private:
	void checkPosition(shared_ptr<Cell> cell, shared_ptr<Cell> beginCell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkPositionForKing(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkVertAndHoriz(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkDiagonal(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkPositionForKnight(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	void checkPositionForPawn(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
public:
	void erase(shared_ptr<Cell> cell);
	void goTo(shared_ptr<Cell> firsCell, shared_ptr<Cell> secondCell);
	void checkAllFunction(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
};