#include <iostream>
#include <fstream>
#include <String>


using namespace std;

int main() {

	//Declarations
	const int MAX = 80;
	char buffer[MAX];
	ofstream outfile;
    outfile.open("StringFile.txt");

	outfile << "This is the data that my stringFile.txt contains\n";
	outfile << "This is the first line\n";
	outfile << "This is the second line of my file\n";
	outfile << "This is the third line... file ends here";

	cout << "Data written\n";

	outfile.close();

	//Now we are going to read the same file:
	ifstream infile("StringFile.txt");

	
	while (!infile.eof()) {//This is a function that determines if the end of file was reached. can use infile.good() also in place of the condition. 
		infile.getline(buffer, MAX);
		cout << "buffer = " << buffer << endl; //Printing line by line
	}

	infile.close();

	system("pause");


	return 0;
}




