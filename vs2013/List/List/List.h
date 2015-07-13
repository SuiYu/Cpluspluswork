#include<iostream>

class List
{
public:
	List();
	bool add(int a);
	bool remove(int ad);
	bool insert(int ad,int a);
	int length();
	bool isEmpty();
	bool isFull();
	int search(int a);
	void print();
	void operator=(List L2);
private:
	int L[100];
	int num;
};

