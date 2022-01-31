#include <iostream>
#include "List.h"
#include "Iterator.h"
int main()
{
    List<int> m_list = List<int>();
    Node<int> m_node = Node<int>();
    Iterator<int> m_iter = Iterator<int>();
    //it prints but not correcly
    m_list.pushFront(5);
    m_list.pushBack(6);
    m_list.pushFront(7);
    m_list.pushBack(8);
    m_list.print();
}


