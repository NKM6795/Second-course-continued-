#include "pch.h"
#include "../Chess on a four-linked list/SinglyLinked.h"


TEST(WorkWithElements, PushBackElements)
{
	//arrange
	SinglyLinked list;

	for (int i = 0; i < 100; ++i)
	{
		//action
		list.pushBack(i, i);

		//assert
		EXPECT_EQ(i + 1, list.getSize());
	}
}


TEST(WorkWithElements, PopFrontElements)
{
	//arrange
	SinglyLinked list;

	//action
	for (int i = 0; i < 100; ++i)
	{
		list.pushBack(i, i);
	}

	for (int i = 100 - 1; i >= 0; --i)
	{
		//action
		list.popFront();

		//assert
		EXPECT_EQ(i, list.getSize());
	}

	//action
	list.popFront();

	//assert
	EXPECT_EQ(0, list.getSize());
}


TEST(WorkWithElements, clearList)
{
	//arrange
	SinglyLinked list;

	for (int j = 0; j < 10; ++j)
	{
		//action
		for (int i = 0; i < j; ++i)
		{
			list.pushBack(i, i);
		}
		
		//assert
		EXPECT_EQ(j, list.getSize());

		//action
		list.clear();

		//assert
		EXPECT_EQ(0, list.getSize());
	}
}


TEST(WorkWithElements, correctElement)
{
	//arrange
	SinglyLinked list;

	//action
	for (int i = 0; i < 100; ++i)
	{
		list.pushBack(i, i);
	}

	//arrange
	shared_ptr<SinglyNode> node = list.getHead();

	//assert
	for (int i = 0; i < 100; ++i, node = node->next)
	{
		EXPECT_EQ(i, node->i);
		EXPECT_EQ(i, node->j);
	}
}