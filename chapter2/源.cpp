#include <iostream>

using namespace std;

//2-9
//��������Ԫ������
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
//һ��ð�ݹ���
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
//��������
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
//��ʱ��ֹѡ������
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
				sort = false;//��һ�ζ�û����˵������������ģ����˳�ѭ��;			
			}
		}
		if (i != indexOfMax)
		{
			swap(a[i], a[indexOfMax]);
		}	
	}
	return;
}

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


	return 0;
}