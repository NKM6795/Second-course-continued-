#include "Graphic.h"


void Graphic::setInformation(int xCoordinate, int yCoordinate, int width, int height, string fileName)
{
	needBackground = true;

	backgroundTexture = make_shared<Texture>();
	backgroundTexture->loadFromFile(fileName);

	backgroundSprite = make_shared<Sprite>();
	backgroundSprite->setTexture(*backgroundTexture);

	backgroundSprite->setOrigin(width * 0.5f, height * 0.5f);
	backgroundSprite->setPosition(float(xCoordinate), float(yCoordinate));
}

void Graphic::setInformation(Board &board)
{
	drawBoard.setInformation(board.getSizeOfBoard(), board.getOffset());
}


void Graphic::drawWindow()
{
	textureForWindow->display();

	Sprite spriteForWindow;
	spriteForWindow.setTexture(textureForWindow->getTexture());
	window->draw(spriteForWindow);
	window->display();
	window->clear(Color(119, 107, 76));

	textureForWindow->clear(Color(119, 107, 76));
}


void Graphic::drawPrivate()
{
	if (needBackground)
	{
		textureForWindow->draw(*backgroundSprite);
	}
}

void Graphic::drawPrivate(Board &board, int sizeOfCell)
{
	drawBoard.draw(*textureForWindow, screanHeight, screanWidth, sizeOfCell, board.getHead(), board.getAllotment(), board.getFreeCellList().getHead(), board.getFreeCellList().getSize(), board.getEnemyList().getHead(), board.getEnemyList().getSize(), board.turn);
}


void Graphic::draw(Board &board, int sizeOfCell)
{
	drawInRenderTexture(board, sizeOfCell);

	drawWindow();
}


void Graphic::drawInRenderTexture(Board &board, int sizeOfCell)
{
	drawPrivate();
	drawPrivate(board, sizeOfCell);
}


long Graphic::getTimeAsMilliseconds()
{
	return globalTimer.getElapsedTime().asMilliseconds();
}

long long Graphic::getTimeAsMicroseconds()
{
	return globalTimer.getElapsedTime().asMicroseconds();
}


bool Graphic::isOpen()
{
	return window ? true : false;
}

void Graphic::close()
{
	window->close();
	window.reset();
}

bool Graphic::pollEvent()
{
	return window->pollEvent(event);
}

Event Graphic::getEvent()
{
	return event;
}


Vector2int Graphic::getPositionOfMouse()
{
	return convert(Mouse::getPosition(*window));
}