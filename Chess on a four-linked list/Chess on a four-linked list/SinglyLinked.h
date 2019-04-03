#pragma once


struct SinglyNode
{
	int i;
	int j;
	SinglyNode *next = nullptr;
	SinglyNode(int iForStruct, int jForStruct);
};


class SinglyLinked
{
private:
	SinglyNode *head = nullptr;
	SinglyNode *tail = nullptr;
	int length;

public:
	SinglyLinked();
	void pushBack(int i, int j);
	void popFront();
	void clear();
	int getSize();
	SinglyNode *getHead();
};