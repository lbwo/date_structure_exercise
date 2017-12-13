#include <iostream>

using namespace std;

//2-9
//计算所有元素名次
template <class T>
void countRank(T a[], int n, int r[])
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] <= a[i])
			{
				r[i]++;
			}
			else
			{
				r[j]++;
			}
		}
	}
	return;
}

//2-11
//一次冒泡过程
template<class T>
void bubbleSort(T a[], int n)	
{
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] > a[i + 1])
		{
			swap(a[i], a[i + 1]);
		}
	}
	return;
}

//2-13
//插入排序
template<class T>
void insertSort(T a[], int &n, const T& x)
{
	int i;
	for ( i = n - 1; i >= 0 && a[i] > x; i--)
	{
		a[i + 1] = a[i];
	}
	a[i + 1] = x;
	n++;
	return;
}

//2-15
//及时终止选择排序
template<class T>
void selectSort(T a[],int n)
{
	bool sort = false;
	for(int i=n-1;i>1 && !sort;i--)
	{
		int indexOfMax =0;
		sort = true;
		for (int j = 1; j < i; j++)			
		{
			if (a[indexOfMax] <= a[j])		
			{
				indexOfMax = j;
			}
			else
			{
				sort = false;//若一次都没设置说明数组是有序的，可退出循环;			
			}
		}
		if (i != indexOfMax)
		{
			swap(a[i], a[indexOfMax]);
		}	
	}
	return;
}

//矩阵乘法
template<class T>
void matrixMutiply(T **a, T **b, T **c, int m, int n, int p)
{
	for (int i = 0; i < n; i++)		//固定行
	{
		for (int j = 0; j < p; j++) //固定列
		{
			T sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
		}
	}
	return;
}

//2-27
//void d(int x[], int n)
//{
//	int step = 0;
//	for (int i = 0; i < n; i += 2)
//	{
//		step++;
//		x[i] += 2;
//		step++;
//	}
//	step++;
//	int i = 1;
//	step++;
//	while (i <= n / 2)
//	{
//		step++;
//		x[i] += x[i + 1];
//		step++;
//		i++;
//		step++;
//	}
//	step++;
//	cout << step;
//	return;
//}
int main()
{
	//2-9
	/*
	int a[] = { 3,2,6,5,9,4,7,1,8 };
	int r[9] = {0};
	countRank(a, 9, r);
	for (int i = 0; i < 9; i++)
	{
		cout << r[i] << '\t';
	}
	*/

	//2-11
	/*int a[] = { 3,2,6,5,9,4,8 };
	int n = sizeof(a) / sizeof(a[0]);
	bubbleSort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}*/


	//2-13
	/*int a[8] = { 1,2,4,6,7,8,9 };
	int n = 7;
	insertSort(a, n, 3);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}*/

	//2-15
	/*int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	selectSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << '\t';
	}*/

	//2-27
	/*int a[] = { 1,2,3,4,5,6,7 };
	d(a, 7);*/
	
	return 0;
}