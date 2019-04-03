#include "pch.h"
#include "../Chess on a four-linked list/SinglyLinked.h"


TEST(SinglyLinkedTest, AddElements)
{
	//arrange
	SinglyLinked list;

	for (int i = 1; i < 100; ++i)
	{
		//action
		list.pushBack(i, i);

		//assert
		EXPECT_EQ(i, list.getSize());
	}
}