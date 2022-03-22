#include<iostream>
using namespace std;
class aClass
{
private:
	char* pchs; // a char-type array pointed by pointer pchs
	int length; // length of the array
public:
	// (1) constructor, to set the array length to len, to allocate a char-type 
	// array of the given length pointed by pchs, and to initialise the array 
	// elements to random ASCII codes each with a value 97 + rand() % 26
	aClass(int len);
	// (2) destructor, to free the memory used by the array 
	~aClass();
	// (3) function, to print the elements of the array
	void print() const;
	// (4) function, to search the array for the last occurrence of the 
	// character x specified in the parameter; it returns the index of the last 
	// occurrence of the character found, or -1 if no matches are found.
	int find_last_of(char x) const;
};
#pragma once
