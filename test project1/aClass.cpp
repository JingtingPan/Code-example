#include<iostream>
#include"aClass.h"
#include<ctime>
using namespace std;

// (1) constructor, to set the array length to len, to allocate a char-type 
	// array of the given length pointed by pchs, and to initialise the array 
	// elements to random ASCII codes each with a value 97 + rand() % 26
aClass::aClass(int len)
{
	length = len;
	pchs = new char[length];
	srand(time(0));
	for (int i = 0; i < length; i++)
	{
		pchs[i] = 97 + rand() % 26;
	}
}
// (2) destructor, to free the memory used by the array 
aClass::~aClass()
{
	length = 0;
	delete[]pchs;
}
// (3) function, to print the elements of the array
void aClass::print() const
{
	for (int i = 0; i < length; i++)
	{
		cout << pchs[i] << " ";
	}
	cout << endl;
}
// (4) function, to search the array for the last occurrence of the 
// character x specified in the parameter; it returns the index of the last 
// occurrence of the character found, or -1 if no matches are found.
int aClass::find_last_of(char x) const
{
	for (int i = length - 1; i > 0; i--)
	{
		if (pchs[i] == x)
			return i;
	}
	return -1;
}