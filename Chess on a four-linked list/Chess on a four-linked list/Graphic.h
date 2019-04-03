#pragma once


#include "DrawBoard.h"
#include "Board.h"

class Graphic
{
	Clock globalTimer;
	Event event;

	int screanWidth;
	int screanHeight;
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
	Graphic(int screanWidth, int screanHeight) : screanWidth(screanWidth), screanHeight(screanHeight)
	{
		window = make_shared<RenderWindow>(VideoMode(screanWidth, screanHeight), "Chess", Style::None);

		textureForWindow = make_shared<RenderTexture>();
		textureForWindow->create(screanWidth, screanHeight);
		textureForWindow->clear(Color(119, 107, 76));

		needBackground = false;
	}

	void setInformation(int xCoordinate, int yCoordinate, int width, int height, string fileName);
	void setInformation(Board &board);

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