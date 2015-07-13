#include<iostream>
#include"Stack.h"

Stack::Stack()
{
	for (int i = 0; i < 10; i++)
	{
		St[i] = i + 1;
	}
	top = 10;
}

void Stack::print()
{
	for (int i = 0; i < top; i++)
	{
		std::cout << St[i] << " ";
	}
	std::cout << std::endl;
}
void Stack::push(int a)
{
	St[top] = a;
	top++;
	print();
}
void Stack::pop()
{
	std::cout << St[--top] << std::endl;
	print();
}

