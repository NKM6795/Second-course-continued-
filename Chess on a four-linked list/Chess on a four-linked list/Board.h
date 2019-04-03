#pragma once


#include "DrawBoard.h"

class Board
{
private:
	DrawBoard drawBoard;
	FiguresMoving figuresMoving;

	int offset;
	int sizeOfBoard;
	Vector2i allotment;
	Vector2i allotmentPast;
	Cell *head = nullptr;

	int moveThroughOne;
	bool needDoing;
	bool keyIsPressed;
	bool figureIsAllotment;

	SinglyLinked<Cell> freeCell;
	SinglyLinked<Cell> enemy;

	
	Cell *getCell(int i, int j);

public:
	ColorFigures turn;
	void setInformation(int sizeOfBoardForClass, int offsetForClass, string addressOfBeginingPosition);
	void work(Vector2i mousePosition, bool isPressed, int sizeOfCell);
	void draw(RenderTexture &textureForWindow, int heightOfTheScrean, int widthOfTheScrean, int sizeOfCell);
};