#include "Game.h"


void game()
{
	int screenWidth, screenHeight, sizeOfCell, timeForWorkProgram, timeForFPS, offset, sizeOfBoard;
	
	ifstream fileIn("Data/Data for game.dat");

	fileIn >> screenWidth >> screenHeight >> sizeOfCell >> timeForWorkProgram >> timeForFPS >> sizeOfBoard >> offset;

	string addressOfbackground;
	getline(fileIn, addressOfbackground);
	getline(fileIn, addressOfbackground);


	Graphic graphic(screenWidth, screenHeight);

	graphic.setInformation(screenWidth / 2, screenHeight / 2, screenWidth, screenHeight, addressOfbackground);


	Vector2int mousePosition;

	long timerForWorkProgram = 0,
		timerForFPS = 0;

	Board board(sizeOfBoard, string("Data/Data for board.dat"));

	graphic.setInformation(board, offset);

	WorkWithBoard workWithBoard(offset);


	while (graphic.isOpen())
	{
		if (graphic.getTimeAsMicroseconds() - timerForWorkProgram >= timeForWorkProgram)
		{
			timerForWorkProgram += timeForWorkProgram;

			mousePosition = graphic.getPositionOfMouse();
			while (graphic.pollEvent())
			{
				if (graphic.getEvent().type == Event::Closed || (graphic.getEvent().type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape)))
				{
					graphic.close();
					return;
				}
			}

			workWithBoard.work(board, mousePosition, Mouse::isButtonPressed(Mouse::Left), sizeOfCell);

			if (graphic.getTimeAsMicroseconds() - timerForFPS >= timeForFPS)
			{
				timerForFPS += timeForFPS;

				graphic.draw(board, sizeOfCell);
			}
		}
	}
}