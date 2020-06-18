#pragma once

struct NodeThreaded
{
	int key;
	NodeThreaded* pLeftNode;
	NodeThreaded* pRightNode;

	bool lTag;
	bool rTag;
};