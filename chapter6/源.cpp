#include <iostream>

using namespace std;
template<class T>
struct Node
{
	T date;
	Node<T>* next;
};

//1.递归删除单链表内所有含有x的结点
template <class T>
void deleteAllX(linkList<T>& a, T& x)
{
	Node<T>* temp;
	if (a == NULL)	//递归出口
	{
		return;
	}
	if (a->date == x)
	{
		temp = a;
		a = a->next;
		delete temp;
		deleteAllX(a, x);
	}
	else
	{
		deleteAllX(a->next, x);
	}
}

//2.
template<class T>
void deleteAllX_(linkList<T>& a, T& x)
{
	Node<T> *p = a->next, *pre = a,*temp;	//指向第一个结点

	while (p != NULL)
	{
		if (p->date == x)
		{
			pre->next = p->next;
			temp = p;
			p = p->next;
			delete temp;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

//3. 从尾到头输出链表
template <class T>
void R_print(linkList<T>& a)
{
	if (a->next != NULL)
	{
		R_print(a->next);
	}
	cout << a->date;
}

//4.删除节点值最小的结点
template<class T>
void deleteMin(linkList<T>& a)
{
	Node<T> *mp,*lmp, *pre = a, p = a->next;
	T min = p->date;
	while (p != NULL)
	{
		if (p->date < min)
		{
			min = p->date;
			mp = p;
			lmp = pre;
		}
		pre = p;
		p = p->next;
	}
	lmp->next = mp->next;
	delete mp;
}

//5.反转单链表结点	//摘出头结点，然后用头插法插入
template<class T>
void resever(linkList<T>& a)
{
	Node<T> *p = a->next,*r;
	a->next = NULL;
	while (p != NULL)
	{
		r = p->next;
		p->next = a->next;
		a->next = p;
		p = r;
	}
	return a;
}
int main()
{
	return 0;
}