#include"tree.h"  

int main()
{
	ThreadTree t;
	Thrnode *r = t.Get_Root(), *k;
	k = t.Create_Tree(r);

	cout << "_____二叉树线索化_____" << endl;
	Thrnode *Thrt = 0;
	Thrt = t.InOrder_Threading(k);

	if (Thrt)
	{
		cout << "中序遍历线索二叉树为：";
		t.InOrder_Thr(Thrt);
		cout << endl;
	}

	int data1, data2;
	cout << "输入你要在值为多少的结点处插入作为其左孩子：";
	cin >> data1;
	Thrnode *p = 0;
	p = t.Search(data1);
	if (!p)
		cout << "找不到插入点" << endl;
	else
	{
		cout << "要插入的结点地址为：" << p << endl;
		cout << t.Get_data(p) << endl;

		cout << "输入你要插入的新结点的值：";
		cin >> data2;
		cout << "____将新结点插入为左孩子____" << endl;
		t.Insert_Lchild(Thrt, p, data2);
	}

	cout << "中序遍历二叉树为：";
	t.InOrder_Thr(Thrt);
	cout << endl;

	int data3, data4;
	cout << "输入你要在值为多少的结点处插入作为其右孩子：";
	cin >> data3;
	Thrnode *f = 0;
	f = t.Search(data3);
	if (!f)
		cout << "找不到插入点" << endl;
	else
	{
		cout << "要插入的结点地址为：" << f << endl;
		cout << t.Get_data(f) << endl;
		cout << "输入你要插入的新结点的值：";
		cin >> data4;
		cout << "____将新结点插入为右孩子____" << endl;
		t.Insert_Rchild(Thrt, f, data4);
	}

	cout << "中序遍历二叉树为：";
	t.InOrder_Thr(Thrt);
	cout << endl;

	cout << "结点值为：" << data1 << "的前驱结点值为：";
	Thrnode *s = new Thrnode;
	t.Prior_Thr(Thrt, p, s);
	cout << t.Get_data(s) << endl;

	cout << "结点值为：" << data3 << "的后继结点值为：";
	Thrnode *x = new Thrnode;
	f = t.Search(data3);
	t.Next_Thr(Thrt, f, x);
	cout << t.Get_data(x) << endl;

	return 0;
}