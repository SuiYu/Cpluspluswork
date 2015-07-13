#include<iostream>

class Node
{
public:
	Node()
	{
		next = NULL;
	};
	Node(int item , Node* ptr)
	{
		data = item;
		next = ptr;
	};

public:
	int data;
	Node* next;
};

class SqList
{
public:
	SqList();
	int length();
	bool add(int a);
	bool insert(int ad,int a);
	bool remove(int ad);
	int search(int a);
	bool isEmpty();
	void print();
	Node* locate(int ad);

private:
	Node head;
	int num=0;
	Node* p1 = &head;
	Node* p2 = &head;
};
