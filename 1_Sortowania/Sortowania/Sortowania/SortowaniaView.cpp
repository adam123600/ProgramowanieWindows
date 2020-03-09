
// SortowaniaView.cpp : implementation of the CSortowaniaView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sortowania.h"
#endif

#include "SortowaniaDoc.h"
#include "SortowaniaView.h"
#include "Sort.h"

#include "ColorRect.h"
#include "CoordinateSystem.h"

#include <iostream>
#include <utility>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RED RGB(255, 0, 0)
#define GREEN RGB(0, 255, 0)
#define SIZE_LINES 20
#define MAX_ELEMENTS_TAB 20000
#define SIZE_OF_SORTING 1

// CSortowaniaView

IMPLEMENT_DYNCREATE(CSortowaniaView, CView)

BEGIN_MESSAGE_MAP(CSortowaniaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSortowaniaView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSortowaniaView construction/destruction

CSortowaniaView::CSortowaniaView()
{
	// TODO: add construction code here
	this->m_pClientRect = new CRect();

	this->tabRandomNumbers = new int[MAX_ELEMENTS_TAB];
	this->tabSorted = new int[MAX_ELEMENTS_TAB];

	this->sortingTimes = new int[SIZE_OF_SORTING];
	flag = 3;
}

CSortowaniaView::~CSortowaniaView()
{
	delete this->m_pClientRect;
	delete[] this->tabRandomNumbers;
	delete[] this->sortingTimes;
	delete[] this->tabSorted;

	randomNumbersTab();
}

BOOL CSortowaniaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSortowaniaView drawing

void CSortowaniaView::OnDraw(CDC* pDC)
{
	CSortowaniaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	drawCoordinateSystem(pDC);
	drawRectangle(pDC);
	
}


// CSortowaniaView printing


void CSortowaniaView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSortowaniaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSortowaniaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSortowaniaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSortowaniaView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSortowaniaView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSortowaniaView diagnostics

#ifdef _DEBUG
void CSortowaniaView::AssertValid() const
{
	CView::AssertValid();
}

void CSortowaniaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSortowaniaDoc* CSortowaniaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSortowaniaDoc)));
	return (CSortowaniaDoc*)m_pDocument;
}
#endif //_DEBUG


// CSortowaniaView message handlers

void CSortowaniaView::drawCoordinateSystem(CDC* pDC)
{
	GetClientRect(m_pClientRect);
	
	std::pair<int, int> LT(20, 0.1 * m_pClientRect->Height());
	std::pair<int, int> MP( 20, 0.9 * m_pClientRect->Height());
	std::pair<int, int> BR(700, 0.9 * m_pClientRect->Height());

	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines;

	for (int i = 0; i < SIZE_LINES + 1; i++)
	{
		std::pair<std::pair<int, int>, std::pair<int, int>> s;
		s.first.first = 20;
		s.first.second = (0.8 * m_pClientRect->Height() / SIZE_LINES) * i + 0.1 * m_pClientRect->Height();
		s.second.first = 700;
		s.second.second = (0.8 * m_pClientRect->Height() / SIZE_LINES) * i + 0.1 * m_pClientRect->Height();
	
		lines.push_back(s);
	}

	CoordinateSystem* cs = new CoordinateSystem(LT, MP, BR, lines);

	cs->drawObject(pDC);
}

void CSortowaniaView::drawRectangle(CDC* pDC)
{
	GetClientRect(m_pClientRect);

	//CRect r1(0.8 * m_pClientRect->right, 5, 2, 200);
	POINT temp;
	/*temp.x = 40;
	temp.y = 100 + 0.45 * m_pClientRect->bottom;*/
	
	POINT temp2;
	/*temp2.x = 60;
	temp2.y = 0.9 * m_pClientRect->bottom;*/

	
	//for (int i = 0; i < SIZE_LINES - 1; i++)
	//{
		temp.x = 40;
		temp.y = 200 - ((m_pClientRect->bottom * 0.1 ) );
		//temp.y = 200;

		temp2.x = 60;
		temp2.y = 0.9 * m_pClientRect->bottom;
	
	CRect r1(temp, temp2);
	
	CColorRect* r1C = new CColorRect(&r1, 2, RED, GREEN);
	

	// ***********************************


	POINT t3;
	POINT t4;

	// wywolanie sorta
	/*DWORD startTime = GetTickCount();
	BubbleSort(this->tabRandomNumbers, MAX_ELEMENTS_TAB);
	DWORD endTime = GetTickCount();
	*/
	//endTime = endTime - startTime;
	/*if (!flag)
	{
		randomNumbersTab();
		sort();
		flag = 1;
	}*/

	t3.x = 80;
	//t3.y = this->sortingTimes[0] + ((m_pClientRect->bottom * 0.9));
	t3.y = 200;
	t4.x = 100;
	t4.y = 0.9 * m_pClientRect->bottom;
	CRect r2(t3, t4);
	CColorRect* r2C = new CColorRect(&r2, 2, RED, GREEN);
	r2C->drawObject(pDC);
	
	
	r1C->drawObject(pDC);
}

void CSortowaniaView::randomNumbersTab()
{
	srand(time(NULL));

	for (int i = 0; i < MAX_ELEMENTS_TAB; i++)
		this->tabRandomNumbers[i] = rand();
}

void CSortowaniaView::sort()
{
	memcpy(this->tabSorted, this->tabRandomNumbers, MAX_ELEMENTS_TAB);

	DWORD startTime = GetTickCount();
	BubbleSort(tabSorted, MAX_ELEMENTS_TAB);
	DWORD endTime = GetTickCount();

	endTime = endTime - startTime;

	this->sortingTimes[0] = endTime;

}