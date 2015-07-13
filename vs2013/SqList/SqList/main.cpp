#include<iostream>
#include"SqList.h"

using namespace std;

void main()
{
	SqList a;
	a.print();
	a.insert(2, 100);
	a.add(100);
	a.remove(1);
	cout << a.search(100)<<endl;
	system("pause");
}