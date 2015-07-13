#include<iostream>
#include"SqList.h"

SqList::SqList()
{
	for (int i = 0; i < 10; i++)
	{
		p2 = new Node;
		p2->data = i;
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;

	}
	num = 10;
}

void SqList::print()
{
	Node *p=&head;
	while (p->next!=NULL)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

int SqList::length()
{
	return num;
}

bool SqList::isEmpty()
{
	if (num==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SqList::add(int a)
{
	p2 = new Node;
	p2->data = a;
	p2->next = NULL;
	p1->next = p2;
	p1 = p2;
	num++;
	print();
	return true;
}

Node* SqList::locate(int ad)
{
	Node* p = &head;
	for (int i = 0; i < ad; i++)
	{
		p = p->next;
	}
	return p;
}
bool SqList::remove(int ad)
{
	Node* p = locate(ad);
	Node* p2 = p->next->next;
	delete p->next;
	p->next = p2;
	num--;
	print();
	return true;
}

bool SqList::insert(int ad, int a)
{
	Node* p = locate(ad);
	Node* p2 = p->next;
	Node* t = new Node;
	t->data = a;
	t->next = p2;
	p->next = t;
	num++;
	print();
	return true;
}

int SqList::search(int a)
{
	Node* p = &head;
	int i = 1;
		while (p->next!=NULL)
		{
			if (p->data==a)
			{
				return i;
			}
			p=p->next;
			i++;
		}
		return false;
}

