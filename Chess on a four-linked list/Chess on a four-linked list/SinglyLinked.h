#pragma once


#include <memory>


using std::shared_ptr;
using std::make_shared;


template<typename T>
struct SinglyNode
{
	T data;

	shared_ptr<SinglyNode> next;
	
	SinglyNode(T data) : data(data)
	{

	}
};


template<typename T>
class SinglyLinked
{
private:
	shared_ptr<SinglyNode<T> > head;
	shared_ptr<SinglyNode<T> > tail;

	int length;

public:
	SinglyLinked()
	{
		length = 0;
	}

	void pushBack(T data)
	{
		shared_ptr<SinglyNode<T> > newNode = make_shared<SinglyNode<T> >(data);

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

	void popFront()
	{
		if (length != 0)
		{
			shared_ptr<SinglyNode<T> > node = head;
			head = head->next;
			node.reset();

			--length;
		}
	}

	void clear()
	{
		while (length > 0)
		{
			popFront();
		}
	}

	int getSize()
	{
		return length;
	}

	shared_ptr<SinglyNode<T> > getHead()
	{
		return head;
	}
};
