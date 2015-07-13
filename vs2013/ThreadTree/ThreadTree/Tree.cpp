#include<iostream>  
using namespace std;

class ThreadTree;//线索二叉树  

class Thrnode
{
private:
	int data;
	int ltag;   //ltag为0:表示lchild为一般二叉树的指针，指向其左子树  
	int rtag;   //ltag为1:表示lchild为指向此结点的前驱的指针，rtag同理  
	Thrnode *lchild;
	Thrnode *rchild;

	friend class ThreadTree;
};

int num = 0;//记录结点数目  
struct Address      //辅助搜索  
{
	int data;
	Thrnode *p;
}ad[100];

class ThreadTree
{
private:
	Thrnode *root;
public:
	ThreadTree()
	{
		root = 0;
	}

	Thrnode *Get_Root()
	{
		return root;
	}

	int Get_data(Thrnode *p)
	{
		return p->data;
	}

	Thrnode *Create_Tree(Thrnode *r)    //先序建立二叉树  
	{
		int d;
		cout << "输入数据(0代表空)：";
		cin >> d;
		if (d == 0)
			return 0;
		else
		{
			num++;
			r = new Thrnode;
			r->ltag = 0;
			r->rtag = 0;
			r->data = d;
			r->lchild = Create_Tree(r->lchild);
			r->rchild = Create_Tree(r->rchild);
		}
		root = r;
		return r;
	}

	void In_Threading(Thrnode *p, Thrnode *&pre)
	{
		//以指针p所指向的二叉树进行中序遍历，遍历过程中进行线索化  
		//pre指针是p的前驱指针  
		if (p)
		{
			In_Threading(p->lchild, pre);//左子树线索化  
			if (!p->lchild) //若p的左子树为空，给p结点加前驱线索  
			{
				p->ltag = 1;
				p->lchild = pre;
			}
			else
				p->ltag = 0;
			if (pre && !pre->rchild)
			{
				pre->rtag = 1;
				pre->rchild = p;
			}
			pre = p;
			In_Threading(p->rchild, pre); //右子树线索化  
		}

	}

	Thrnode *InOrder_Threading(Thrnode *r) //将二叉树线索化，按中序遍历的顺序  
	{
		//遍历二叉树，并将其中序线索化，其中，Thrt指针指向头结点，r指向根节点  
		Thrnode *pre = NULL;
		Thrnode *Thrt;
		Thrt = new Thrnode;
		Thrt->ltag = 0;
		Thrt->rtag = 1;
		Thrt->rchild = Thrt;//初始化时，让头结点的右指针指向自己  
		if (!r)
			Thrt->lchild = Thrt;   //若为空树，左指针也指回自己  
		else
		{
			Thrt->lchild = r;
			pre = Thrt;
			In_Threading(r, pre);    //pre是r的前驱指针  

			//从上面的函数出来时，pre指在最后一个结点处  
			pre->rchild = Thrt;
			pre->rtag = 1;
			//最后一个结点的线索化  

			Thrt->rchild = pre;
		}
		cout << "二叉树线索化 完成~~" << endl;
		return Thrt;
	}

	void InOrder_Thr(Thrnode *Thrt) //中序遍历线索二叉树  
	{
		//遍历的同时，将相对应的值和结点指针存入结构体，便于搜索  
		int count = 0;
		Thrnode *r;
		r = Thrt->lchild;
		while (r != Thrt)
		{
			while (r->ltag == 0)
				r = r->lchild;
			cout << r->data << "  ";
			ad[count].data = r->data;
			ad[count].p = r;
			count++;
			while (r->rtag == 1 && r->rchild != Thrt)
			{
				r = r->rchild;
				cout << r->data << "  ";
				ad[count].data = r->data;
				ad[count].p = r;
				count++;
			}
			r = r->rchild;
		}
	}

	Thrnode *Search(int d)  //搜索  
	{
		for (int i = 0; i<num; i++)
			if (ad[i].data == d)
				return ad[i].p;
	}

	void Prior_Thr(Thrnode *Thrt, Thrnode *t, Thrnode *&p)  //求结点前驱  
	{
		//p返回结点t的前驱  
		p = t->lchild;
		if (p == Thrt)
		{
			cout << "给定的结点是第一个结点，不存在前驱" << endl;
			return;
		}
		if (t->ltag == 0)
			while (p->rtag == 0)
				p = p->rchild;
	}

	void Next_Thr(Thrnode *Thrt, Thrnode *t, Thrnode *&p) //求结点后继  
	{
		p = t->rchild;
		if (p == Thrt)
		{
			cout << "该结点为最后一个结点，无后继" << endl;
			return;
		}
		if (p->rtag == 0)
			while (p->ltag == 0)
				p = p->lchild;
	}

	void Insert_Lchild(Thrnode *Thrt, Thrnode *t, int d)  //作为左孩子插入  
	{
		/*
		将结点值为d的结点插入t后面，作为t的左孩子
		如果t本来的无左孩子，那么直接插入即可
		如果t有左孩子，那么：
		t的左孩子在新的节点q插入后，作为q的左孩子，因此q->ltag=0;
		将新结点q作为t的左孩子
		求出新的结点q的前驱，修改q的前驱结点的rchild域，使它的后继为q
		*/

		Thrnode *q = new Thrnode;
		q->data = d;

		q->lchild = t->lchild;
		q->ltag = t->ltag;

		q->rchild = t;
		q->rtag = 1;

		t->lchild = q;
		t->ltag = 0;

		if (q->ltag == 0)
		{
			Thrnode *p;
			Prior_Thr(Thrt, q, p);
			p->rchild = q;
		}
		//若q->rtag为0，那么就要找出q的前继  
		cout << "插入为结点值为：" << t->data << "的左孩子成功" << endl;
		num++;
	}

	void Insert_Rchild(Thrnode *Thrt, Thrnode *t, int d)  //作为右孩子插入  
	{
		//思路和上面的左孩子一样  
		Thrnode *q = new Thrnode;
		q->data = d;

		q->rchild = t->rchild;
		q->rtag = t->rtag;

		q->lchild = t;
		q->ltag = 1;

		t->rchild = q;
		t->rtag = 0;

		if (q->rtag == 0)
		{
			Thrnode *p;
			Next_Thr(Thrt, q, p);
			p->lchild = q;
		}
		cout << "插入为结点值：" << t->data << "的右孩子成功" << endl;
		num++;
	}

};