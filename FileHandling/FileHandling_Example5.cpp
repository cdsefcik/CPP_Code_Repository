#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {


	string str = "In some ways, programming is like painting";
	char ch;

	ofstream outfile("File5.txt");

	for (int j = 0; j < str.size(); j++) {
		outfile.put(str[j]);
	}

	cout << "File5.txt is written successfully\n";

	outfile.close();

	ifstream infile("File5.txt");

	//while (infile) {
	//	infile.get(ch);
	//	cout << ch;
	//}

	//cout << "\n";



	//This prints all the data from the file from one statement.

	cout << infile.rdbuf();

	infile.close();
	system("pause");
	return 0;
}