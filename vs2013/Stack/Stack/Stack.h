#include<iostream>

class Stack
{
public:
	Stack();
	void  push(int a);
	void pop();
	void print();

private:
	int St[100];
	int top = 0;
	int bottom = 0;
};
