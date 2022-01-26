#pragma once
template <typename T>
class Node;
template <typename T>
class Iterator 
{
public:

	Iterator();
	Iterator(Node<T>* node);
	Iterator<T> operator++();
	Iterator<T> operator--();
	const bool operator ==(const Iterator<T> & iter);
	const bool operator !=(const Iterator<T>& iter);
	T operator *();
	
private:
	Node<T>* m_current;
};

template<typename T>
inline Iterator<T>::Iterator()
{
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	node = m_current;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	return Iterator<T>( Iterator + 1);
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	return Iterator<T>(Iterator - 1);
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	if (&iter == Iterator)
		return;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	if (&iter != iterator)
		return;
}

//This is on hold for now
template<typename T>
inline T Iterator<T>::operator*()
{
	return T();
}
