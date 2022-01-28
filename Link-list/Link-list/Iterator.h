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
	return Iterator<T>( m_current->next);
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	return Iterator<T>(m_current->previous);
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	/*if ((int)&iter == m_current->data)
		return;*/
	if (Iterator(m_current) == iter)
			return;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	/*if ((int)&iter != m_current->data)
		return;*/

	if (Iterator(m_current) != iter)
		return;
}

//This is on hold for now
template<typename T>
inline T Iterator<T>::operator*()
{
	return T();
}
