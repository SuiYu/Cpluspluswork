#include<iostream>
#include "List.h"

List::List()
{
	for (int i = 0; i < 10; i++)
	{
		L[i] = i + 1;
	}
	num = 10;
}
void List::print()
{
	for (int i = 0; i < num; i++)
	{
		std::cout << L[i]<<" ";
	}
	std::cout << '\n'<<num;
}
bool List::add(int a)
{
	if (isFull())
	{
		return false;
	}
	L[num] = a;
	num++;
	print();
	return true;
}
bool List::insert(int ad, int a)
{
	if (isFull())
	{
		return false;
	}
	for (int i = num; i >= ad; i--)
	{
		L[i] = L[i - 1];
	}
	num++;
	L[ad - 1] = a;
	print();
	return true;
}
bool List::isEmpty()
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
bool List::isFull()
{
	if (num == 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool List::remove(int ad)
{
	if (isEmpty())
	{
		return false;
	}
	for (int i = ad-1; i < num; i++)
	{
		L[i] = L[i + 1];
	}
	num--;
	print();
	return true;
}
int List::search(int a)
{
	for (int i = 0; i < num; i++)
	{
		if (L[i]==a)
		{
			return i;
		}
	}

	return -1;
}
void List::operator=(List L2)
{
	for (int i = 0; i < L2.num; i++)
	{
		L[i] = L2.L[i];
	}
	num = L2.num;
}