// vector implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented
// USES STL ALGORITHMS TO SIMPLIFY CODE
// iterator class for vectorList included

#ifndef vectorList_
#define vectorList_

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include "linearList.h"
#include "myExceptions.h"

using namespace std;

template<class T>
class vectorList : public linearList<T> 
{
   public:
      // constructor, copy constructor and destructor
      vectorList(int initialCapacity = 10);
      vectorList(const vectorList<T>&);
      ~vectorList() {delete element;}

      // ADT methods
      bool empty() const {return element->empty();}
      int size() const {return (int) element->size();}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;
	  //5-37
	  void half();

	  //5-39
	  void merge(const vectorList<T>& a, const vectorList<T>& b);

      // additional method
      int capacity() const {return (int) element->capacity();}
      
      // iterators to start and end of list
      typedef typename vector<T>::iterator iterator;
      iterator begin() {return element->begin();}
      iterator end() {return element->end();}

   protected:  // additional members of vectorList
      void checkIndex(int theIndex) const;
      vector<T>* element;     // vector to hold list elements
};

template<class T>
vectorList<T>::vectorList(int initialCapacity)
{// Constructor.
   if (initialCapacity < 1)
   {ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
   }

   element = new vector<T>;
            // create an empty vector with capacity 0
   element->reserve(initialCapacity);
            // increase vector capacity from 0 to initialCapacity
}

template<class T>
vectorList<T>::vectorList(const vectorList<T>& theList)
{// Copy constructor.
   element = new vector<T>(*theList.element);
}

template<class T>
void vectorList<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and size() - 1.
   if (theIndex < 0 || theIndex >= size())
   {ostringstream s;
    s << "index = " << theIndex << " size = " << size();
    throw illegalIndex(s.str());
   }

}

template<class T>
T& vectorList<T>::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);
   return (*element)[theIndex];
}

template<class T>
int vectorList<T>::indexOf(const T& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.

   // search for theElement
   int theIndex = (int) (find(element->begin(), element->end(),
                         theElement)
                         - element->begin());

   // check if theElement was found
   if (theIndex == size())
     // not found
     return -1;
   else return theIndex;
 }

template<class T>
void vectorList<T>::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);
   element->erase(begin() + theIndex);
}

template<class T>
void vectorList<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > size())
   {// invalid index
      ostringstream s;
      s << "index = " << theIndex << " size = " << size();
      throw illegalIndex(s.str());
   }

   element->insert(element->begin() + theIndex, theElement);
           // may throw an uncaught exception if insufficient
           // memory to resize vector
}

template<class T>
void vectorList<T>::output(ostream& out) const
{// Put the list into the stream out.
   copy(element->begin(), element->end(), ostream_iterator<T>(cout, "  "));
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const vectorList<T>& x)
   {x.output(out); return out;}

//5-37
//将数组中的元素隔一个删除一个
template<class T>
void vectorList::half()
{
	int size = element->size();
	for (int i = 2; i < size; i += 2)
	{
		(*element)[i/2] = (*element)[i];
	}
	int newSize = (size + 1) / 2;
	element->erase(element->begin() + newSize, element->end());
	return;
}

//5-39
//合并升序数组
template<class T>
void vectorList<T>::merge(const vectorList<T>& a, const vectorList<T>& b)
{
	iterator ia = a.begin();
	iterator aend = a.end();
	iterator ib = b.begin();
	iterator bend = b.end();

	element = new vector<T>;
	
	while ((ia < aend) && (ib < bend))
	{
		if (*(ia) <= *(ib))
		{
			element->push_back(*ia);
			ia++;
		}
		else
		{
			element->push_back(*ib)
				ib++
		}
	}
	element->insert(element->end(), ia, aend);
	element->insert(element->end(), ib, bend);
	return;
}
#endif
