//Here are some header guards used for conditional compilation

//EXE different header files for linux or windows:

#ifdef WINDOWS
    #include "my_windows_header.h"
#else
    #include "my_linux_header.h"
#endif

//Stops header files from being included twice:
#ifndef MY_WINDOWS_HEADER
#define MY_WINDOWS_HEADER

#endif
