#pragma once

#include <string>

class Sorty
{
public:
	Sorty();
	~Sorty();

public:
	unsigned int getSortTime(const std::string& sortName);
	void setSortTime(const unsigned int& time, const std::string& sortName);
	void randomNumbers(int* pTab, const int& size);

private:
	unsigned int selectionSortTime;
	unsigned int insertionSortTime;
	unsigned int bubbleSortTime;
	unsigned int halfSortTime;
	unsigned int quickSortTime;
	unsigned int heapSortTime;
};

