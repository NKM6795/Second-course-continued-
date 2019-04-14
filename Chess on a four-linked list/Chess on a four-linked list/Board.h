#pragma once


#include <string>
#include "FiguresMoving.h"


using std::string;
using std::getline;


class Board
{
private:
	int sizeOfBoard;
	Vector2int allotment;
	Vector2int allotmentPast;
	shared_ptr<Cell> head;

	int moveThroughOne;

	SinglyLinked<Cell> freeCell;
	SinglyLinked<Cell> enemy;

public:
	ColorFigures turn;

	Board(int sizeOfBoard, string addressOfBeginingPosition);

	bool moveCheck(int i, int j);
	bool moveCheck(int i, int j, int beginI, int beginJ);

	void makeAMove(int i, int j);

	void newMoves();
	void newMoves(int i, int j);

	shared_ptr<Cell> getCell(int i, int j);

	int getSizeOfBoard();
	shared_ptr<Cell> getHead();
	Vector2int getAllotment();
	Vector2int &accessToAllotment();
	SinglyLinked<Cell> getFreeCellList();
	SinglyLinked<Cell> getEnemyList();
};