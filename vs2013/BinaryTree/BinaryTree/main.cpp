#include<iostream>
#include"BinaryTree.h"

using namespace std;

void main()
{
	BinaryTree A;
	BinaryTree B;
	int Array[] = { 7, 4, 2, 3, 15, 35, 6, 45, 55, 20, 1, 14, 56, 57, 58 };
	int k;
	k = sizeof(Array) / sizeof(Array[0]);
	cout << "½¨Á¢ÅÅÐò¶þ²æÊ÷Ë³Ðò: " << endl;
	for (int i = 0; i < k; i++)
	{
		cout << Array[i] << " ";
		A.create(Array[i]);
	}
	cout << endl;
	A.display1();
	cout << endl;
	A.display2();
	cout <<endl;
	A.display3();
	system("pause");
}