#include<iostream>
#include"List.h"

using namespace std;

void main()
{
	List a;
	a.print();
	a.add(7);
	a.insert(2, 1000);
	a.remove(3);
	cout << '\n';
	List b;
	a = b;
	a.print();
	system("pause");
}