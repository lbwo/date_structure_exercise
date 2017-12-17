// array implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented
// USES STL ALGORITHMS TO SIMPLIFY CODE

#ifndef arrayList_
#define arrayList_

#include<iostream>
#include<iterator>
#include<sstream>
#include<string>
#include<algorithm>
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

using namespace std;

template<class T>
class arrayList : public linearList<T> 
{
   public:
      // constructor, copy constructor and destructor
      arrayList(int initialCapacity = 10);
      arrayList(const arrayList<T>&);
      ~arrayList() {delete [] element;}

      // ADT methods
      bool empty() const {return listSize == 0;}
      int size() const {return listSize;}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;

      // additional method
      int capacity() const {return arrayLength;}
	  //5-7 
	  //overlord []
	  T& operator[](int i)
	  {
		  if (i >= arrayLength)
		  {
			  ostringstream s;
			  s << "argument number > arraylist length!";
			  throw illegalParameterValue(s.str());
		  }
		  return element[i];
		}

	  //5-8
	  //overlord ==
	  bool operator==(const arrayList<T> a)
	  {
		  if (a.listSize != listSize)
		  {
			  return false;
		  }
		  for (int i = 0; i < listSize; i++)
		  {
			  if (element[i] != a[i])
			  {
				  return false;
			  }
		  }
		  return true;
	  }

	  //5-9
	  //overlord !=
	  bool operator!=(const arrayList<T> a)
	  {
		  return !(*this == a);
	  }

	  //5-11
	  void push_back(const T& a);

	  //5-13
	  void swap(arrayList<T>& a);

	  //5-15
	  T& set(int index, const T& a);

	  //5-17
	  void removeRange(int start, int end);

	  //5-23
	  void leftShift(int i);

	  //5-25
	  void half();
   protected:
      void checkIndex(int theIndex) const;
            // throw illegalIndex if theIndex invalid
      T* element;            // 1D array to hold list elements
      int arrayLength;       // capacity of the 1D array
      int listSize;          // number of elements in list
};

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{// Constructor.
   if (initialCapacity < 1)
   {ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
   }
   arrayLength = initialCapacity;
   element = new T[arrayLength];
   listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{// Copy constructor.
   arrayLength = theList.arrayLength;
   listSize = theList.listSize;
   element = new T[arrayLength];
   copy(theList.element, theList.element + listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }

}

template<class T>
T& arrayList<T>::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);
   return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.

   // search for theElement
   int theIndex = (int) (find(element, element + listSize, theElement)
                         - element);

   // check if theElement was found
   if (theIndex == listSize)
     // not found
     return -1;
   else return theIndex;
 }

template<class T>
void arrayList<T>::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);

   // valid index, shift elements with higher index
   copy(element + theIndex + 1, element + listSize,
                                element + theIndex);

   element[--listSize].~T(); // invoke destructor
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > listSize)
   {// invalid index
      ostringstream s;
      s << "index = " << theIndex << " size = " << listSize;
      throw illegalIndex(s.str());
   }

   // valid index, make sure we have space
   if (listSize == arrayLength)
      {// no space, double capacity
         changeLength1D(element, arrayLength, 2 * arrayLength);
         arrayLength *= 2;
      }

   // shift elements right one position
   copy_backward(element + theIndex, element + listSize,
                 element + listSize + 1);

   element[theIndex] = theElement;

   listSize++;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{// Put the list into the stream out.
   copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
   {x.output(out); return out;}

//5-11
template <class T>
void arrayList<T>::push_back(const T& a)
{
	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	element[listSize] = a;
	listSize++;
	return;
}

//5-13
//交换两个线性表的元素
template<class T>
void arrayList<T>::swap(arrayList<T>& a)
{
	swap(arrayLength, a.arrayLength);
	swap(listSize, a.listSize);
	swap(element, a.element);
	return;
}

//5-15
template<class T>
T& arrayList<T>::set(int index, const T& a)
{
	checkIndex(index);
	T temp = element[index];
	element[index] = a;
	return temp;
}

//5-17
template<class T>
void arrayList<T>::removeRange(int start, int end)
{
	if (start <0 || end >listSize)
	{
		throw illegalIndex();
	}
	if (start > end)
	{
		return;
	}
	copy(element + end, element + listSize, element + start);
	int newSize = listSize - end + start;
	for (int i = newSize; i < listSize; i++)
	{
		element[i].~T();
	}
	listSize = newSize;
	return;
}

//5-23
//左移i个元素
template<class T>
void arrayList<T>::leftShift(int i)
{
	if (i < 0)
	{
		throw illegalIndex("i must be >= 0");
	}
	int  newSize = 0;
	if (i < listSize)
	{
		copy(element + i, element + listSize, element);
		newSize = listSize - i;
	}
	for (int i = newSize; i < listSize; i++)
	{
		element[i].~T();
	}
	listSize = newSize;
	return;
}

//5-25
//x的元素隔一个删除一个
template<class T>
void arrayList<T>::half()
{

	int newSize = ceil((double)listSize / 2);
	T* temp = new T[newSize];
	for (int i=0,j = 0; i < newSize; i++,j=j+2)
	{
		temp[i] = element[j];
	}
	delete[] element;
	element = temp;
	listSize = newSize;
	return;
}
#endif
