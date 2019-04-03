#pragma once


#include <string>
#include "DrawBoard.h"


using std::string;
using std::getline;


class Board
{
private:
	DrawBoard drawBoard;

	int offset;
	int sizeOfBoard;
	Vector2i allotment;
	Vector2i allotmentPast;
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
	void work(Vector2i mousePosition, bool isPressed, int sizeOfCell);
	void draw(RenderTexture &textureForWindow, int heightOfTheScrean, int widthOfTheScrean, int sizeOfCell);
};