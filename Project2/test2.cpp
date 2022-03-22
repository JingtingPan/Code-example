#include<iostream>
#include<ctime>
#include"Stack.h"

using namespace std;
int main1()
{
	Stack<string>* ps0 = new Stack<string>;
	string item;
	cout << "Enter a sentence ending with a '*'" << endl;
	cin >> item;
	while (item != "*") 
	{
		ps0->push(item);
		cin >> item;
	}
	ps0->print();
	Stack<string> s1 = *ps0;
	s1.print();
	Stack<string>* ps2 = new Stack<string>;
	int len = ps0->size();
	for (int i = 0; i < len; i++)
		ps2->push(ps0->pop());
	ps2->print();
	if (*ps0 == s1)
		cout << "The two stacks are identical" << endl;
	else cout << "The two stacks are not identical" << endl;
	delete ps0;
	delete ps2;
	return 0;
}

int main2()
{
	Stack<int> pch;
	srand((int)time(0));
	for (int i = 0; i < 20; i++)
		pch + rand() % 9;
	pch.print();
	cout << "the position of the second occurrence of 8 is: " << pch.search(8, 2) << endl;
	return 0;

}

int main()
{
	Stack<int> pch;
	srand((int)time(0));
	for (int i = 0; i < 20; i++)
		pch + rand() % 9;
	pch.print();
	pch.replace(pch, 8, 0);
	pch.print();
	return 0;
}