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

	//5-7
	/*arrayList<int> a;
	a[1] = 1;
	int b = a[1];
	cout << a[1]<<b;
	*/

	//5-8 5-9
	/*arrayList<int> a, b(20);
	a.insert(0, 1);
	b.insert(0, 1);
	cout << (a == b);
	cout << (a != b);
	*/

	//5-11
	/*arrayList<int> a;
	a.push_back(1);
	cout<<a[0];*/
	
	//5-15
	/*arrayList<int> a(10);
	a.insert(0, 1);
	
	cout << a.set(0, 3);
	cout << a[0];*/

	//5-23
	/*arrayList<int> a(10);
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
	}
	a.output(cout);
	a.leftShift(2);
	a.output(cout);*/

	//5-25
	/*arrayList<int> a(7);
	a.push_back(2);
	a.push_back(13);
	a.push_back(4);
	a.push_back(5);
	a.push_back(17);
	a.push_back(8);
	a.push_back(29);
	a.output(cout);
	a.half();
	cout << endl;
	a.output(cout);*/
	return 0;
}