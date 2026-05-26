#include<iostream>
#include<algorithm>
//#include<bits/stdc++.h>

using namespace std;

#include "StudentStaticMembers.cpp"
#include "Fraction.cpp"
//#include "isSorted.cpp"
void bubbleSort(int a[], int n);
void OptimizedbubbleSort(int a[], int n);
bool isSorted(int a[], int n);
int sumOfArray(int a[], int n);
bool isPresent(int a[], int n, int x);
int lastIndex(int a[], int n, int x, int i);
int lastIndex2(int a[], int n, int x);
void printAllPos(int a[], int n, int x, int i);
void count(int a[], int n, int x, int i, int& ans);
int count2(int a[], int n, int x, int i);
bool checkPal(int a[], int s, int e);
void print(char input[]);
void revPrint(char input[]);
void removeA(char input[]);
void removeConsecutiveDuplicates(char input[]);
void print_subs(string input, string output);
int convertStringToInt(char str[], int n);
int length(char input[]);
void printPermutation(char str[], int i=0);
int countWays(int n);
int toh(int n);
void printSteps(int n, char s, char d, char h);
void mergeArrays(int x[], int y[], int a[], int s, int e);
void mergeSort(int a[], int s, int e);


int main() {
	

	int n;
	cin>>n;

	int a[100];
	int b[] = { 1,2,3,4,3,2,1,};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//OptimizedbubbleSort(a, n);

	cout << "Next Fuction" << endl;; //This is algorithm library sort.

	int ans = 0;
	//printAllPos(a, 6, 6, 0);
	char c[] = "1234";
	char d[] = "aabstdfffffgarsfgsdeaaa";

	count(a, 6, 5, 0, ans);
	cout << ans << endl;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	cout << "New" << endl;
	cout << count2(a, 6, 5, 0) << endl;

	cout << "Check Palindrome" << endl;
	cout << checkPal(b, 0, 6);

	cout << "Print Array" << endl;
	print(c);

	revPrint(c);

	cout << d << endl;
	//removeA(d);
	cout << d << endl;

	cout << endl;
	removeConsecutiveDuplicates(d);
	cout << d << endl;

	/*
	string output = "";
	print_subs(d, output);

	char str44[] = "12345";
	int n44 = length(str44);

	int a44 = convertStringToInt(str44,n44);

	cout << a44 << endl;
	*/
	char str[] = "ABC";
	printPermutation(str);

	cout << "CountWays" << endl;
	cout<<countWays(4)<<endl;

	cout << toh(3) << endl;

	printSteps(3,'A','C','B');

	cout << "Mergesort" << endl;

	int j[] = {7,3,10,5,6,2,-5,78};
	mergeSort(j, 0, 7);

	for (int i = 0; i < 8; i++) {
		cout << j[i] << " ";
	}

	return 0;
}


