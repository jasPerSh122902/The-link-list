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
	list.print();

	list.remove(3);
	list.print();

	List<int> list2 = list;
	//List<int> list3 = List<int>(list);

	list2.print();
	//list3.print();

	list.destroy();
	list.print();

	//list3.remove(42);


	system("pause");
}
