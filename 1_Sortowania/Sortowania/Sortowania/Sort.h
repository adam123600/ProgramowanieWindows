#pragma once

#include "stdafx.h"
#include <stdlib.h>

typedef void(pFSort)(int*, int);

void BubbleSort(int* pTab, int nSize); // sortowanie bšbelkowe
void InsertionSort(int* pTab, int nSize); // sortowanie przez wstawianie
void SelectionSort(int* pTab, int nSize); // sortowanie przez wybieranie
void MixedSort(int* pTab, int nSize); // sortowanie mieszane
void HalfSort(int* pTab, int nSize); // sortowanie przez wstawianie po³ówkowe
void MergeSort(int* pTab, int* pTabHelp, int nSize, int l, int r); // sortowanie przez scalanie
void HeapSort(int* pTab, int nSize); // sortowanie przez kopcowanie
void QuickSort(int* pTab, int l, int r); // sortowanie szybkie
void Sort(int* pTab, int nSize); // sortowanie przez laczenie naturalne

// 
//void RandomNumber(int* pTab, int nSize); // zapelnianie losowymi
void CopyTab(int* pTabCopy, int* pTabOrginal, int nSize); // kopiowanie tablicy
void Sort(int* pTabO, int* pTabI, pFSort sort, int nSize,
	unsigned int& sortTime, unsigned int& maxSortTime); // funcja sortujaca

