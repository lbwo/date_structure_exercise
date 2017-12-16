#include "exercise.h"
#include "arrayList.h"

//5-5
//template <class T>
//class arrayWithTrimToSize :public arrayList<T>
//{
//	public:
//		arrayWithTrimToSize(int initialCapacity = 10) :arrayList<T>(initialCapacity) {};
//		void trimToSize();
//};
//
//template <class T>
//void arrayWithTrimToSize<T>::trimToSize()
//{
//	if (arrayLength == listSize)
//	{
//		return;
//	}
//	if (listSize == 0)
//	{
//		delete[] element;
//		element = new T[1];
//		arrayLength = 1;
//		return;
//	}
//	changeLength1D(element, arrayLength, listSize);
//	arrayLength = listSize;
//	return;
//}
int main()
{
	//5-2
	/*int oldRows = 3, oldColumns = 3;
	int newRows = 4, newColumns = 4;
	int** a = new int*[oldRows];
	for (int i = 0; i < oldRows; i++)
	{
		a[i] = new int[oldColumns];
	}
	for (int i = 0; i < oldRows; i++)
	{
		for (int j = 0; j < oldColumns; j++)
		{
			a[i][j] = i + j;
		}
	}
	changeLength2d(a, oldRows, oldColumns, newRows, newColumns);
	for (int i = 0; i < newRows; i++)
	{
		for (int j = 0; j < newColumns; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}*/

	//5-5
	//arrayWithTrimToSize<int> a(10);
	//cout << "before:" << a.capacity()<<endl;
	//a.trimToSize();
	//cout << "after:" << a.capacity() << endl;


	return 0;
}