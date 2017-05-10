#include "stdafx.h"

#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
	Node(int value, Node* left, Node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}

	int getValue() const
	{
		return value;
	}

	Node* getLeft() const
	{
		return left;
	}

	Node* getRight() const
	{
		return right;
	}

private:
	int value;
	Node* left;
	Node* right;
};

class BinarySearchTree
{
public:
	static bool contains(const Node& root, int value)
	{
		return checkContains(&root, value);
	}

private:

	static bool checkContains(const Node* root, int value) {
		if (nullptr == root)
			return false;

		if (value == root->getValue())
			return true;

		if (value < root->getValue())
			return checkContains(root->getLeft(), value);

		return checkContains(root->getRight(), value);
	}
};

#ifndef RunTests
int main()
{
	Node n1(1, NULL, NULL);
	Node n3(3, NULL, NULL);
	Node n2(2, &n1, &n3);

	std::cout << BinarySearchTree::contains(n2, 3);
}
#endif