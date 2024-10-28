#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<map>

using namespace std;

/*
* Standard Template Library (STL)
* STL is a set of C++ template classes (lists, stacks, arrays, searching, sorting). These are generic.
* STL contains: Algorithms, Containers and Iterators.
* Iterators are used to point to containers. They act as the bridge between containers and algorithms. The iterator acts like a pointer that allows the user to traverse through elements in a container.
* Containers provided: Array, Vector, Queue, Stack, Priority_Queue, List, Set, Map.
* Container types: Sequence Containers, Associative Containers, Unordered Associative Containers, Container Adaptors Containers.
*/



int main() {

	//VECTOR INSIDE VECTOR
	vector<int> myvec{ 40,50,20 };

	vector<vector<int>> vec1 = { {1,2,3}, { 4,5,6 }, { 7,8,9 } };
	
	vec1.push_back(myvec);

	//Pop back function
	vec1[0].pop_back();

	//LIST INSIDE LIST

	list < int> l = { 5,6,7 };
	list < list<int>> ll = { {1,2,3}, {4,5,6} };

	//Outer Iterator
	list<list<int>>::iterator i = ll.begin();
	for (i; i != ll.end(); i++) {
		list<int> pi = *i;

		//Inner Iterator
		list<int>::iterator itr = pi.begin();
		for (itr; itr != pi.end(); itr++) {
			cout << *itr << " ";
		}
		cout << endl;

	}

	//MAP INSIDE MAP

	return EXIT_SUCCESS;
}
