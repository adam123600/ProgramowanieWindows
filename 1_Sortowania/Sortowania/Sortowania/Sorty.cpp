#include "stdafx.h"
#include "Sorty.h"


Sorty::Sorty()
{
}


Sorty::~Sorty()
{
}

unsigned int Sorty::getSortTime(const std::string& sortName)
{
	if (sortName == "SelectionSort")
		return selectionSortTime;

	else if (sortName == "InsertionSort")
		return insertionSortTime;

	else if (sortName == "BubbleSort")
		return bubbleSortTime;

	else if (sortName == "HalfSort")
		return halfSortTime;

	else if (sortName == "QuickSort")
		return quickSortTime;

	else if (sortName == "HeapSort")
		return heapSortTime;

	else
		return 0;
}

void Sorty::setSortTime(const unsigned int& time, const std::string& sortName)
{
	if (sortName == "SelectionSort")
	{
		selectionSortTime = time;
		return;
	}

	else if (sortName == "InsertionSort")
	{
		insertionSortTime = time;
		return;
	}

	else if (sortName == "BubbleSort")
	{
		bubbleSortTime = time;
		return;
	}

	else if (sortName == "HalfSort")
	{
		halfSortTime = time;
		return;
	}

	else if (sortName == "QuickSort")
	{
		quickSortTime = time;
		return;
	}

	else if (sortName == "HeapSort")
	{
		heapSortTime = time;
		return;
	}

	else
		return;
}

void Sorty::randomNumbers(int* pTab, const int& size)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
		pTab[i] = rand() % size;
}