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
	void destroy();//deletes all nodes in the list
	Iterator<T> begin()const;//returns an iterator pointing to the first node in the list
	Iterator<T> end()const;// returns the next item after the last node in the list
	 bool contain(const T object)const;//checks to see if the given item is in the list
	void pushFront(const T& value);//adds a new node to the beginning of the list
	void pushBack(const T& value);//adds a new node to the end of the list
	bool insert(const T& value, int
		index);//adds a new node at the given index
	bool remove(const T& value);//remove all nodes with the given value
	 void print()const;//prints the values for all the nodes
	void initialize();//set the default values for the first node pointer, the last node pointer, and the node count
	 bool isEmpty()const;// returns whether or not the list has any nodes in it
	bool getData(Iterator<T>& iter, int index);//sets the given iterator to point to a node at the given index
	int getLength()const;//returns the amount of nodes in the list
	const List<T>& operator =(const List<T>& otherList);
	void sort();


};

//the basic constructor for the list
template<typename T>
inline List<T>::List()
{
	m_first = nullptr;
	//exparemental the thing behind first is null
	m_first->previous = NULL;
	m_last = nullptr;
	//exparemental (meant to say that the next thing will be null
	m_last->next = NULL;
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

template<typename T>
inline void List<T>::destroy()
{
	for (Node<int>* m_nodeCount = m_first; m_nodeCount >  m_last; m_nodeCount++)
	{
		m_nodeCount = m_first->next;
		delete m_first;}

	initialize();
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	//Iterator<T>* m_iteratorPointer =new Iterator<T>;
	return /**m_iteratorPointer =*/ m_first;//makes the iterator pointer equal to the first.

}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return m_last->next;
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
	//Node<T>* next;
	//Node<T>* previous;
	//m_first->previous == &(Node<int>)value;
	Node<int> *node = new Node<int>(value);
	m_first->previous = node;
	node->next = m_first;
	m_first = node;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Node<T>* next;
	//Node<T>* previous;
	//m_last->next == &(Node<int>)value;
	Node<int>* node = new Node<int>(value);
	m_last->next = node;
	node->previous = m_last;
	m_last = node;
}

//add a if statment that allos for push back and push front to be seperat.
template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	index = m_nodeCount;
	//can i add pointer here 

	

	//is it a while loop or a for loop
	for (int i = value; i <= index; i++)
	{
		//also this needs some work
		pushBack(value);
		pushFront(value);
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
		//I dont have a arry that can be used that is m_items
		//need to make a m_items or somthing that is like it
		//delete pushFront();
		//delete pushBack();

		delete m_first;//delets the items array 
		*m_first = *newArray;//set the items to the new array
		m_nodeCount--;//decrement length
	}
	//Return whether or not the removal was successful
	return actorRemoved;
}

// there are errors
template<typename T>
inline void List<T>::print() const
{
	//The iter pointer may not work do figure this out
	for (Iterator<int> iter = begin(); iter != end(); iter++)
		std::cout << *iter << std::endl;
}

//there are errors
template<typename T>
inline void List<T>::initialize()
{
	//question here about how to set the m_first to the node coutner 
	m_first = m_nodeCount;	//set the m_fiest to the node counter at the index of 1
	for (m_nodeCount = 1; m_nodeCount == getLength(); m_nodeCount++)
	{
		//questioin is this corrent and if yes ask if there is a better way of doing this...
		m_last = m_nodeCount;//set the m_last to the last node counter index 
	}
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	for (Iterator<int> iter = begin(); iter != end(); iter++)
	{
		if (iter == nullptr || iter == NULL)
			return false;}
	return true;
}

//needs work I think
template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	for (int i = 1; i < index; i++)
	{
		index = i;
		return index;}
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

//needs ajustment
template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	return List(otherList);
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
}
