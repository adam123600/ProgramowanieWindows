#pragma once

#include "NodeThreaded.h"

class ThreadedTree
{
public:
	ThreadedTree();
	~ThreadedTree();

private:
	NodeThreaded* pRoot;

	void insert(const int value);
	NodeThreaded* nextItemInorder(NodeThreaded* pCurrentNode);
	void deleteNode(NodeThreaded* pNode);
};

