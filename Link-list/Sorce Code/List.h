#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>

template<typename T>
class List {
public:
	List();
	List(const List<T>& otherList);
	~List();

	void destroy(); //Deletes all nodes in the list

	Iterator<T> start() const; //Returns the node at the start of the list
	Iterator<T> end() const; //Returns the ndoe at the end of the list
	const bool checkIfIncludes(const T object); // Checks to see if the given item is in the list

	void pushFront(const T& value); //Adds a new node at the beginning of the list
	void pushBack(const T& value); //Adds a new node to the end of the list
	bool insert(const T& value, int index); //Adds a new node at the given index
	bool remove(const T& value); //Removes the first node with the given value

	void print() const; //Prints every node's data
	void initialize();  //Set the default values for the first node pointer, the last node pointer, and the node count
	bool isEmpty() const; //Returns whether or not the list has any nodes in it
	bool getData(Iterator<T>& iterator, int index); //Sets the given backwardsIterator to point at a node at the given index
	int getLength() const; //Returns the amount of nodes in the list

	const List<T>& operator =(const List<T>& otherList); //Sets a list to be equal to another
	void sort(); //Sorts the nodes in the list 

private:
	bool remove(const T& value, int index);

	Node<T>* m_first; //First node in the list
	Node<T>* m_last; //Last node in the list
	int m_nodeCount; //Number of nodes in the list
};

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
inline void List<T>::print() const
{
	for (Iterator<T> iterator(m_first); iterator != end(); ++iterator) {
		std::cout << *iterator << "\n";
	}
	std::cout << "\n";
}

template<typename T>
inline void List<T>::destroy() 
{
	Node<T>* currentNode = m_first;
	Node<T>* nextNode;

	for (int i = 0; i < getLength(); i++) {

		if (currentNode = nullptr)
		{
			currentNode = currentNode->previous;
			return;
		}
		
		if (currentNode != nullptr)
		{
			//Holds the current node's next in a temp variable
			nextNode = currentNode->next;
			delete currentNode;
			// sets the current node to be  the temp variable
			currentNode = nextNode;
		}
		
	}

	initialize();
}

template<typename T>
inline Iterator<T> List<T>::start() const 
{
	//Creates an Iterator that points at the first node
	Iterator<T> iterator(m_first); 
	return iterator;
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	//Creates an Iterator that points at the last node
	Iterator<T> iterator(m_last); 
	return iterator;
}

template<typename T>
inline const bool List<T>::checkIfIncludes(const T data)
{
	//Goes through each node using the Iterator and check to see if the data at the ....
	for (Iterator<T> iterator(start()); iterator != end(); ++iterator) {
		if (*iterator == data)//...Iterator's current node matches the given data
			return true;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& data) {
	//Creates a new node with the given data
	Node<T>* newNode = new Node<T>(data); 

	if (m_nodeCount == 0)
	{
		m_first = newNode;
		m_last = newNode;
	}
	else if (m_nodeCount == 1)
	{
		m_first = newNode;
		m_first->next = m_last;
		m_last->previous = m_first;
	}
	else
	{
		//Sets the current first node's previous to be the new node
		m_first->previous = newNode;
		//and then sets the first node to point at the new node
		newNode->next = m_first;
		m_first = newNode;
	}
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& data) 
{
	//Creates a new node with the given data
	Node<T>* newNode = new Node<T>(data); 

	if (m_nodeCount == 0) 
	{
		m_first = newNode;
		m_last = newNode;
	}
	else if (m_nodeCount == 1)
	{
		m_last = newNode;
		m_first->next = m_last;
		m_last->previous = m_first;
	}
	else {
		//Sets the current first node's previous to be the new node
		m_last->next = newNode;
		// sets the first node to point at the new nodenewNode->previousNode = m_lastNode;
		newNode->previous = m_last;
		m_last = newNode;
	}
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& data, int index) 
{
	//If the given index is outside the range of the list
	if (index < 0 || index > m_nodeCount)
		return false;//return false

	Node<T>* newNode = new Node<T>(data); //Creates a new node with the given data

	//If the index is zero
	if (index == 0) 
	{
		// add the new node to the front of the list
		pushFront(data);
		return true;
	}
	//If the index is zero
	else if (index == getLength())
	{
		//add the new node to the back of the list
		pushBack(data);
		return true;
	}

	//Gets the node currently at the given index
	Node<T>* nodeIndex = m_first;
	for (int i = 0; i < index; i++)
		nodeIndex = nodeIndex->next;

	//Places the new node in the place that the current node is
	//makes the new nodes next to the given index
	newNode->next = nodeIndex;
	//the nev nodes previous to the node indexs previous
	newNode->previous = nodeIndex->previous;
	//makes the new nodes previous next (looks at it self) equal to the new node
	newNode->previous->next = newNode;
	//makes the index previous equal to the nes node
	nodeIndex->previous = newNode;
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::remove(const T& value) 
{
	//Loops through the nodes and checks to see if their data matches the value given
	Node<T>* currentNode = m_first;
	for (int i = 0; i < getLength(); i++) 
	{
		//If the current node's data matches the value given
		if (currentNode->data == value) 
		{
			//If the current node matches the first node
			if (currentNode == m_first)
			{
				m_first = currentNode->next; //Set the first node to be the currents next node;
				m_first->previous = nullptr;
				delete currentNode; //Deletes the current node
			}
			//Else if the current node matches the last node
			else if (currentNode == m_last)
			{
				m_last = currentNode->previous; //Set the last node to be equal to the current node's previous node
				m_last->next = nullptr;
				delete currentNode; //Deletes the current node
			}
			else
			{
				//Sets the current node's previous next to be equal to the current node's next node
				currentNode->previous->next = currentNode->next;
				//Sets the current node's next  previous to be equal to the current node's previous node
				currentNode->next->previous = currentNode->previous;
				delete currentNode; //Deletes the current node
			}
			m_nodeCount--;
			return true;
		}
		//If the current node's data does not match the value, go to the next node
		else currentNode = currentNode->next;
	}
	return false;
}


template<typename T>
inline void List<T>::initialize() 
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const 
{
	if (getLength() == 0)
		return true;
	else return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iterator, int index)
{
	if (index < 0 || index < getLength())
		return false;

	iterator = start(); //Sets the Iterator equal to the first node in this list 
	//Loops through the list until the Iterator reaches the node at the given index
	while (iterator < index)
		++iterator;
	return true;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	destroy(); //Clears this list
	m_first = otherList.m_first; //Sets this list's first node to be the other list's first node
	m_last = otherList.m_last; //Sets this list's last node to be the other list's last node
	m_nodeCount = otherList.m_nodeCount; //Sets the node count to be equal to the other list's node count
}

template<typename T>
inline void List<T>::sort()
{
	Iterator<T> IteratorFirst(m_first); //Iterator that points at the first node
	T key = NULL; //Stores the value of the node that 
	int i = 0, j = 0; 

	//Loops forwards through a list using an backwardsIterator
	for (Iterator<T> forwardIterator(m_first->next); forwardIterator != end();) 
	{
		i++;
		key = *forwardIterator; //Sets the key equal to the forwardIterator's current node
		j = i - 1; //Sets j to be one less than i
		//is never ment ot be greater than 0
		IteratorFirst = forwardIterator; //Sets the backwardsIterator to be one less than the forwardIterator
		--IteratorFirst;
		//While j is less than or greator to 0, and the backwardsIterator's current node's value is greater than the key
		while (j >= 0 && *IteratorFirst > key)
		{
			j--; //Decrement j
			--IteratorFirst; //Decrement the backwardsIterator
		}
		++forwardIterator; //Increment the forwardIterator
		remove(key, i); //Removes the key...
		insert(key, j + 1); //...and adds it back and the index of j + 1
	}
}

template<typename T>
inline bool List<T>::remove(const T& value, int index)
{
	if (index < 0 || index > getLength())
		return false;

	//Loops through the nodes and gets the node at the given index
	Node<T>* currentNode = m_first;
	for (int i = 0; i < index; i++) 
	{
		// getting the next node
		currentNode = currentNode->next;
	}

	if (currentNode->data != value)
		return false;

	//If the current node matches the first node...
	if (currentNode == m_first) 
	{
		m_first = currentNode->next; //Set the first node to be the current first node's next node;
		m_first->previous = nullptr;
		delete currentNode; //Deletes the current node
	}
	//Else if the current node matches the last node
	else if (currentNode == m_last) 
	{
		m_last = currentNode->previous; //Set the last node to be equal to the current node's previous node
		m_last->next = nullptr;
		delete currentNode; //Deletes the current node
	}
	else
	{
		//Sets the current node's previous  next to be equal to the current node's next node
		currentNode->previous->next = currentNode->next;
		//Sets the current node's next  previous  to be equal to the current node's previous node
		currentNode->next->previous = currentNode->previous;
		delete currentNode; //Deletes the current node
	}
	m_nodeCount--;
	return true;
}
