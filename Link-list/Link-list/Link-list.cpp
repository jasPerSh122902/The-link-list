#include <iostream>
#include "List.h"
#include "Iterator.h"
int main()
{
    List<int> m_list = List<int>();
    Node<int> m_node = Node<int>();
    Iterator<int> m_iter = Iterator<int>();


    m_list.pushFront(5);
    m_list.print();
}


