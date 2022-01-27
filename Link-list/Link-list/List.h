#pragma once
#include "Iterator.h"
#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>

class List
{
private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
public:
	List();
	List(const List<T>&);
	~List();
	void destroy();
	Iterator<T> begin()const;
	Iterator<T> end()const;
	 bool contain(const T object)const;
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int
		index);
	bool remove(const T& value);
	 void print()const;
	void initialize();
	 bool isEmpty()const;
	bool getData(Iterator<T>& iter, int index);
	int getLength()const;
	const List<T>& operator =(const List<T>& otherList);
	void sort();

};

//the basic constructor for the list
template<typename T>
inline List<T>::List()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline List<T>::List(const List<T>&)
{}

template<typename T>
inline List<T>::~List()
{
	delete m_first;
	delete m_last;
}


//there is a error on the Node delete
template<typename T>
inline void List<T>::destroy()
{
	for (int i = m_first; i <= m_last; i++)
	{
		delete m_nodeCount;
	}
}

//makes the iterator pointer equal to the first.
template<typename T>
inline Iterator<T> List<T>::begin() const
{
	Iterator<T>* m_iteratorPointer = new Iterator<T>;
	m_iteratorPointer->operator==(m_first);
	return m_first;
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	Iterator<T>* m_iteratorPointer = new Iterator<T>;
	m_iteratorPointer->operator-- == m_last;
	return m_last;
}

template<typename T>
inline bool List<T>::contain(const T object) const
{
	if (!object || m_nodeCount <= 0)
		return false;
	return true;
}

//error but did not start this one
template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//T* next;
	//T* previous;
	//can i add pointer here
	value = m_first
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//T* next;
	//T* previous;
	//can i add pointer here
	for (value = index; value)

}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	index = m_nodeCount;
	//can i add pointer here 

	//is it a while loop or a for loop
	for (int i = value; i <= index; i++)
	{
		//also this needs some work
		pushBack(value[i]);
		pushFront(value[i]);
	}
	return false;

}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Check to see if the actor was null
	if (!value || getLength() <= 0)
		return false;

	bool actorRemoved = false;
	//Create a new array with a size one less than our old array
	T* newArray = new T[getLength() - 1];
	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
	{
		//if the values are the same or the actor has been removed...
		if (value != m_nodeCount[i] || actorRemoved)
		{
			newArray[j] = m_nodeCount[i];//print that actor and...
			j++;//increament j
		}
		else
			actorRemoved = true;
	}
	//Set the old array to the new array
	if (actorRemoved)//if actor removed == true
	{
		//I dont havbe a arrya that can be used that is m_items
		//need to make a m_items or somthing taht is like it
		//delet pushFront();
		//delete pushBack();
		delete[] m_items;//delets the items array 
		m_items = newArray;//set the items to the new array
		m_nodeCount--;//decrement length
	}
	//Return whether or not the removal was successful
	return actorRemoved;
}

//change this but yes there are errors
template<typename T>
inline void List<T>::print() const
{
	for (int i = 0; i < m_nodeCount; i++)
		std::cout << m_nodeCount->getItem(i) << std::endl;
}

template<typename T>
inline void List<T>::initialize()
{
	//question here about how to set the m_first to the node coutner 
	m_first == m_nodeCount[1];//set the m_fiest to the node counter at the index of 1
	for (m_nodeCount = 1; m_nodeCount == getLength(); m_nodeCount++)
	{
		//questioin is this corrent and if yes ask if there is a better way of doing this...
		m_last == m_nodeCount;//set the m_last to the last node counter index 
	}
}

//there is errors
template<typename T>
inline bool List<T>::isEmpty() const
{
	if (m_first == nullptr && m_last = nullptr)
		return false;
	return true;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	for (index = 1; index < getLength(); index++)
	{
		iter == index;
		return iter;
	}
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	// TODO: insert return statement here
}

//error on the c and d
template<typename T>
inline void List<T>::sort()
{
	int c, b;
	T temp;

	for (c = 0; c < 4; c++)
	{
		for (b = c + 1; b < 4; b++)
		{
			//have to change the c and b
			if (m_nodeCount[b] < m_nodeCount[c])
			{
				temp = m_nodeCount[c];
				m_nodeCount[c] = m_nodeCount[b];
				m_nodeCount[b] = temp;
			}
		}
	}
	cout << "Sorted Element List ...\n";
	for (c = 0; c < 4; c++)
		cout << m_nodeCount[c] << "\t";
}
