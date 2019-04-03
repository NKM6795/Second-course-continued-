#pragma once


#include "BasicElement.h"

class FiguresMoving
{
private:
	static void checkPosition(shared_ptr<Cell> cell, shared_ptr<Cell> beginCell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	static void checkPositionForKing(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	static void checkVertAndHoriz(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	static void checkDiagonal(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	static void checkPositionForKnight(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
	static void checkPositionForPawn(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
public:
	static void erase(shared_ptr<Cell> cell);
	static void goTo(shared_ptr<Cell> firsCell, shared_ptr<Cell> secondCell);
	static void checkAllFunction(shared_ptr<Cell> cell, SinglyLinked<Cell> &freeCell, SinglyLinked<Cell> &enemy);
};