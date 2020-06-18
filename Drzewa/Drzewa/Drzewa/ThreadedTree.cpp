#include "stdafx.h"
#include "ThreadedTree.h"


ThreadedTree::ThreadedTree()
{
	pRoot = new NodeThreaded();
	pRoot->key = 0;
	pRoot->pLeftNode = pRoot;
	pRoot->pRightNode = pRoot;
	pRoot->lTag = false;
	pRoot->rTag = true;
}


ThreadedTree::~ThreadedTree()
{
}

void ThreadedTree::insert(const int value)
{
	NodeThreaded* pNewItem = new NodeThreaded();
	pNewItem->key = value;

	if (pRoot == pRoot->pLeftNode && pRoot == pRoot->pRightNode)
	{
		pNewItem->pLeftNode = pRoot;
		pNewItem->pRightNode = pRoot;

		pRoot->pLeftNode = pNewItem;
		pRoot->lTag = true;

		pNewItem->lTag = false;
		pNewItem->rTag = false;
	}

	else
	{
		NodeThreaded* pCurrentNode = pRoot->pLeftNode;
		
		while (true)
		{
			if (pCurrentNode->key > pNewItem->key)
			{
				if (pCurrentNode->lTag == false)
				{
					pNewItem->pLeftNode = pCurrentNode->pLeftNode;
					pCurrentNode->pLeftNode = pNewItem;
					pCurrentNode->lTag = true;
					pNewItem->lTag = false;
					pNewItem->rTag = false;
					pNewItem->pRightNode = pCurrentNode;
					break;
				}
				pCurrentNode = pCurrentNode->pLeftNode;
			}
			else
			{
				if (pCurrentNode->rTag == false) 
				{
					pNewItem->pRightNode = pCurrentNode->pRightNode;
					pCurrentNode->pRightNode = pNewItem;
					pCurrentNode->rTag = true;
					pNewItem->lTag = false;
					pNewItem->rTag = false;
					pNewItem->pLeftNode = pCurrentNode;
					break;
				}
				pCurrentNode = pCurrentNode->pRightNode;
			}
		}
	}

}

NodeThreaded * ThreadedTree::nextItemInorder(NodeThreaded * pCurrentNode)
{
	return nullptr;
}

void ThreadedTree::deleteNode(NodeThreaded * pNode)
{
}
