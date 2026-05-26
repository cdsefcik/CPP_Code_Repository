#ifndef SEARCHHEADER_H
#define _SEARCHHEADER_H

#ifdef __DLLEXPORT
#define API_DEF __declspec(dllexport)
#else 
#define API_DEF __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

	API_DEF int linearSearch(int* a, int n, int key);
	
#ifdef __cplusplus
}

#endif

#endif // !SEARCHHEADER_H




