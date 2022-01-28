#include<iostream>
#include"BinarySearchTree.h"

template <typename K, typename V>
int BST<K,V>::calculateheight(Node* Node)//function to calculate height of BST
{
	if (Node == NULL)
		return -1;
	else
	{
		int leftsubheight = calculateheight(Node->left);
		int rightsubheight = calculateheight(Node->right);

		if (leftsubheight > rightsubheight)
			return leftsubheight + 1;
		else
			return rightsubheight + 1;
	}
}

//function to create a binary search tree with minimum height
template <typename K, typename V>
void insert(BST<K, V>& bst, int array[], int low, int high)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;//calculating mid of array

		bst.Insert(array[mid], array[mid]);//inserting middle element into Tree

		insert<K,V>(bst, array, low, mid - 1);//repeating the process above for left side of array
		insert<K,V>(bst, array, mid + 1, high);//repeating the process above for right side of array
	}
}

int insert(int array[], int size)// to insert an array into BST
{
	if (size > 0)
	{
		BST<int, int> bst;
		insert(bst, array, 0, size - 1);

		BST<int, int>::InorderIterator it;

		for (it = bst.begin(); !it.end(); it++)
			cout << (*it).first << "  " << (*it).second << endl;

		cout << endl;

		return bst.calculateheight(bst.begin());
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Height of BST is " << insert(arr, size) << endl;
}