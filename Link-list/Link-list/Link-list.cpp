#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Node.h"
int main()
{
    List<int> m_list = List<int>();
    Node<int> m_node = Node<int>();
    Iterator<int> m_iter = Iterator<int>();

    m_list.getData(m_iter, 1);
    m_list.pushBack(5);
    m_list.print();
}


