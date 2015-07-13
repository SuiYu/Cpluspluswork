#include<iostream>

class Node
{
public:
	Node(){left = NULL; right = NULL; };
	int data;
	Node* left;
	Node* right;
};

class BinaryTree
{
public:
	void create(int x);
	void Preorder(Node *);
	void Inorder(Node *);
	void Postorder(Node *);
	void display1(){ Preorder(root); };
	void display2(){ Inorder(root); };
	void display3(){ Postorder(root); };

public:
	Node* root=NULL;
};

