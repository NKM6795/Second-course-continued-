#include "pch.h"
#include "../Chess on a four-linked list/BasicElement.h"


TEST(Vector2typeTest, operatorsComparison)
{
	for (int i = 0; i < 100; ++i)
	{
		//arrange
		Vector2int first(-(rand() % 10 + 1), -(rand() % 10 + 1)),
			second(rand() % 10 + 1, rand() % 10 + 1);

		//assert
		EXPECT_NE(first, second);
		EXPECT_LT(first, second);
		EXPECT_LE(first, second);
		EXPECT_GT(second, first);
		EXPECT_GE(second, first);
	}
}


TEST(Vector2typeTest, operatorsChanges)
{
	for (int i = 1; i <= 100; ++i)
	{
		//arrange
		Vector2int first(-(rand() % 10 + 1), -(rand() % 10 + 1)),
			second(rand() % 10 + 1, rand() % 10 + 1);

		//assert
		EXPECT_EQ(first + second, Vector2int(first.x + second.x, first.y + second.y));
		EXPECT_EQ(first - second, Vector2int(first.x - second.x, first.y - second.y));
		EXPECT_EQ(first + i, Vector2int(first.x + i, first.y + i));
		EXPECT_EQ(first - i, Vector2int(first.x - i, first.y - i));
		EXPECT_EQ(first * i, Vector2int(first.x * i, first.y * i));
		EXPECT_EQ(first / i, Vector2int(first.x / i, first.y / i));
	}
}