#include "pch.h"
#include "../Chess on a four-linked list/BasicElement.h"


TEST(CellTest, links)
{
	//arrange
	Cell *first = new Cell;
	Cell *second = new Cell;

	//action
	first->up = second;

	//assert
	EXPECT_EQ(second, first->up);


	//action
	first->down = second;

	//assert
	EXPECT_EQ(second, first->down);


	//action
	first->left = second;

	//assert
	EXPECT_EQ(second, first->left);


	//action
	first->right = second;

	//assert
	EXPECT_EQ(second, first->right);
}

TEST(CellTest, data)
{
	//arrange
	Cell *first = new Cell;
	
	//action
	first->setInformation(Figure::King, ColorFigures::White, 4, 5);

	//assert
	EXPECT_EQ(Figure::King, first->figure);
	EXPECT_EQ(ColorFigures::White, first->color);
	EXPECT_EQ(4, first->position.x);
	EXPECT_EQ(5, first->position.y);
	EXPECT_TRUE(first->firstUnique);
	EXPECT_FALSE(first->moveThroughOne);
}