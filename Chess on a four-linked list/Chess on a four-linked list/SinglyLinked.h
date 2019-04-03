#pragma once


#include <memory>


using std::shared_ptr;
using std::make_shared;


struct SinglyNode
{
	int i;
	int j;

	shared_ptr<SinglyNode> next;
	
	SinglyNode(int i, int j);
};


class SinglyLinked
{
private:
	shared_ptr<SinglyNode> head;
	shared_ptr<SinglyNode> tail;

	int length;

public:
	SinglyLinked();
	void pushBack(int i, int j);
	void popFront();
	void clear();
	int getSize();
	shared_ptr<SinglyNode> getHead();
};