# link-List 
# **Introduction**
This program is meant to be a test to make the data structure link list. 

*Successful creation of a project which implements and demonstrates a double-linked list.

    * The created program must demonstrate a custom sorting algorithm
* Project submitted as an executable binary file that can be run external to an IDE.
* Source code and project files are also submitted for review.

$File$ : _Iterator.h_

$Type$ : Tempate T

Iterators are meant to go through the list nodes in a link list and hold the data of those nodes. 

# **Desgin**

$Name$ :  Iterator()
+ Description : Is a baic contructor for the Iterator class.
* Visualibility : public


$Name$ :  Iterator(Node<T>* node)
+ Description : Is a contructor for the Iterator class that takes in a Node pointer.
* Visualibility : public

$Name$ :  operator ++()
+ Description : Add the ability to add a node and iterators.
* Visualibility : public
* Type : Iterator<T>

$Name$ :  operator --()
+ Description : Add the ability to subtract a node and iterators.
* Visualibility : public
* Type : Iterator<T>

$Name$ :  operator ==(const Iterator<T>& iterator)
+ Description : Makes a node and iterators equal each other.
* Visualibility : public
* Type : const bool

$Name$ :  operator !=(const Iterator<T>& iterator)
+ Description : Makes a node and iterators run the check to see if they are not equal.
* Visualibility : public
* Type : const bool

$Name$ :  operator *()
+ Description : Dereference eny variable.
* Visualibility : public
* Type : T

$Name$ :  m_currentNode
+ Description : Is a Node pointer
* Visualibility : private
* Type : Node<T>*

$File$ : _List.h_

$Type% : Tempate T

List is a holder for the nodes. And it works like a array.

$Name$ :  List()
+ Description : Is a baic contructor for the Listclass.
* Visualibility : public

$Name$ :  List(const List<T>* otherList)
+ Description : Is a contructor for the List class that takes in aother list.
* Visualibility : public

$Name$ :  ~List()
+ Description : is a deconstructor for the list 
* Visualibility : public

$Name$ :  start() const
+ Description : sets the m_first
* Visualibility : public
* Type : Iterator<T>

$Name$ :  End() const
+ Description : sets the m_last 
* Visualibility : public
* Type : Iterator<T>

$Name$ :  checkIfIncludes(const T object)
+ Description : checks to see if the object is in the list
* Visualibility : public
* Type : const bool

$Name$ :  pushFront(const T& value)
+ Description : makes m_first the value that is given
* Visualibility : public
* Type : void

$Name$ :  pushBack(const T& value)
+ Description : makes m_last the value that is given
* Visualibility : public
* Type : void

$Name$ :  insert(const T& value, int index)
+ Description : put the value at the given index
* Visualibility : public
* Type : void

$Name$ :  remove(const T& value)
+ Description : removes the value
* Visualibility : public
* Type : bool

$Name$ :  print() const
+ Description : prints the list that exists
* Visualibility : public
* Type : void

$Name$ :  initialize()
+ Description : sets both of the m_fist , m_last, and m_nodeCount to base values
* Visualibility : public
* Type : void

$Name$ :  isEmpty() const
+ Description : checks to see if the list is empty
* Visualibility : public
* Type : bool

$Name$ :  getData(Iterator<T>& iterator, int index) const
+ Description : gets the data at the index and takes in a iterator
* Visualibility : public
* Type : bool

$Name$ :  getLength() cont
+ Description : get the m_nodeCount
* Visualibility : public
* Type : int

$Name$ :   operator= (const List<T>& otherlist)
+ Description : adds the the ability for the equal operator to make a list equal to a iterator
* Visualibility : public
* Type : List<T>&

$Name$ :   sort()
+ Description : it is a sorting agarithom 
* Visualibility : public
* Type : void

$Name$ :  remove(const T& value, int index)
+ Description : removes the value at the index. Is used to removes the node
* Visualibility : private
* Type : bool

$Name$ :  m_currentNode
+ Description : is used to hold and count the number of nodes
* Visualibility : private
* Type : int

$Name$ :  m_first
+ Description : is a pointer to a node that is called m_first
* Visualibility : private
* Type : Node<T>*

$Name$ :  m_last
+ Description : is a node pointer for the Node that is calssed m_last
* Visualibility : private
* Type : Node<T>*

$File$ : _Node.h_

$Type$ : Tempate T

The Nodes hold information that can be pointers or any variables.

$Name$ :  Node()
+ Description : Is a baic contructor for the Node class.
* Visualibility : public

$Name$ :  List(T value)
+ Description : Is a contructor for the Node class that takes in a  value.
* Visualibility : public

$Name$ :  Next
+ Description : holds the value of the next node form the current node
* Visualibility : public
* Type : Node<T>*

$Name$ :  previous
+ Description : holds the value of the previous node form the current node
* Visualibility : public
* Type : Node<T>*

$Name$ :  data
+ Description : holds the data of a node
* Visualibility : public
* Type : T