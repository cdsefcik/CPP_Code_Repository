#include<iostream>
using namespace std;


    void SelectionSortTest(int a[], int n) {
        for (int i = 0; i <= n - 2; i++) {
            int smallest = i;
            for (int j = i + 1; j <= n - 1; j++) {

                if (a[j] < a[smallest]) {
                    smallest = j;
                }
            }

            swap(a[i], a[smallest]);
        }
    }