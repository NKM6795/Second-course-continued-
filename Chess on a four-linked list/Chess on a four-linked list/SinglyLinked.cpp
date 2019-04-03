#include "SinglyLinked.h"


SinglyNode::SinglyNode(int i, int j) : i(i), j(j)
{

}


SinglyLinked::SinglyLinked()
{
	length = 0;
}


void SinglyLinked::pushBack(int i, int j)
{
	shared_ptr<SinglyNode> newNode = make_shared<SinglyNode>(i, j);

	if (length == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	++length;
}


void SinglyLinked::popFront()
{
	if (length != 0)
	{
		shared_ptr<SinglyNode> node = head;
		head = head->next;
		node.reset();

		--length;
	}
}


void SinglyLinked::clear()
{
	while (length > 0)
	{
		popFront();
	}
}


int SinglyLinked::getSize()
{
	return length;
}


shared_ptr<SinglyNode> SinglyLinked::getHead()
{
	return head;
}