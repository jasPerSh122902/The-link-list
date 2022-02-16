#include <iostream>
#include "List.h"
#include "Iterator.h"
int main()
{
	List<int> list;
	list.pushFront(2);
	list.pushFront(17);
	list.pushFront(3);
	list.pushFront(3);
	list.pushFront(42);
	list.sort();
	std::cout << "This is the first list" << std::endl;
	list.print();

	list.remove(3);
	std::cout << "This is the first list but I removed 3" << std::endl;
	list.print();

	List<int> list2 = list;
	List<int> list3 = List<int>(list);
	std::cout << "This is the list list that is copyied into another list called list 2" << std::endl;
	list2.print();
	std::cout << "This is the fist list copied into a third list but made a instence of a list while useing the first list" << std::endl;
	list3.print();
	
	list3.remove(42);
	std::cout << "This is the third list but I removed 42 and this should not have 3" << std::endl;
	list3.print();

	list.destroy();
	std::cout << "This is the first list but it is destroyed" << std::endl;
	list.print();

	system("pause");
}
