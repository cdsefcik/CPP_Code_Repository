#include<iostream>
#include<vector>
#include<algorithm>

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

	//Vector Container instantiated
	vector<int> myvec = { 40,50,20,10,30 };

	//Iterator for vector container
	for (std::vector<int>::iterator i = myvec.begin(); i != myvec.end(); i++) {
		cout << *i << " ";
	}

	//SORT
	sort(myvec.begin(), myvec.end());

	cout << " Sorted Vector : ";
	for (std::vector<int>::iterator i = myvec.begin(); i != myvec.end(); i++) {
		cout << *i << " ";
	}

	cout << endl;

	//REVERSE
	reverse(myvec.begin(), myvec.end());

	cout << " Reversed Vector : ";

	for (std::vector<int>::iterator i = myvec.begin(); i != myvec.end(); i++) {
		cout << *i << " ";
	}

	//MAX ELEMENT
	cout << " Max : " << *max_element(myvec.begin(), myvec.end()) << endl;

	//MIN ELEMENT
	cout << " Max : " << *min_element(myvec.begin(), myvec.end()) << endl;

	//Binary_search - Search Element
	if (binary_search(myvec.begin(), myvec.end(), 29)) {
		cout << "Element Found" << endl;
	}
	else {
		cout << "Element Not Found " << endl;
	}

	vector<int> myvec2 = { 5,10,20,20,20,40,40,50 };

	//Count
	cout << "No of 20: " << count(myvec2.begin(), myvec2.end(), 20) << endl;
	
	//Can go to cplusplus.com to see the list of all algorithms under the algorithms hyperlink.
	
	return EXIT_SUCCESS;
}
