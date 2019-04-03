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
	
	void setInformation(int sizeOfBoardForClass, int offsetForClass);
	void draw(RenderTexture &textureForWindow, int heightOfTheScrean, int widthOfTheScrean, int sizeOfCell, shared_ptr<Cell> head, Vector2i allotment, shared_ptr<SinglyNode<Cell> > headForFreeCell, int lengthForFreeCell, shared_ptr<SinglyNode<Cell> > headForEnemy, int lengthForEnemy, int turn);

};


Vector2int convert(Vector2i value);
Vector2i convert(Vector2int value);