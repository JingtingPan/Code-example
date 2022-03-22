#include<iostream>
#include"TreeNode.h"

using namespace std;

int alternating_sum(int n)
{
	int sum = 0;
	if (n < 1)
		return sum;
	if (n % 2 == 1) sum += n;
	else sum -= n;
	return sum + alternating_sum(n - 1);
}

template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree) {
	if (tree == NULL) // key not in tree, insert
		tree = new TreeNode<T>(key);
	else if (key < tree->item)
		tree->leftTree = search(key, tree->leftTree);
	else if (key > tree->item)
		tree->rightTree = search(key, tree->rightTree);
	return tree;
}

template<typename T>
void print(TreeNode<T>* tree)
{
	if (tree == NULL);
	else
	{
		cout << tree->item << " ";
		print(tree->leftTree);
		print(tree->rightTree);
	}
}


int main1()
{
	cout << alternating_sum(100) << endl;
	return 0;
}

int main()
{
	TreeNode<int>* tree = NULL;
	tree = search(212, tree);
	tree = search(111, tree);
	tree = search(20, tree);
	tree = search(150, tree);
	tree = search(531, tree);
	tree = search(412, tree);
	tree = search(718, tree);
	print(tree);
	cout << "The complexity of the balanced BST is O(log2n)" << endl;
	return 0;
}