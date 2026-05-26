#define __DLLEXPORT

#include "C:\Users\CompS\source\repos\optimizedsearchalgorithms\include\SearchHeader.h"
#include <iostream>


int linearSearch(int* a, int n, int key) {

	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			std::cout << "" << i << '\n';
			return i;
		}
	}
	return -1; //-1 because it is an invalid position.
};



