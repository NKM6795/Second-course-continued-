#include "Game.h"


void game()
{
	int screanWidth, screanHeight, sizeOfCell, timeForWorkProgram, timeForFPS;
	
	ifstream fileIn("Date/Date for game.dat");

	fileIn >> screanWidth >> screanHeight >> sizeOfCell >> timeForWorkProgram >> timeForFPS;

	string addressOfbackground;
	getline(fileIn, addressOfbackground);
	getline(fileIn, addressOfbackground);


	Graphic graphic(screanWidth, screanHeight);

	graphic.setInformation(screanWidth / 2, screanHeight / 2, screanWidth, screanHeight, addressOfbackground);

	Vector2int mousePosition;

	long timerForWorkProgram = 0,
		timerForFPS = 0;

	Board board;
	board.setInformation(8, 25, string("Date/Date for board.dat"));

	graphic.setInformation(board);

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

			board.work(mousePosition, Mouse::isButtonPressed(Mouse::Left), sizeOfCell);

			if (graphic.getTimeAsMicroseconds() - timerForFPS >= timeForFPS)
			{
				timerForFPS += timeForFPS;

				graphic.draw(board, sizeOfCell);
			}
		}
	}
}