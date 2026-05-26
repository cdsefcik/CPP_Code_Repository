#include<iostream>
using namespace std;
//#include"SelectionSortTest.cpp"

void SelectionSortTest(int array[], int length);

void selectionSort(int a[], int n) {
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

/*
int main() {

    int n;
    cin >> n;

    int a[10];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SelectionSortTest(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

*/