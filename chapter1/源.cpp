#include <iostream>
#include <iterator>
#include "currency.h"
using namespace std;

//ʹ�õݹ麯����������ģ��

//template <class	T>
//void permutations(T list[], int k, int m)
//{
//	if (k == m)		//����ݹ������������У�list[k:m]����һ�����������
//	{
//		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
//		cout << endl;
//	}
//	else//list[k:m]�ж���һ�����У��ݹ�������Щ����
//	{
//		for (int i = k; i <= m; i++)
//		{
//			swap(list[k], list[i]);		//����λ�����޸�ǰ׺
//			permutations(list, k + 1, m);
//			swap(list[k], list[i]);		//����ԭλ
//		}
//	}
//}

//�ǵݹ麯������n��
//template <class T>
//T factorial(int n)
//{
//	T sum = 1;
//	for (int i = 0; i <= n; i++)
//	{
//		if (i <= 1)
//		{
//			sum *= 1;
//		}
//		else
//		{
//			sum *= i;
//		}
//	}
//	return sum;
//}

//1-21 �ݹ麯��f(n)
//int func1_21(int n) {
//	if (n % 2 == 0)
//	{
//		return n/2;
//	}
//	else
//	{
//		func1_21(3 * n + 1);
//	}
//}

//1-27 
template <class T>
T accumulate(T* start, T* end, T value)
{
	T sum = value;
	for (T* i = start; i != end; i++)
	{
		sum += *i;
	}
	return sum;
}

int main()
{


	//1-17 1
	/*
	currency c1;
	c1.input();
	c1.output();*/

	//2
	/*currency c1, c2;
	c1.setValue(233.33);
	c2.setValue(233);
	c1.subtract(c2).output();*/

	//3
	//currency c1, c2;
	//c1.setValue(100);
	//c2 = c1.percent(12);
	//c2.output();

	//4,5
	/*currency c1, c2;
	c1.setValue(100);
	c2 = c1.multiply(12);
	c2.output();
	c2 = c1.divide(10);
	c2.output();*/

	//ʹ�õݹ麯����������
	/*char a[] = "abc";
	permutations(a, 0, 2);*/

	//1-19
	//cout << factorial<int>(15);

	//1-21
	/*cout << func1_21(7);*/

	//1-27
	/*int a[] = { 1,2,4 };
	cout << accumulate(a,a+3,0);*/
	return 0;
}