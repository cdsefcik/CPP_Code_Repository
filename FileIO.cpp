#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*
*File IO
* Input Output Streams (IOS) Keyboard, monitor: istream(Keyboard) and ostream(Monitor)
* (IOS) file streams: ifstream(Input) and ofstream(Output)
*/

//class student to read and write student details
class student
{
private:
	char name[30];
	int age;
public:
	void getData(void)
	{
		cout << "Enter name:"; cin.getline(name, 30);
		cout << "Enter age:"; cin >> age;
	}

	void showData(void)
	{
		cout << "Name:" << name << ",Age:" << age << endl;
	}
};


int main() {
	
	//How to write data into file.
	//First, create an ofstream.
	ofstream fout; //Create an object from the ofstream class.

	fout.open("my.txt"); //Open a file, if does not exist, create the file.
	fout <<"VeDinesh"; //Write to the file, with the help of output stream.
	fout.close(); //Write the file into the hard disk and close the file.

	//Reading data from file.
	ifstream fin;                //Create input stream.
	char ch;                     //Variable for storing GET pointer character.

	fin.open("my.txt");          //Load file into RAM.
	fin >> ch;                   //Storing 1st GET pointer value into CH variable.

	while (!fin.eof()) {         //Iterate until the end of file.
		cout << ch;              //Print the value at the first index, first character.          
		fin >> ch;               //Move the get pointer forward.
	}

	fin.close();

	cout << "\n";

	//Tellg function gets the position of the current character.
	char ch1;                     //Variable for storing GET pointer character.

	fin.open("my.txt");          //Open the file.
	int pos;                     //Position of the character.
	pos = fin.tellg();           //Get the position of the value.

	cout << pos << endl;         //Print the position.

	fin >> ch1;                    //Move the pointer forward.
	pos = fin.tellg();

	cout << pos << endl;

	fin.close();                   //Close the file.

    //Tellp function tells the position of the put pointer. This function is defined in the output stream class.
	ofstream fout1;                //Create output stream.
	fout1.open("my.txt", ios::app); //Open file in append mode. 
	int pos1;
	pos1 = fout1.tellp();

	cout << "Put pointer is at " << pos1 << endl;

	fout1 << " Academy";           //Write text to the end of the file.

	pos1 = fout1.tellp();           //Get the new position of the pointer.

	cout << "Put pointer is at " << pos1 << endl;

	fout1.close();

	//Seekg is used to move the get pointer to a desired location with respect to a reference point. (istream)
	//Reference point: beg, cur, end
	//seekg(number of bytes, reference point)
	ifstream fin3;
	char A[10];

	fin3.open("my.txt");

	for (int i = 0; i < 10; i++) {

		A[i] = 0;
	}

	fin3.seekg(-3, ios_base::end);

	fin3.read(A, 3);

	for (int i = 0; A[i] != 0; i++) {
		cout << A[i];
	}

	fin3.close();

	//seekp is used to move pointer to a reference point. Can be used to modify the file. 
	//seekp(number of bytes, reference point) reference point = beg, cur or end.
	ofstream fout4;
	char A1[8] = "Academy";

	fout4.open("my.txt", ios::in);

	fout4.seekp(3, ios_base::beg);

	fout4.write(A1, 8);

	fout4.close();

	//Example of writing an object to a file.
	student s;
	ofstream file;
	
	file.open("data.txt", ios::out);
	if (!file) { //If we are not able to read or open the file, then it will be false.
		cout << "Error in creating file.." << endl;
		return 0;
	}

	cout << "\nFile created successfully." << endl;

	s.getData(); //Read the data from the user.

	/*
	(char*)&s is used to point at the start of an object and sizeof(s)
	calculates the number of bytes copied in file
	*/

	file.write((char*)&s, sizeof(s));

	file.close(); //Close the file

	cout << "\n File saved and closed successfully." << endl;

	ifstream file1; //Open the file created

	file1.open("data.txt", ios::in);
	if (!file1) {
		cout << "Error in opening file.";
		return 0;
	}

	//Read data from file
	file1.read((char*)&s, sizeof(s));

	s.showData();

	file1.close();

	return EXIT_SUCCESS;
}

