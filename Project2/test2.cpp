#include<iostream>
#include <string>

using namespace std;

int linearSearch(int* pi,int N,int key)
{
	for (int i = 0; i < N; i++)
	{
		if (pi[i] == key)
			return i;
	}
	return -1;
}

/* demonstration program for binary search */
// B1. implement binary search, below, through an int array pointed by pi from first 
// to last for a specified key number; return the index if found or -1 otherwise
int binarySearch(int* pi, int first, int last, int key) 
{
	if (first > last || pi == NULL)
		return -1;
	int m = (first + last)/2;
	if (pi[m] == key)
		return m;
	else if (key > pi[m])
		return binarySearch(pi, m + 1, last, key);
	else
		return binarySearch(pi, first, m - 1, key);
}

/* demonstration program for hashing-based search */
// H1. write a good hash function (such as the one used in the lecture notes), which 
// converts a string key to a hash index in a hash table of the given tableSize
size_t Hash_(string key, size_t tableSize)
{
	size_t index = 0;
	for (int i = 0; i < key.size(); i++)
		index = 37 * index + key[i];
	return index % tableSize;
}



/* demonstration program for linear search */
int main1()
{
	// L1. allocate an int array, pointed by pi, and store each number in an 
	// element of the array (e.g., pi[0] = 12, pi[1] = 211, ..., pi[7] = 4)
	// run three search tests
	int* pi = new int[8];
	pi[0] = 12;
	pi[1] = 211;
	pi[2] = 48;
	pi[3] = 501;
	pi[4] = 91;
	pi[5] = 82;
	pi[6] = 110;
	pi[7] = 4;
	for (int test = 1; test <= 3; test++) {
		// take a search request from keyboard
		cout << "Specify the number to be searched for: ";
		int key;
		cin >> key;
		// L2. implement linear search through the array for the 1st occurrence 
		// of the key number; print the index if found or -1 otherwise
		cout << "the first occurrence of " << key << " is " << linearSearch(pi, 8, key) << endl;
		// L3. complete the statement, where XXX is what you think the 
		// complexity is in terms of the order(s) of the size of the data set
		cout << "The complexity of the linear search is O(N)" << endl;
	}
	// L4. free the memory used by the array
	delete []pi;
	return 0;
}

int main2()
{
	// B2. allocate an int array, pointed by pi, and store each number in an 
	// element of the array
	int* pi = new int[8];
	pi[0] = 4;
	pi[1] = 12;
	pi[2] = 48;
	pi[3] = 82;
	pi[4] = 91;
	pi[5] = 110;
	pi[6] = 211;
	pi[7] = 501;
	// run three search tests
	for (int test = 1; test <= 3; test++) {
		// take a search request from keyboard
		cout << "Specify the number to be searched for: ";
		int key;
		cin >> key;
		// B3. call binarySearch to search for the key number; print the 
		// index if found or -1 otherwise
		cout << "the first occurrence of " << key << " is " << binarySearch(pi, 0, 7, key) << endl;
		// B4. complete the statement, where XXX is what you think the 
		// complexity is in terms of the order(s) of the size of the data set
		cout << "The complexity of the binary search is O(log2n)" << endl;
	}
	delete[] pi;
	return 0;
}

int main()
{
	// choose a suitable tableSize (e.g. 223), allocate an int array (i.e. the hash 
	// table) of this size pointed by pht
	int tableSize = 223;
	int* pht = new int[tableSize];
	// H2. store the numbers in the hash table, e.g., 12 in a location specified by 
	// Hash("12", tableSize)
	pht[Hash_("12", tableSize)]=12;
	pht[Hash_("211", tableSize)]=211;
	pht[Hash_("48", tableSize)]=48;
	pht[Hash_("501", tableSize)]=501;
	pht[Hash_("91", tableSize)]=91;
	pht[Hash_("82", tableSize)]=82;
	pht[Hash_("110", tableSize)]=110;
	pht[Hash_("4", tableSize)]=4;
	// run three search tests
	for (int test = 1; test <= 3; test++) {
		// take a search request from keyboard
		cout << "Specify the number to be searched for: ";
		int key;
		cin >> key;
		string  strkey = to_string(key);
		// H3. perform hashing-based search for the key number in the table; 
		// print the index if found or -1 otherwise
		if (pht[Hash_(strkey, tableSize)] == key)
			cout << "Hash index = " << Hash_(strkey, tableSize) << endl;
		else cout << "Hash index = -1" << endl;
		// H4. complete the statement, where XXX is what you think the 
		// complexity is in terms of a suitable measure
		cout << "The hashing-based search is potentially O(1)" << endl;
	}
	delete[] pht;
	return 0;
}