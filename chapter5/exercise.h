#ifndef EXERCISE
	#define EXERCISE

#include <iostream>
#include <algorithm>
using namespace std;

//5-2
//改变二维数组长度
template <class T>
void changeLength2d(T**& a,int oldRows,int oldColumn,int newRowS,int newColumn)
{
	
	//创建二维数组
	T** temp = new T*[newRowS];
	for (int i = 0; i < newRowS; i++)
	{
		temp[i] = new T[newColumn];
	}

	int row = min(oldRows, newRowS);
	int column = min(oldColumn, newColumn);
	
	//复制数据
	for (int i = 0; i < row; i++)
	{
		copy(a[i], a[i] + column, temp[i]);
	}

	//释放原数组空间
	for (int i = 0; i < oldRows; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	//指向新数组
	a = temp;
	return;

}

#endif // !EXERCISE

