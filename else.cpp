

#if defined __WIN32
#define PLATFORM "Windows"
#elif defined __linux
 #define PLATFORM "Linux"
 #endif

 #include <iostream>
 using namespace std;

 int main(){

    cout << PLATFORM << " System " << endl;
    
    if (PLATFORM == "Windows")
    cout << "Performing windows-only tasks..."<< endl;

    if (PLATFORM == "Linux")
    cout << "Performing Linux-only tasks..." << endl;

    return 0;
 }

