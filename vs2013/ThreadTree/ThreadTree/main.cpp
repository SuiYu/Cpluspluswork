#include"tree.h"  

int main()
{
	ThreadTree t;
	Thrnode *r = t.Get_Root(), *k;
	k = t.Create_Tree(r);

	cout << "_____������������_____" << endl;
	Thrnode *Thrt = 0;
	Thrt = t.InOrder_Threading(k);

	if (Thrt)
	{
		cout << "�����������������Ϊ��";
		t.InOrder_Thr(Thrt);
		cout << endl;
	}

	int data1, data2;
	cout << "������Ҫ��ֵΪ���ٵĽ�㴦������Ϊ�����ӣ�";
	cin >> data1;
	Thrnode *p = 0;
	p = t.Search(data1);
	if (!p)
		cout << "�Ҳ��������" << endl;
	else
	{
		cout << "Ҫ����Ľ���ַΪ��" << p << endl;
		cout << t.Get_data(p) << endl;

		cout << "������Ҫ������½���ֵ��";
		cin >> data2;
		cout << "____���½�����Ϊ����____" << endl;
		t.Insert_Lchild(Thrt, p, data2);
	}

	cout << "�������������Ϊ��";
	t.InOrder_Thr(Thrt);
	cout << endl;

	int data3, data4;
	cout << "������Ҫ��ֵΪ���ٵĽ�㴦������Ϊ���Һ��ӣ�";
	cin >> data3;
	Thrnode *f = 0;
	f = t.Search(data3);
	if (!f)
		cout << "�Ҳ��������" << endl;
	else
	{
		cout << "Ҫ����Ľ���ַΪ��" << f << endl;
		cout << t.Get_data(f) << endl;
		cout << "������Ҫ������½���ֵ��";
		cin >> data4;
		cout << "____���½�����Ϊ�Һ���____" << endl;
		t.Insert_Rchild(Thrt, f, data4);
	}

	cout << "�������������Ϊ��";
	t.InOrder_Thr(Thrt);
	cout << endl;

	cout << "���ֵΪ��" << data1 << "��ǰ�����ֵΪ��";
	Thrnode *s = new Thrnode;
	t.Prior_Thr(Thrt, p, s);
	cout << t.Get_data(s) << endl;

	cout << "���ֵΪ��" << data3 << "�ĺ�̽��ֵΪ��";
	Thrnode *x = new Thrnode;
	f = t.Search(data3);
	t.Next_Thr(Thrt, f, x);
	cout << t.Get_data(x) << endl;

	return 0;
}