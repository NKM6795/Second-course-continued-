#include "BasicElement.h"

Cell::Cell()
{
	firstUnique = false;
	moveThroughOne = false;
	figure = Figure::Nothing;
	color = ColorFigures::NoColor;
}


void Cell::setInformation(Figure figure, ColorFigures color, int i, int j)
{
	this->figure = figure;
	this->color = color;

	if (figure == Figure::Pawn || figure == Figure::King || figure == Figure::Rook)
	{
		firstUnique = true;
	}

	position = { i, j };
}


void Cell::setInformation(int figureId, int colorId, int i, int j)
{
	this->figureId = figureId;
	this->colorId = colorId;

	setInformation(figure, color, i, j);
}