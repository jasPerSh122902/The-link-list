#pragma once
template <typename T>
class List
{
private:

public:
	List();
	List(const List);
	~List();
	void destroy();
	Iterator<T> const begin();
	Iterator<T> const end();
	const bool contain(const T object);
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);
	const void print();
	void initialize();

};