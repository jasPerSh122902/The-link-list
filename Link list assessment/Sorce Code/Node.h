#pragma once

template <typename T>
struct Node
{
public:
	Node();
	Node(T value);
	Node<T>* next;
	Node<T>* previous;
	T data;
};

template<typename T>
inline Node<T>::Node()
{
	next = nullptr;
	previous = nullptr;
	data = 0;
}

template<typename T>
inline Node<T>::Node(T value)
{
	previous = nullptr;
	next = nullptr;
	data = value;
}
