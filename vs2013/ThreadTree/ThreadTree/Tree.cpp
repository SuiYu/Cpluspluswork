#include<iostream>  
using namespace std;

class ThreadTree;//����������  

class Thrnode
{
private:
	int data;
	int ltag;   //ltagΪ0:��ʾlchildΪһ���������ָ�룬ָ����������  
	int rtag;   //ltagΪ1:��ʾlchildΪָ��˽���ǰ����ָ�룬rtagͬ��  
	Thrnode *lchild;
	Thrnode *rchild;

	friend class ThreadTree;
};

int num = 0;//��¼�����Ŀ  
struct Address      //��������  
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

	Thrnode *Create_Tree(Thrnode *r)    //������������  
	{
		int d;
		cout << "��������(0�����)��";
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
		//��ָ��p��ָ��Ķ���������������������������н���������  
		//preָ����p��ǰ��ָ��  
		if (p)
		{
			In_Threading(p->lchild, pre);//������������  
			if (!p->lchild) //��p��������Ϊ�գ���p����ǰ������  
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
			In_Threading(p->rchild, pre); //������������  
		}

	}

	Thrnode *InOrder_Threading(Thrnode *r) //���������������������������˳��  
	{
		//���������������������������������У�Thrtָ��ָ��ͷ��㣬rָ����ڵ�  
		Thrnode *pre = NULL;
		Thrnode *Thrt;
		Thrt = new Thrnode;
		Thrt->ltag = 0;
		Thrt->rtag = 1;
		Thrt->rchild = Thrt;//��ʼ��ʱ����ͷ������ָ��ָ���Լ�  
		if (!r)
			Thrt->lchild = Thrt;   //��Ϊ��������ָ��Ҳָ���Լ�  
		else
		{
			Thrt->lchild = r;
			pre = Thrt;
			In_Threading(r, pre);    //pre��r��ǰ��ָ��  

			//������ĺ�������ʱ��preָ�����һ����㴦  
			pre->rchild = Thrt;
			pre->rtag = 1;
			//���һ������������  

			Thrt->rchild = pre;
		}
		cout << "������������ ���~~" << endl;
		return Thrt;
	}

	void InOrder_Thr(Thrnode *Thrt) //�����������������  
	{
		//������ͬʱ�������Ӧ��ֵ�ͽ��ָ�����ṹ�壬��������  
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

	Thrnode *Search(int d)  //����  
	{
		for (int i = 0; i<num; i++)
			if (ad[i].data == d)
				return ad[i].p;
	}

	void Prior_Thr(Thrnode *Thrt, Thrnode *t, Thrnode *&p)  //����ǰ��  
	{
		//p���ؽ��t��ǰ��  
		p = t->lchild;
		if (p == Thrt)
		{
			cout << "�����Ľ���ǵ�һ����㣬������ǰ��" << endl;
			return;
		}
		if (t->ltag == 0)
			while (p->rtag == 0)
				p = p->rchild;
	}

	void Next_Thr(Thrnode *Thrt, Thrnode *t, Thrnode *&p) //������  
	{
		p = t->rchild;
		if (p == Thrt)
		{
			cout << "�ý��Ϊ���һ����㣬�޺��" << endl;
			return;
		}
		if (p->rtag == 0)
			while (p->ltag == 0)
				p = p->lchild;
	}

	void Insert_Lchild(Thrnode *Thrt, Thrnode *t, int d)  //��Ϊ���Ӳ���  
	{
		/*
		�����ֵΪd�Ľ�����t���棬��Ϊt������
		���t�����������ӣ���ôֱ�Ӳ��뼴��
		���t�����ӣ���ô��
		t���������µĽڵ�q�������Ϊq�����ӣ����q->ltag=0;
		���½��q��Ϊt������
		����µĽ��q��ǰ�����޸�q��ǰ������rchild��ʹ���ĺ��Ϊq
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
		//��q->rtagΪ0����ô��Ҫ�ҳ�q��ǰ��  
		cout << "����Ϊ���ֵΪ��" << t->data << "�����ӳɹ�" << endl;
		num++;
	}

	void Insert_Rchild(Thrnode *Thrt, Thrnode *t, int d)  //��Ϊ�Һ��Ӳ���  
	{
		//˼·�����������һ��  
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
		cout << "����Ϊ���ֵ��" << t->data << "���Һ��ӳɹ�" << endl;
		num++;
	}

};