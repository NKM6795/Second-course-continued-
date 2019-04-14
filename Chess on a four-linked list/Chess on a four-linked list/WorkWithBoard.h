#pragma once


#include "Board.h"


class WorkWithBoard
{
	bool change;

	bool needDoing;
	bool keyIsPressed;
	   
	bool figureIsAllotment;
	Vector2int allotmentPast;

	int offset;

public:
	WorkWithBoard(int offset);

	void work(Board &board, Vector2int mousePosition, bool isPressed, int sizeOfCell);

};