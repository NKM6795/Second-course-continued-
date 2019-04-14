#pragma once


#include <SFML/Graphics.hpp>
#include "FiguresMoving.h"


using namespace sf;


class DrawBoard
{
private:
	int offset;
	int sizeOfBoard;

	Texture figureTexture;
	Sprite figureSprite;

	Texture changeTexture;
	Sprite changeSprite;

	Texture allotmentTexture;
	Sprite allotmentSprite;

	Texture freeCellTexture;
	Sprite freeCellSprite;

	Texture enemyTexture;
	Sprite enemySprite;


public:
	bool change;
	
	void setInformation(int sizeOfBoard, int offset);
	void draw(RenderTexture &textureForWindow, int heightOfThescreen, int screenWidth, int sizeOfCell, shared_ptr<Cell> head, Vector2int allotment, shared_ptr<SinglyNode<Cell> > headForFreeCell, int lengthForFreeCell, shared_ptr<SinglyNode<Cell> > headForEnemy, int lengthForEnemy, int turn);

};