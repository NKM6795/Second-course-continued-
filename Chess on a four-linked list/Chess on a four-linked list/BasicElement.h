#pragma once


#include <SFML/Graphics.hpp>
#include <fstream>
#include "SinglyLinked.h"


using std::ifstream;
using namespace sf;


enum Figure
{
	Nothing = 0,
	King,
	Queen,
	Rook,
	Bishop,
	Knight,
	Pawn
};


enum ColorFigures
{
	NoColor = 0,
	White,
	Black
};


struct Cell
{
	bool moveThroughOne;
	bool firstUnique;
	union
	{
		Figure figure;
		int figureId;
	};

	union
	{
		ColorFigures color;
		int colorId;
	};

	Vector2i position;

	shared_ptr<Cell> up,
		down,
		left,
		right;

	Cell();

	void setInformation(Figure figure, ColorFigures color, int i, int j);
	void setInformation(int figureId, int colorId, int i, int j);
};


