#include "DrawBoard.h"

void DrawBoard::setInformation(int sizeOfBoardForClass, int offsetForClass)
{
	sizeOfBoard = sizeOfBoardForClass;
	offset = offsetForClass;
	change = false;

	figureTexture.loadFromFile("Date/Objects/Figures/chess.png");
	figureSprite.setTexture(figureTexture);

	allotmentTexture.loadFromFile("Date/Objects/Buttons/Allotment.png");
	allotmentSprite.setTexture(allotmentTexture);

	freeCellTexture.loadFromFile("Date/Objects/Buttons/Free cell.png");
	freeCellSprite.setTexture(freeCellTexture);

	enemyTexture.loadFromFile("Date/Objects/Buttons/Enemy.png");
	enemySprite.setTexture(enemyTexture);

	changeTexture.loadFromFile("Date/Objects/Figures/figure for change.png");
	changeSprite.setTexture(changeTexture);
}

void DrawBoard::draw(RenderTexture &textureForWindow, int heightOfTheScrean, int widthOfTheScrean, int sizeOfCell, shared_ptr<Cell> head, Vector2i allotment, shared_ptr<SinglyNode<Cell> > headForFreeCell, int lengthForFreeCell, shared_ptr<SinglyNode<Cell> > headForEnemy, int lengthForEnemy, int turn)
{
	shared_ptr<Cell> beginOfLine = head;
	for (int i = 0; i < sizeOfBoard; ++i)
	{
		shared_ptr<Cell> cell = beginOfLine;
		for (int j = 0; j < sizeOfBoard; ++j)
		{
			if (cell->figure != 0)
			{
				figureSprite.setPosition(float(j * sizeOfCell + offset), float(i * sizeOfCell + offset));
				figureSprite.setTextureRect(IntRect((cell->figure - 1) * sizeOfCell, (2 - cell->color) * sizeOfCell, sizeOfCell, sizeOfCell));
				textureForWindow.draw(figureSprite);
			}

			cell = cell->right;
		}
		beginOfLine = beginOfLine->down;
	}

	if (allotment.x != -1)
	{
		allotmentSprite.setPosition(float(allotment.x * sizeOfCell + offset), float(allotment.y * sizeOfCell + offset));
		textureForWindow.draw(allotmentSprite);
	}

	shared_ptr<SinglyNode<Cell> > node = headForFreeCell;
	for (int i = 0; i < lengthForFreeCell; ++i)
	{
		freeCellSprite.setPosition(float(node->data.position.y * sizeOfCell + offset), float(node->data.position.x * sizeOfCell + offset));
		textureForWindow.draw(freeCellSprite);
		node = node->next;
	}
	node = headForEnemy;
	for (int i = 0; i < lengthForEnemy; ++i)
	{
		enemySprite.setPosition(float(node->data.position.y * sizeOfCell + offset), float(node->data.position.x * sizeOfCell + offset));
		textureForWindow.draw(enemySprite);
		node = node->next;
	}

	if (change)
	{
		Image tempImage;
		tempImage.create(widthOfTheScrean, heightOfTheScrean, sf::Color(0, 0, 0, 200));
		Texture tempTexture;
		tempTexture.loadFromImage(tempImage);
		Sprite tempSprite;
		tempSprite.setTexture(tempTexture);

		textureForWindow.draw(tempSprite);

		changeSprite.setTextureRect(IntRect(0, turn == ColorFigures::White ? 0 : sizeOfCell, sizeOfCell * 4, sizeOfCell));
		changeSprite.setPosition(float(widthOfTheScrean / 2), float(heightOfTheScrean / 2));
		changeSprite.setOrigin(float(changeTexture.getSize().x / 2), float(changeTexture.getSize().y / 2));
		textureForWindow.draw(changeSprite);
	}
}


Vector2int convert(Vector2i value)
{
	return Vector2int(value.x, value.y);
}

Vector2i convert(Vector2int value)
{
	return Vector2i(value.x, value.y);
}
