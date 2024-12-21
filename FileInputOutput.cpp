#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<sstream>
#include <iomanip> //For the setprecision.


using namespace std;



/*
*This provides input and output examples for C++ from chapter 11.
*
*/

inline ios_base& general(ios_base& b) {
    b.setf(ios_base::fmtflags(0), ios_base::floatfield);
    return b;
}



inline void keep_window_open() {

    char ch; cin >> ch;

}



int main() {

    cin.unsetf(ios::dec);
    cin.unsetf(ios::oct);
    cin.unsetf(ios::hex);


    int a;
    int b;
    int c;
    int d;
    cin >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << endl;

    //Floating point output:
    cout << 1234.56789 << "\t\t(general)\n" //\t\t to line up the columns
        << fixed << 1234.56789 << "\t(fixed)\n"
        << scientific << 1234.56789 << "\t(scientific)\n";

    cout << general << std::setprecision(20) << 123456789.3452435 << endl;

    cout << setw(10)<<1234<<"|" << endl; //setw() sets a field width. Can be used to create files depended on field widths.

    //File stream open modes
    //ios_base::app = appends to the end of the file
    //ios_base::ate = at end, open and seek to end
    //ios_base::binary = binary mode, beware of system specific behavior
    //io_base::in = for reading
    //io_base::out for writing
    //ios_base::trunc truncate file to 0 length
    
    ofstream of1("Test1.txt"); //defaults to io_base::out
    ofstream if1("Test1.txt"); //defaults to io_base::in

    ofstream ofs("Test2.txt", ios_base::app); //append the file
    fstream fs("MyFile1.txt", ios_base::in | ios_base::out); //both in and out. The | is a bitwise operator. Can be used to combined modes.

    //Streams transform characters based on the object of a specified type, then writes it out. We could just print out bytes though, use binary

    //File positioning:
    //seekp() moves writing position:
    fs.seekp(10); //This moves the writing position
    fs << "This starts at the 10th Position" << endl;

    //This moves the reading position
    fs.seekg(10);
    char ch;
    fs >> ch;
    cout << ch << endl;

    fs.close();


        return EXIT_SUCCESS;
}
