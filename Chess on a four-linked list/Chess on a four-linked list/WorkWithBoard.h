#pragma once


#include "Board.h"


class WorkWithBoard
{
	bool change;

	bool needDoing;
	bool keyIsPressed;
	   
	bool figureIsAllotment;
	Vector2int allotmentPast;


public:
	WorkWithBoard();

	void work(Board &board, Vector2int mousePosition, bool isPressed, int sizeOfCell);

};