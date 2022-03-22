#include<iostream>
#include"List.h"
#include<ctime>
using namespace std;
// remove an item at position p, from an array list with size items pointed by List
template <typename T> T remove(T* list, int& size, int p) {
	if (p >= 0 && p < size) {
		T item = list[p];
		for (int i = p + 1; i < size; i++)
			list[i - 1] = list[i];
		size--;
		return item;
	}
	else {
		cout << "Unable remove at position " << p << endl;
		exit(1);
	}
}


// maxmimum size of array list
constexpr int Max_ListSize = 1048576;
int main1()
{
	/* array list */
	srand(1792);
	// (1). dynamically allocate an int-type array list, alist, of Max_ListSize,
	// populate the array with Max_ListSize random numbers, from the 1st 
	// location to the last location, and initialise the number of items in 
	// alist int size = Max_ListSize
	int* alist = new int[Max_ListSize];
	for (int i = 0; i < Max_ListSize; i++)
		alist[i] = rand() % 5000;
	int size = Max_ListSize;
	// (2). time removing 5000 items from alist, by calling the above remove 
	// function, at random positions p = rand() % size; print the time (ms) 
	// used to complete the operation
	time_t startTime = clock();
	for (int i = 0; i < 5000; i++)
		remove(alist, size, rand() % size);
	time_t endTime = clock();
	cout << "Time reading (ms) for operation (2) "<<(endTime - startTime) / 1000.0 << endl;
	// (3). time 500000 random accesses to alist to do the assignment 
	// int x = alist[p], where p = rand() % size; print the time (ms) used to 
	// complete the operation
	startTime = clock();
	for (int i = 0; i < 500000; i++)
		int x = alist[rand() % size];
	endTime = clock();
	cout << "Time reading (ms) for operation (3): "<<(endTime - startTime) / 1000.0 << endl;
	/* linked list */
	srand(1792);
	// (4). declare an int-type List object llist, and call the insert_end method 
	// to insert Max_ListSize random numbers
	List<int> llist;
	for (int i = 0; i < size; i++)
		llist.insert_end(rand() % size);
	// (5). time removing 5000 items from llist, by calling the remove method, at 
	// random positions p = rand() % llist.size(); print the time (ms) 
	// used to complete the operation
	startTime = clock();
	for (int i = 0; i < 5000; i++)
		llist.remove(rand() % size);
	endTime = clock();
	cout << "Time reading (ms) for operation (5) " << (endTime - startTime) / 1000.0 << endl;
	// (6). time 500000 random accesses to llist to do the assignment
	// int x = llist.get(p), where p = rand() % llist.size(); print the 
	// time (ms) used to complete the operation
	startTime = clock();
	for (int i = 0; i < 500000; i++)
		int x = llist.get(rand() % size);
	endTime = clock();
	cout << "Time reading(ms) for operation(6) " << (endTime - startTime) / 1000.0 << endl;
	// (7). note the time taken for each of the above operations (2), (3), (5) and 
	// (6), put these times in place of the corresponding ??? in following 
	// statements and uncomment these statements to finish the program: 
	// cout << "Time reading (ms) for operation (2): " << ??? << endl;
	// cout << "Time reading (ms) for operation (3): " << ??? << endl;
	// cout << "Time reading (ms) for operation (5): " << ??? << endl;
	// cout << "Time reading (ms) for operation (6): " << ??? << endl;
	return 0;
}

//My finding is that the ability to random access,the arraylist is better than linkedlist
//and the ability to remove data,the arraylist is worse than linkedlist




List<string>* readWordSequence() {
	// word array & number of words in the array
	List<string>* st = new List<string>;
	// read & store words
	cout << "Type words to store, ending with a * :" << endl;
	string word;
	while (cin >> word) {
		if (word == "*")
			break;
		st->insert_end(word);
	}
	// print the array
	st->print();
	return st;
}

int main2()
{
	readWordSequence();
	return 0;
}

int main()
{
	List<int> pch;
	srand((int)time(0));
	for (int i = 0; i < 10; i++)
		pch.insert_end(rand() % 9);
	pch.print();
	pch.set(2, 20);
	pch.print();
	pch.setp(8);
	pch.set_next(30);
	cout << pch.get_next() << endl;
	pch.setp(6);
	pch.set_prev(40);
	cout << pch.get_next() << endl;
	pch.print();
	
}