#include "DrawBoard.h"

void DrawBoard::setInformation(int sizeOfBoard, int offset)
{
	this->sizeOfBoard = sizeOfBoard;
	this->offset = offset;
	change = false;

	figureTexture.loadFromFile("Data/Objects/Figures/chess.png");
	figureSprite.setTexture(figureTexture);

	allotmentTexture.loadFromFile("Data/Objects/Buttons/Allotment.png");
	allotmentSprite.setTexture(allotmentTexture);

	freeCellTexture.loadFromFile("Data/Objects/Buttons/Free cell.png");
	freeCellSprite.setTexture(freeCellTexture);

	enemyTexture.loadFromFile("Data/Objects/Buttons/Enemy.png");
	enemySprite.setTexture(enemyTexture);

	changeTexture.loadFromFile("Data/Objects/Figures/figure for change.png");
	changeSprite.setTexture(changeTexture);
}

void DrawBoard::draw(RenderTexture &textureForWindow, int screenHeight, int screenWidth, int sizeOfCell, shared_ptr<Cell> head, Vector2int allotment, shared_ptr<SinglyNode<Cell> > headForFreeCell, int lengthForFreeCell, shared_ptr<SinglyNode<Cell> > headForEnemy, int lengthForEnemy, int turn)
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
		tempImage.create(screenWidth, screenHeight, sf::Color(0, 0, 0, 200));
		Texture tempTexture;
		tempTexture.loadFromImage(tempImage);
		Sprite tempSprite;
		tempSprite.setTexture(tempTexture);

		textureForWindow.draw(tempSprite);

		changeSprite.setTextureRect(IntRect(0, turn == ColorFigures::White ? 0 : sizeOfCell, sizeOfCell * 4, sizeOfCell));
		changeSprite.setPosition(float(screenWidth / 2), float(screenHeight / 2));
		changeSprite.setOrigin(float(changeTexture.getSize().x / 2), float(changeTexture.getSize().y / 2));
		textureForWindow.draw(changeSprite);
	}
}