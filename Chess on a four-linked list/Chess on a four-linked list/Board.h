#pragma once


#include <string>
#include "FiguresMoving.h"


using std::string;
using std::getline;


class Board
{
private:
	bool change;

	int offset;
	int sizeOfBoard;
	Vector2int allotment;
	Vector2int allotmentPast;
	shared_ptr<Cell> head;

	int moveThroughOne;
	bool needDoing;
	bool keyIsPressed;
	bool figureIsAllotment;

	SinglyLinked<Cell> freeCell;
	SinglyLinked<Cell> enemy;

	
	shared_ptr<Cell> getCell(int i, int j);

public:
	ColorFigures turn;

	void setInformation(int sizeOfBoardForClass, int offsetForClass, string addressOfBeginingPosition);

	void work(Vector2int mousePosition, bool isPressed, int sizeOfCell);

	int getSizeOfBoard();
	int getOffset();
	shared_ptr<Cell> getHead();
	Vector2int getAllotment();
	SinglyLinked<Cell> getFreeCellList();
	SinglyLinked<Cell> getEnemyList();
};