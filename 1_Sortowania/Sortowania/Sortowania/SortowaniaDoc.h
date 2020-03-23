
// SortowaniaDoc.h : interface of the CSortowaniaDoc class
//


#pragma once

#include "Sort.h"
#include "Constants.h"

#include <iostream>


class CSortowaniaDoc : public CDocument
{
protected: // create from serialization only
	CSortowaniaDoc();
	DECLARE_DYNCREATE(CSortowaniaDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CSortowaniaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSortowaniaProste();
	afx_msg void OnSortowaniaSzybkie();
	afx_msg void OnSortowaniaWszystkie();

public:
	unsigned int getBubbleSortTime();
	unsigned int getInsertionSortTime();
	unsigned int getHalfSortTime();
	unsigned int getSelectionSortTime();
	unsigned int getQuickSortTime();
	unsigned int getHeapSortTime();

	unsigned int getMaxSortTime();
	void setMaxSortTime(unsigned int maxTime);

	bool getBasicSortsStatus();
	bool getQuickSortsStatus();
	bool getAllSortsStatus();

	void setBasicSortsStatus(bool status);
	void setQuickSortsStatus(bool status);
	void setAllSortsStatus(bool status);

private:
	void randomNumbers(int* pTab, const int& size);

private:
	unsigned int bubbleSortTime;
	unsigned int insertionSortTime;
	unsigned int halfSortTime;
	unsigned int selectionSortTime;
	unsigned int quickSortTime;
	unsigned int heapSortTime;

	unsigned int maxSortTime;

	bool basicSorts;
	bool quickSorts;
	bool allSorts;
};
