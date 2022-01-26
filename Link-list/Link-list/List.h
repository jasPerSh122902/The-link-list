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
	bool insert(const T& value, int index);
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
	for (int i = 0; i < m_nodeCount; i++)
	{
		delete Node;
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
	value = m_first
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	return false;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	return false;
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
