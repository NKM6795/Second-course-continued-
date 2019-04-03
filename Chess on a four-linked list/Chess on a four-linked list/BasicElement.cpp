#include "BasicElement.h"

Cell::Cell()
{
	firstUnique = false;
	moveThroughOne = false;
	figure = Figure::Nothing;
	color = ColorFigures::NoColor;
}


void Cell::setInformation(int figureForStruct, int colorForStruct, int i, int j)
{
	figure = (Figure)figureForStruct;
	color = (ColorFigures)colorForStruct;

	if (figure == Figure::Pawn || figure == Figure::King || figure == Figure::Rook)
	{
		firstUnique = true;
	}

	position = { i, j };
}

