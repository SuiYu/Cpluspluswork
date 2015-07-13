#include<iostream>
#include"BinaryTree.h"
void BinaryTree::create(int x)
{
	Node* p = new Node;
	p->data = x;
	//std::cout << p->data;
	if (root==NULL)
	{
		root = p;
		//std::cout << "nice";
	}
	else
	{
		Node* back = root;
		Node* current = root;
		while (current != NULL)
		{
			if (current->data>=x)
			{
				//std::cout << "@";
				back = current;
				current = current->left;
			}
			else
			{
				//std::cout << "$";
				back = current;
				current = current->right;
			}
		}
		if (back->data>=x)
		{
			back->left = p;
		}
		else
		{
			back->right = p;
		}
	}
}

void BinaryTree::Preorder(Node* temp)
{
	if (temp != NULL)
	{
		std::cout << temp->data<<" ";
		Preorder(temp->left);
		Preorder(temp->right);
	}
}

void BinaryTree::Inorder(Node* temp)
{
	if (temp!=NULL)
	{
		Inorder(temp->left);
		std::cout << temp->data << " ";
		Inorder(temp->right);
	}
}

void BinaryTree::Postorder(Node* temp)
{
	if (temp!=NULL)
	{
		Postorder(temp->left);
		Postorder(temp->right);
		std::cout << temp->data << " ";
	}
}

