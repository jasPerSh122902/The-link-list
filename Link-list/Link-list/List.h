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
	Node<int>* currentNode = m_first;
	Node<T>* nextNode;
	//makes nodecount = to first and if node counter is not null
	for (int i = 0; i < getLength(); i++;)
	{
		//makes a temp node and assigns it the node count
		nextNode = currentNode->nextNode;
		delete currentNode; // delete that temp node
		currentNode = nextNode;
	}
	initialize();
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	Iterator<T> iterator(m_first); //Creates an iterator that points at the first node
	return iterator;
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	Iterator<T> iterator(m_last); //Creates an iterator that points at the first node
	return iterator;
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
	Node<T>* newNode = new Node<T>(data); //Creates a new node with the given data
	
	if (m_nodeCount == 0) {
		m_firstNode = newNode;
		m_lastNode = newNode;
	}
	else if (m_nodeCount == 1) {
		m_firstNode = newNode;
		m_firstNode->nextNode = m_lastNode;
		m_lastNode->previousNode = m_firstNode;
	}
	else {
		//Sets the current first node's previous to be the new node, and then sets the first node to point at the new node
		m_firstNode->previousNode = newNode;
		newNode->nextNode = m_firstNode;
		m_firstNode = newNode;
	}
	m_nodeCount++;
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
	Node<T>* newNode = new Node<T>(data); //Creates a new node with the given data

	if (m_nodeCount == 0) {
		m_firstNode = newNode;
		m_lastNode = newNode;
	}
	else if (m_nodeCount == 1) {
		m_lastNode = newNode;
		m_firstNode->nextNode = m_lastNode;
		m_lastNode->previousNode = m_firstNode;
	}
	else {
		//Sets the current first node's previous to be the new node, and then sets the first node to point at the new nodenewNode->previousNode = m_lastNode;
		m_lastNode->nextNode = newNode;
		m_lastNode = newNode;
	}	
	m_nodeCount++;
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
	Node<T>* newNode = new Node<T>(value);
	
	if(index == 0)
		pushFront(value);
	
	else if(index == m_nodeCount)
		pushBack(value);
	
	Node<T>* nodeAtIndex = m_firstNode;
	
	for (int i = 0; i < index; i++)
		m_nodePointer = currentNode.next;
	newNode.next = m_nodePointer;
	//there is mabye a problem here
	m_nodePointer->previous->next = &newNode;
	m_nodePointer->previous = m_nodePointer->next;
	
	//Places the new node in the place that the current node is
	newNode->nextNode = nodeAtGivenIndex;
	newNode->previousNode = nodeAtGivenIndex->previousNode;
	nodeAtGivenIndex->previousNode->nextNode = newNode;
	nodeAtGivenIndex->previousNode = newNode;

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
	if (index < 0|| index < getLength())
		return false;
	
	iter = begin();
	
	while(iter <index)
		++iter;
	
	return true;
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
	destroy()//Clears this list
	m_first = otherList.m_first; //Sets this list's first node to be the other list's first node
	m_last = otherList.m_last; //Sets this list's last node to be the other list's last node
	m_nodeCount = otherList.m_nodeCount; //Sets the node count to be equal to the other list's node count
}

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
	
	
	//this is mean to be revised by me
	Iterator<T> iterator(m_firstNode);
	T key = NULL;
	int i = 1;
	int j = 0;

	for (Iterator<T> iteratorTwo(m_firstNode->nextNode); iteratorTwo != getLastNode(); ++iteratorTwo) {
		i++;
		iterator = Iterator<T>(m_firstNode);
		for (int k = 0; k < i; k++)
			++iterator;
		j = i - 1;
		while (j >= 0 && *iterator > key) {
			remove(*iterator);
			insert(*iterator, j + 1);
			j--;
			--iterator;
		}
		iterator = Iterator<T>(m_firstNode);
}
