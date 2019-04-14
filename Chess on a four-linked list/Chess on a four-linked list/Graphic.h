#pragma once


#include "DrawBoard.h"
#include "Board.h"

class Graphic
{
	Clock globalTimer;
	Event event;

	int screenWidth;
	int screenHeight;
	shared_ptr<RenderWindow> window;
	shared_ptr<RenderTexture> textureForWindow;

	bool needBackground;
	shared_ptr<Texture> backgroundTexture;
	shared_ptr<Sprite> backgroundSprite;

	DrawBoard drawBoard;



	void drawWindow();

	void drawPrivate();
	void drawPrivate(Board &board, int sizeOfCell);

public:
	Graphic(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight)
	{
		window = make_shared<RenderWindow>(VideoMode(screenWidth, screenHeight), "Chess", Style::None);

		textureForWindow = make_shared<RenderTexture>();
		textureForWindow->create(screenWidth, screenHeight);
		textureForWindow->clear(Color(119, 107, 76));

		needBackground = false;
	}

	void setInformation(int xCoordinate, int yCoordinate, int width, int height, string fileName);
	void setInformation(Board &board, int offset);

	void draw(Board &board, int sizeOfCell);

	void drawInRenderTexture(Board &board, int sizeOfCell);


	long getTimeAsMilliseconds();
	long long getTimeAsMicroseconds();


	bool isOpen();
	void close();

	bool pollEvent();
	Event getEvent();

	Vector2int getPositionOfMouse();
};