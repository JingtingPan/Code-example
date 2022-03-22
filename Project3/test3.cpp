#include<iostream>
#include"List.h"
#include<ctime>

using namespace std;
void quickSort(int* a, int first, int last)
{
	// partition
	int i = first, j = last;
	int pivot = a[(first + last) / 2];  // not the median!
	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {  // swap
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
		}
	}
	// recursion
	if (first < i - 1) quickSort(a, first, i - 1);
	if (i < last) quickSort(a, i, last);
}

void printTopX(int* rand_array, int N, int X)
{
	quickSort(rand_array, 0, N);
	for (int i = N; i > N-X; i--)
	{
		cout << rand_array[i] << " ";
	}
	cout << endl;
}

List<int>* insertionSort(List<int>* l) {

	for (int i = 1; i < l->size(); i++) {
		// item in position i
		int item_i = l->get(i);
		int j = i - 1;
		// for positions from j to 0 find the 1st position j with item <= item_i 
		while (j >= 0 && l->get(j) > item_i)
		{
			l->set(j + 1, l->get(j));
			j--;
		}
			
		// insert item_i into position j + 1
		l->set(j + 1, item_i);
	}
	// complexity - where XXX is what you think the complexity is in terms of the 
	// order(s) of the size of the list
	cout << "The complexity of this list-based insertion sort is O(N^3)" << endl;
	return l;
}

int main1()
{
	srand((int)time(0));
	int N = 512;
	int* pi = new int[N];
	for (int i = 0; i < N; i++)
	{
		pi[i] = rand();
	}
	printTopX(pi, N, 5);
	printTopX(pi, N, 10);
	cout << "¡°The complexity of printTopX is O(Nlog2N)" << endl;
	return 0;

}

int main2()
{
	cout << "Suppose Quick Sort takes 5 ms to sort an array of size 512." << endl;
	// fill ... below and print out your answer
	cout << "Quick Sort (4096) should take 53.33 ms." << endl
		<< "Because: QuickSort of size 512 specific time complexity is O(512log512),and size of 4096 is O(4096log4096)" << endl
		<< "Therefore: if the time increases proportionaly the time should be 5*[(4096*12)/(512*9)]ms" << endl;
	return 0;
}

int main()
{
	int N = 20;
	List<int>* al = new List<int>[N];
	srand((int)time(0));
	for (int i = 0; i < N; i++)
		al->insert_end(rand() % 100);
	insertionSort(al);
	al->print();
	return 0;
}