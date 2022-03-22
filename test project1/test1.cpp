#include<iostream>
#include"aClass.h"
using namespace std;
int alternating_sum(int n)
{
	int sum = 1;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			sum -= i;
		else
		{
			sum += i;
		}
	}
	return sum;
}

void pointer_arithmetic(int n) {
	// an n-element array pointed to by pd
	double* pd = new double[n];
	if (pd != NULL) {
		// assign 0, 1, ..., n-1 to array elements pointed to by pd
		for (int i = 0; i < n; i++)
			*(pd+i) = i;
		// print the array elements
		for (int i = 0; i < n; i++)
			cout << *(pd+i) << " ";
		// free the array space
		delete[] pd;
	}
}

int main1()
{
	cout << alternating_sum(100) << endl;
	return 0;
}

int main2()
{
	aClass pi(100);
	pi.print();
	cout << "the position of y is: " << pi.find_last_of('y') << endl;
	return 0;
}

int main()
{
	pointer_arithmetic(10);
	return 0;
}