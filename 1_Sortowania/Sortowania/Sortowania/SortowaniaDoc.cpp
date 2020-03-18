
// SortowaniaDoc.cpp : implementation of the CSortowaniaDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sortowania.h"
#endif

#include "SortowaniaDoc.h"

#include <propkey.h>
#include <memory>

// ****

#include "Sort.h"

#define LICZBA_ELEMENTOW 20000
// ****

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSortowaniaDoc

IMPLEMENT_DYNCREATE(CSortowaniaDoc, CDocument)

BEGIN_MESSAGE_MAP(CSortowaniaDoc, CDocument)
	ON_COMMAND(ID_SORTOWANIA_PROSTE, &CSortowaniaDoc::OnSortowaniaProste)
END_MESSAGE_MAP()


// CSortowaniaDoc construction/destruction

CSortowaniaDoc::CSortowaniaDoc()
{
	// TODO: add one-time construction code here

	//std::unique_ptr<Sorty> sorty{ new Sorty() };
	srand(time(NULL));
	maxSortTime = 0;
	bubbleSortTime = 0;
	insertionSortTime = 0;
	halfSortTime = 0;
	selectionSortTime = 0;
	heapSortTime = 0;

	basicSorts = false;
}

CSortowaniaDoc::~CSortowaniaDoc()
{
}

BOOL CSortowaniaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSortowaniaDoc serialization

void CSortowaniaDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSortowaniaDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CSortowaniaDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSortowaniaDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSortowaniaDoc diagnostics

#ifdef _DEBUG
void CSortowaniaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSortowaniaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSortowaniaDoc commands


unsigned int CSortowaniaDoc::getBubbleSortTime()
{
	return bubbleSortTime;
}

unsigned int CSortowaniaDoc::getInsertionSortTime()
{
	return insertionSortTime;
}

unsigned int CSortowaniaDoc::getHalfSortTime()
{
	return halfSortTime;
}

unsigned int CSortowaniaDoc::getSelectionSortTime()
{
	return selectionSortTime;
}

unsigned int CSortowaniaDoc::getQuickSortTime()
{
	return quickSortTime;
}

unsigned int CSortowaniaDoc::getHeapSortTime()
{
	return heapSortTime;
}

unsigned int CSortowaniaDoc::getMaxSortTime()
{
	return maxSortTime;
}

bool CSortowaniaDoc::getBasicSortsStatus()
{
	return basicSorts;
}

void CSortowaniaDoc::randomNumbers(int* pTab, const int& size)
{
	
	for (int i = 0; i < size; i++)
		pTab[i] = std::rand() % size;
}

void CSortowaniaDoc::OnSortowaniaProste()
{
	int tab[LICZBA_ELEMENTOW];
	int tabCopy[LICZBA_ELEMENTOW];

	randomNumbers(tab, LICZBA_ELEMENTOW);

	maxSortTime = 0;

	Sort(tabCopy, tab, BubbleSort, LICZBA_ELEMENTOW, bubbleSortTime, maxSortTime);
	Sort(tabCopy, tab, InsertionSort, LICZBA_ELEMENTOW, insertionSortTime, maxSortTime);
	Sort(tabCopy, tab, HalfSort, LICZBA_ELEMENTOW, halfSortTime, maxSortTime);
	Sort(tabCopy, tab, SelectionSort, LICZBA_ELEMENTOW, selectionSortTime, maxSortTime);

	/*CString s;
	s.Format(L"%d %d\n%d %d", bubbleSortTime*(-1), insertionSortTime*(-1),
		halfSortTime*(-1), selectionSortTime*(-1));
	AfxMessageBox(s);*/
	basicSorts = true;
	UpdateAllViews(NULL);
}







