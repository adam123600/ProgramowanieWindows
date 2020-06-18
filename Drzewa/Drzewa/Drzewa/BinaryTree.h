#pragma once

#include "NodeBinary.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	NodeBinary* getRoot();

private:
	NodeBinary* pRoot;
	void insert(const int value);
	void deleteNode(NodeBinary* pNode);
};

