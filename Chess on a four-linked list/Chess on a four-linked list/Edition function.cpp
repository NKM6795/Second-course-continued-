#include "Edition function.h"

void game(int heightOfTheScrean, int widthOfTheScrean, int timeForWorkProgram, int timeForFPS, int sizeOfCell)
{
	ifstream fileIn("Date/Date for game.dat");

	string addressOfbackground;
	getline(fileIn, addressOfbackground);


	Graphic graphic(widthOfTheScrean, heightOfTheScrean);

	graphic.setInformation(widthOfTheScrean / 2, heightOfTheScrean / 2, widthOfTheScrean, heightOfTheScrean, addressOfbackground);

	Vector2int mousePosition;

	long timerForWorkProgram = 0,
		timerForFPS = 0;

	Board temp;
	temp.setInformation(8, 25, string("Date/Date for board.dat"));

	graphic.setInformation(temp);

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

			temp.work(mousePosition, Mouse::isButtonPressed(Mouse::Left), sizeOfCell);

			if (graphic.getTimeAsMicroseconds() - timerForFPS >= timeForFPS)
			{
				timerForFPS += timeForFPS;

				graphic.draw(temp, sizeOfCell);
			}
		}
	}
}