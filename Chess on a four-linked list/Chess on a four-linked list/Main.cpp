#include "Edition function.h"

int main()
{
	ifstream fileInForStart("Date/Date for start.dat");

	int widthOfTheScrean, heightOfTheScrean, sizeOfCell, timeForWorkProgram, timeForFPS;
	fileInForStart >> widthOfTheScrean >> heightOfTheScrean >> sizeOfCell >> timeForWorkProgram >> timeForFPS;


	game(heightOfTheScrean, widthOfTheScrean, timeForWorkProgram, timeForFPS, sizeOfCell);

	return 0;
}