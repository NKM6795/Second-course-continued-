#include "pch.h"
#include "../Chess on a four-linked list/SinglyLinked.h"


TEST(SinglyLinkedTest, PushBackElements)
{
	//arrange
	SinglyLinked<int> list;

	for (int i = 0; i < 100; ++i)
	{
		//action
		list.pushBack(i);

		//assert
		EXPECT_EQ(i + 1, list.getSize());
	}
}


TEST(SinglyLinkedTest, PopFrontElements)
{
	//arrange
	SinglyLinked<int> list;

	//action
	for (int i = 0; i < 100; ++i)
	{
		list.pushBack(i);
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


TEST(SinglyLinkedTest, clearList)
{
	//arrange
	SinglyLinked<int> list;

	for (int j = 0; j < 10; ++j)
	{
		//action
		for (int i = 0; i < j; ++i)
		{
			list.pushBack(i);
		}
		
		//assert
		EXPECT_EQ(j, list.getSize());

		//action
		list.clear();

		//assert
		EXPECT_EQ(0, list.getSize());
	}
}


TEST(SinglyLinkedTest, correctElement)
{
	//arrange
	SinglyLinked<int> list;

	//action
	for (int i = 0; i < 100; ++i)
	{
		list.pushBack(i);
	}

	//arrange
	shared_ptr<SinglyNode<int> > node = list.getHead();

	//assert
	for (int i = 0; i < 100; ++i, node = node->next)
	{
		EXPECT_EQ(i, node->data);
	}
}