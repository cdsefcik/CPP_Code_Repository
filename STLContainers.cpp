#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>

using namespace std;

/*
* Standard Template Library (STL)
* STL is a set of C++ template classes (lists, stacks, arrays, searching, sorting). These are generic.
* STL contains: Algorithms, Containers and Iterators.
* Iterators are used to point to containers. They act as the bridge between containers and algorithms. The iterator acts like a pointer that allows the user to traverse through elements in a container.
* Containers provided: Array, Vector, Queue, Stack, Priority_Queue, List, Set, Map.
* Container types: Sequence Containers, Associative Containers, Unordered Associative Containers, Container Adaptors Containers.
*/

/*
*Array properties: Contiguous storage, strict linear sequence, cannot be expanded or contracted at run time. 
*Vector properties: It is a dynamic array.
*List: A linked list can be implemented by list.
*Stack properties, push and pop both done at the top of the stack. Adaptor Container, implements a different interface
*Queue, Adaptor container, insertion is done at back and deletion is done at the front.
*Priority Queue, (Replicate Max Heap or Min Heap). Greatest, Smallest lement in the front.
*Map Container, Associated Container. Key-Value pair. The key is unique and cannot be changed.
*Multimap Container, Associative Container. Key-Value pair. Can have multiple keys.
*Unordered map, the keys are not ordered. The keys can not duplicate.
*Set, a set is an associtate container, that is sorted and unique. Usually implemented as a red-black tree.
*Mulitset container - Associative Container, is ordered and allows non unique values.
*Unordered Set - unique values that are not ordered.
*/


int main() {
	//ARRAY CONTAINER: Sequential container
	std::array<int, 3> testArray1;
	std::array<int, 3> testArray2 = { 10,20,30 };

	//Array Containers:
	cout << "At " << testArray2.at(2) << endl; //Out of bound safe.
	cout << "[] " << testArray2[2] << endl;    //unsafe.
	cout << "back() " << testArray2.back() << endl; //Return last element.
	cout << "front() " << testArray2.front() << endl; //Return first element.

	testArray1.fill(0); //Fill array with 0.

	testArray1.swap(testArray2); //Swap array.

	testArray1.empty(); //Empty the array

	cout << "Size() " << testArray2.size() << endl; //Size of array filled

	cout << "max_size() " << testArray2.max_size() << endl; //Max size of array

	//VECTOR CONTAINER: Sequential container
	std::vector<int> testVector1;

	cout << "size " << testVector1.size() << endl;

	std::vector<int> testVector2 = { 10,20,30 };

	//methods
	cout << "At " << testVector2.at(2) << endl; //Out of bounds safe.
	cout << "[] " << testVector2[2] << endl;    //Unsafe

	testVector2.push_back(40); //Insert an elemenet at the end of vector.
	testVector2.push_back(50);
	testVector2.push_back(60);

	//Iterator is pointer to container

	for (vector<int>::iterator i = testVector2.begin(); i != testVector2.end(); i++) {
		cout << *i << " ";

	}

	//Insert - insert the element in vector before the position pointed
	vector<int>::iterator i = testVector2.begin();
	testVector2.insert(i, 0);

	//Erase erase and element.
	vector<int>::iterator i2 = testVector2.begin();
	testVector2.erase(i2);

	//Erase all elements except last element
	testVector2.erase(testVector2.begin(), testVector2.end() - 1);

	//Swap: interchanges value of two vectors
	testVector2.swap(testVector1);

	//Capacity: number of elements that can be inserted
	//In the vector based on the memory allocated to the vector
	cout << endl << "Capacity " << testVector2.capacity() << endl;
	cout << endl;

	//LIST: A linked list can be implemented by list.

	std::list<int> list1;

	//Initialization
	std::list<int> list2 = { 1,2,3 };

	//Methods
	list<int>::iterator i6 = list2.end();

	//insert
	list2.insert(i6, 10);

	for (list<int>::iterator i = list2.begin(); i != list2.end(); i++)
	{
		cout << *i << " ";   // for printing the list
	}

	//push_back     1,2,3,20
	list2.push_back(20);

	//push_front    10,1,2,3,20
	list2.push_front(10);

	//pop_back      10,1,2,3
	list2.pop_back();

	//pop_front    1,2,3
	list2.pop_front();

	//reverse      3,2,1
	list2.reverse();

	//swap
	list2.swap(list1);

	//size :- no of element present in list  = 3
	list1.size();

	//sort    1,2,3
	list1.sort();

	//merge   10,20,1,2,3
	list1.merge(list2);

	//STACK 
	stack<int> stack1;

	//Push Values
	stack1.push(10);
	stack1.push(20);
	stack1.push(30);

	//Top
	cout << "Top element :-" << stack1.top() << endl;

	//Pop
	stack1.pop();

	cout << endl << "Top Element : -" << stack1.top() << endl;

	//Size
	cout << endl << "No. Of Elements : -" << stack1.size() << endl;

	//QUEUE
	queue<int> queue1;

	//push value
	queue1.push(10);
	queue1.push(20);
	queue1.push(30);

	//10,20,30
	//front  = 10
	cout << endl << "front element :-" << queue1.front();

	//back
	cout << endl << "Back element :-" << queue1.back();

	//pop
	queue1.pop();
	cout << endl << "New front element :-" << queue1.front();

	//size: no of element present in queue
	cout << endl << "No. Of element:- " << queue1.size();

	//PRIORITY QUEUE

	//Create a priority Queue with a max heap.
	priority_queue <int> queue5;

	//Add elements
	queue5.push(20);
	queue5.push(40);
	queue5.push(30);

	//Will be arranged in descending order: 40, 30, 20

	//Top print 40
	cout << endl << "Top Element : - " << queue5.top() << endl;

	//Pop
	queue5.pop();

	cout << "Size of: " << queue5.size() << endl;

	//Create a priority Queue with min heap.
	priority_queue<int, vector<int>, greater<int>> queue6;

	queue6.push(20);
	queue6.push(40);
	queue6.push(30);
	//Will arrange:20,30,40

	cout << endl << "Top Element : - " << queue6.top() << endl;
	
	//MAP
	//map<Key_Type, Value_type> map_name

	std::map<int, string> map1; //Declaration

	//Initialization
	std::map<int, string> map2 = { {101,"value1"},{201,"value2"},{301,"value3"} };

	//Insert
	map2[201] = "Time";

	//methods

	//check
	for (map<int, string>::iterator i = map2.begin(); i != map2.end(); i++)
	{
		cout << i->first << " ";   // for printing the map KEY

		cout << i->second << endl;   // for printing Value - for string value
		//don't forget to include STRING header.
	}
	cout << endl;

	//at()
	cout << "Value at 201:-" << map2.at(201) << endl; // get value by KEY
	//out of bound safe
//[]
	cout << "Value at 201:-" << map2[201] << endl;

	//change value
	map2.at(201) = "Lima";

	cout << "Value at 201:-" << map2.at(201) << endl;


	//insert:- insert key,value at particular location as MAP is sorted.
	//2 approach
	map2.insert(pair<int, string>(106, "Amit"));

	map2.insert(make_pair(208, "Hina"));

	//insert:- insert key,value at particular location as MAP is sorted.
	//2 approach
	map2.insert(pair<int, string>(106, "Amit"));

	map2.insert(make_pair(208, "Hina"));

	//check
	for (map<int, string>::iterator i = map2.begin(); i != map2.end(); i++)
	{
		cout << i->first << " ";   // for printing the map KEY

		cout << i->second << endl;   // for printing Value - for string value
		//don't forget to include STRING header.
	}
	cout << endl;

	//Declaration
	multimap <int, string> mmap1;

	//init.
	multimap <int, string> mmap2 = { {101, "Vedinesh"}, {201, "Tim"}, {201, "Faran"} };

	//UNORDERED MAP
	//declaration
	unordered_map <int, string> umap1;

	//init.
	unordered_map <int, string> umap2 = { {101, "Vedinesh"}, {202, "Tim"}, {201, "Faran"} };
	
	cout << endl;

	//CONTAINER - SET
	set<int> set1 = { 10,20,10,30,40,50,20 };

	//Create an iterator
	for (set<int>::iterator i200 = set1.begin(); i200 != set1.end(); i200++) {
		cout << *i200 << " ";
	}

	//Insert
	set1.insert(90);

	//CONTAINER - MULTISET
	multiset <int> mset1;

	//Container
	multiset <int> mset2 = { 1,3,2,1,4,5,6,7,5,6,7,9 };

	mset2.insert(9);

	cout << endl;

	//CONTAINER - UNORDERED SET
	unordered_set <int> uset1;

	unordered_set <int> uset2 = { 1,3,2,1,4,5,6,7,1,2 };

	//Iterator
	for (unordered_set<int>::iterator i50 = uset2.begin(); i50 != uset2.end(); i50++) {
		cout << *i50 << " ";
	}

	//Insert.
	uset2.insert(500);

	//Erase
	unordered_set<int>::iterator del = uset2.begin();
	uset2.erase(del); //Erase by iterator

	uset2.erase(2); //Value

	uset2.erase(uset2.begin(), uset2.find(5));// delete by range. 
	
	cout << endl << "Size uset2 : " << uset2.size();

	return EXIT_SUCCESS;
}
