#include <iostream>
#include <iterator>
#include "currency.h"
using namespace std;

//使用递归函数生成排列模板

//template <class	T>
//void permutations(T list[], int k, int m)
//{
//	if (k == m)		//到达递归基础，输出排列（list[k:m]仅有一个排列输出）
//	{
//		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
//		cout << endl;
//	}
//	else//list[k:m]有多于一个排列，递归生成这些排列
//	{
//		for (int i = k; i <= m; i++)
//		{
//			swap(list[k], list[i]);		//交换位置以修改前缀
//			permutations(list, k + 1, m);
//			swap(list[k], list[i]);		//换回原位
//		}
//	}
//}

//非递归函数计算n！
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

//1-21 递归函数f(n)
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

	//使用递归函数生成排列
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