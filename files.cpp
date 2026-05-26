


#include <fstream>
#include <string>
#include <iostream>
using namespace std;


int main() {

string poem = "\n\t I never saw a man who looked";
poem.append("\n\t With such a wistful eye");
poem.append("\n\t Upon that little tent of blue");
poem.append("\n\t Which prisoners call the sky");

ofstream writer("Poem.txt");

if(!writer){
  cout << "Error opening file for output" << endl;
  return -1; 
}
writer << poem << endl;
writer.close();


    return 0;
}