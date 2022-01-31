#pragma once
#include "Iterator.h"
#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>
class List {
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
	void sortItem();
};

//the basic constructor for the list
template<typename T>
inline List<T>::List()
{
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& otherList)
{
	m_first = otherList.m_first;
	m_last = otherList.m_last;
	m_nodeCount = otherList.m_nodeCount;
}

template<typename T>
inline List<T>::~List()
{
	destroy();
}

template<typename T>
inline void List<T>::destroy()
{
	//makes nodecount = to first and if node counter is not null
	for (Node<int>* m_nodeCount = m_first; m_nodeCount != nullptr;)
	{
		//makes a temp node and assigns it the node count
		Node<T>* tempNode = m_nodeCount;
		m_nodeCount = m_nodeCount->next; // maes node count = to the next
		delete tempNode; // delete that temp node
	}
	initialize();
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return m_first;
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return m_last;//return a null
}

template<typename T>
inline bool List<T>::contain(const T object) const
{
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		if (*iter == object)
			return true;
	}
	return false;
}

//error but did not start this one
template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//Node<T>* next;
	//Node<T>* previous;
	//m_first->previous == &(Node<int>)value;
	Node<int> *node = new Node<int>;
	node->data = value;
	m_first->previous = node;
	node->next = m_first;
	m_first = node;
	m_first->next = NULL;
	
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Node<T>* next;
	//Node<T>* previous;
	//m_last->next == &(Node<int>)value;
	Node<int>* node = new Node<int>;
	node->data = value;
	m_last->next = node;
	node->previous = m_last;
	m_last = node;
	
	m_nodeCount++;
}

//add a if statment that allos for push back and push front to be seperat.
template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	if (index >= 0 || index < m_nodeCount) 
		return false;
	Node<T> newNode(value);
	Node<T>* m_nodePointer;
	Node<T> currentNode;
	if(index == 0)
		pushFront(value);
	else if(index == m_nodeCount)
		pushBack(value);
	
	for (int i = 0; i < index; i++)
		m_nodePointer = currentNode.next;
	newNode.next = m_nodePointer;
	//there is mabye a problem here
	m_nodePointer->previous->next = &newNode;
	m_nodePointer->previous = m_nodePointer->next;

}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	//Check to see if the actor was null
	if (!value  || getLength() <= 0)
		return false;

	bool actorRemoved = false;
	//Create a new array with a size one less than our old array
	T* newArray = new T[getLength() - 1];
	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int* i = 0; *i < getLength(); i++)
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
	for (Iterator<int> iter = begin(); iter != end(); iter.operator++())
		std::cout << *iter << std::endl;
}

//there are errors
template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	//exparemental the thing behind first is null
	m_last = nullptr;
	//exparemental (meant to say that the next thing will be null
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	for (Iterator<int> iter = begin(); iter != end(); iter++)
	{
		if (iter == nullptr || iter == NULL)
			return true;}
	return false;
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
//template<typename T>
//inline void List<T>::sort()
//{
//	T temp;
//
//	for (Node<int> c = m_nodeCount[m_first]; c < getLength(); c.next)
//	{
//		for (Node<int> b = m_nodeCount + 1; b < getLength(); b.next)
//		{
//			//have to change the c and b
//			if ( b < m_nodeCount[c])
//			{
//				Node<int>temp = m_nodeCount[c];
//				m_nodeCount[c] = m_nodeCount[b];
//				m_nodeCount[] = temp;
//			}
//		}
//	}
//}

template<typename T>
inline void List<T>::sortItem()
{

	//key = 0 j= 0
	Node<int>* valueHolder;
	Node<int>* temparry;//collection = []
	for (m_nodeCount[m_first]; m_nodeCount < getLength();)//for each index in collection
	{
		//set key to be the value at the curretn index
		valueHolder = temparry;
		//set j to be the previews index
		m_first = &m_nodeCount[valueHolder->previous];

		//start while loop
		while (m_first >= 0 && &temparry[m_first->data] > valueHolder)//While j is greater than or equal to 0 value at j is greater than key
		{
			temparry[m_first->data] = temparry[m_first->data];	//set value at the index of j+1 to the value at index of j 
			m_first--;//decrement j
		}//end while loop
		temparry[m_first->data] = *valueHolder;//set collection at the index of j + 1 to be the key 
	}
	for (m_nodeCount = 0; m_nodeCount < getLength();)
		cout << &temparry[valueHolder->data] << endl;
	////if i want to use inserten sort then i have to use a iterator to iterat throu the list
}
