#ifndef EXERCISE
	#define EXERCISE

#include <iostream>
#include <algorithm>
using namespace std;

//5-2
//�ı��ά���鳤��
template <class T>
void changeLength2d(T**& a,int oldRows,int oldColumn,int newRowS,int newColumn)
{
	
	//������ά����
	T** temp = new T*[newRowS];
	for (int i = 0; i < newRowS; i++)
	{
		temp[i] = new T[newColumn];
	}

	int row = min(oldRows, newRowS);
	int column = min(oldColumn, newColumn);
	
	//��������
	for (int i = 0; i < row; i++)
	{
		copy(a[i], a[i] + column, temp[i]);
	}

	//�ͷ�ԭ����ռ�
	for (int i = 0; i < oldRows; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	//ָ��������
	a = temp;
	return;

}

#endif // !EXERCISE

