#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {

	//Declarations
	char ch = 'z';
	int i = 77;
	float f = 6.02;
	string str1 = "Hello";
	string str2 = "file";

	//open file
	//ofstream outfile;
	fstream outfile;
	outfile.open("File.txt",ios::out|ios::app);

	//write data to the file
	outfile << ch << i << ' ' << f << str1 << ' ' << str2;

	cout << "Data is written to the file\n";

	//Close file
	outfile.close();


	system("pause");
	return 0;
}


