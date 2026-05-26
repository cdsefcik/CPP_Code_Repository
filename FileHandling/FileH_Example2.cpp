#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {

	//Declarations
	char ch;
	int i;
	float f;
	string str1;
	string str2;

	//open file
	ifstream infile("File.txt");
	
	infile >> ch>>i>>f>> str1>> str2;


	//write data to the file
	cout << ch << endl;
	cout << i << endl;
	cout << f << endl;
	cout << str1 << endl;
	cout << str2 << endl;
	//Close file
;
    infile.close();

	system("pause");
	return 0;
}


