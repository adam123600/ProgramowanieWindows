#include "stdafx.h"
#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
	pRoot = nullptr;
}


BinaryTree::~BinaryTree()
{
	deleteNode(pRoot);
	pRoot = nullptr;
}

NodeBinary * BinaryTree::getRoot()
{
	return pRoot;
}

void BinaryTree::insert(const int value)
{
	NodeBinary* pNode = new NodeBinary();
	pNode->pLeftNode = nullptr;
	pNode->pRightNode = nullptr;

	if (pRoot == nullptr)
	{
		pNode->key = value;
	}

	else
	{
		NodeBinary* pCurrentItem = pRoot;
		
		while (true)
		{
			if (pCurrentItem->key > pNode->key)
			{
				if (pCurrentItem->pLeftNode == nullptr)
				{
					pCurrentItem->pLeftNode = pNode;
					break;
				}
				pCurrentItem = pCurrentItem->pLeftNode;
			}
			else
			{
				if (pCurrentItem->pRightNode == nullptr)
				{
					pCurrentItem->pRightNode = pNode;
					break;
				}
				pCurrentItem = pCurrentItem->pRightNode;
			}
		}
	}
}

void BinaryTree::deleteNode(NodeBinary * pNode)
{
	if (pNode->pLeftNode != nullptr)
		deleteNode(pNode->pLeftNode);
	if (pNode->pRightNode != nullptr)
		deleteNode(pNode->pRightNode);

	delete pNode;
	pNode = nullptr;
}
