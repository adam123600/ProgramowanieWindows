
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CSortowaniaView

IMPLEMENT_DYNCREATE(CSortowaniaView, CView)

BEGIN_MESSAGE_MAP(CSortowaniaView, CView)
END_MESSAGE_MAP()

// CSortowaniaView construction/destruction

CSortowaniaView::CSortowaniaView()
{
	// TODO: add construction code here
	m_pClientRect = new CRect();
	m_pPenCoordinateSystem = new CPen(PS_SOLID, 1, BLACK);
}

CSortowaniaView::~CSortowaniaView()
{
	delete this->m_pClientRect;
	delete this->m_pPenCoordinateSystem;
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
	GetClientRect(m_pClientRect);

	this->maxSortTime = pDoc->getMaxSortTime();

	drawCoordinateSystem(pDC);

	if (pDoc->getAllSortsStatus())
		drawAllSorts(pDC, pDoc);
	
	else if (pDoc->getBasicSortsStatus())
		drawBasicSorts(pDC, pDoc);

	else if (pDoc->getQuickSortsStatus())
		drawQuickSorts(pDC, pDoc);
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

void CSortowaniaView::drawAllSorts(CDC* pDC, CSortowaniaDoc* pDoc)
{
	CString str;

	str.LoadStringW(IDS_STRING_BUBBLE);
	drawRectangle(pDC, pDoc->getBubbleSortTime(), 188, RED);
	pDC->TextOutW(210, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_INSERTION);
	drawRectangle(pDC, pDoc->getInsertionSortTime(), 364, GREEN);
	pDC->TextOutW(383, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_HALF);
	drawRectangle(pDC, pDoc->getHalfSortTime(), 540, YELLOW);
	pDC->TextOutW(570, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_SELECTION);
	drawRectangle(pDC, pDoc->getSelectionSortTime(), 716, RGB(181, 1, 255));
	pDC->TextOutW(730, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_QUICK);
	drawRectangle(pDC, pDoc->getQuickSortTime(), 892, RGB(101, 191, 173));
	pDC->TextOutW(916, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_HEAP);
	drawRectangle(pDC, pDoc->getHeapSortTime(), 1068, RGB(105, 100, 214));
	pDC->TextOutW(1090, bottomCoordinateSystem.y + 20, str);
}

void CSortowaniaView::drawBasicSorts(CDC * pDC, CSortowaniaDoc * pDoc)
{
	CString str;

	str.LoadStringW(IDS_STRING_BUBBLE);
	drawRectangle(pDC, pDoc->getBubbleSortTime(), 188, RED);
	pDC->TextOutW(210, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_INSERTION);
	drawRectangle(pDC, pDoc->getInsertionSortTime(), 364, GREEN);
	pDC->TextOutW(383, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_HALF);
	drawRectangle(pDC, pDoc->getHalfSortTime(), 540, YELLOW);
	pDC->TextOutW(570, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_SELECTION);
	drawRectangle(pDC, pDoc->getSelectionSortTime(), 716, RGB(181, 1, 255));
	pDC->TextOutW(730, bottomCoordinateSystem.y + 20, str);
}

void CSortowaniaView::drawQuickSorts(CDC * pDC, CSortowaniaDoc * pDoc)
{
	CString str;

	str.LoadStringW(IDS_STRING_QUICK);
	drawRectangle(pDC, pDoc->getQuickSortTime(), 892, RGB(101, 191, 173));
	pDC->TextOutW(916, bottomCoordinateSystem.y + 20, str);

	str.LoadStringW(IDS_STRING_HEAP);
	drawRectangle(pDC, pDoc->getHeapSortTime(), 1068, RGB(105, 100, 214));
	pDC->TextOutW(1090, bottomCoordinateSystem.y + 20, str);
}

void CSortowaniaView::drawCoordinateSystem(CDC* pDC)
{
	CPen* pOldPen = pDC->SelectObject(m_pPenCoordinateSystem);

	std::pair<int, int> LeftTop(100, 0.1 * m_pClientRect->Height());
	std::pair<int, int> MiddlePoint(100, 0.9 * m_pClientRect->Height());
	std::pair<int, int> BottomRight(1250, 0.9 * m_pClientRect->Height());

	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines;

	topCoordinateSystem.x = 100;
	topCoordinateSystem.y = 0.1 * m_pClientRect->Height();
	bottomCoordinateSystem.x = 100;
	bottomCoordinateSystem.y = 0.9 * m_pClientRect->Height();

	for (int i = 0; i < SIZE_LINES + 1; i++)
	{
		std::pair<std::pair<int, int>, std::pair<int, int>> s;
		s.first.first = 100;
		s.first.second = (0.8 * m_pClientRect->Height() / SIZE_LINES) * i + 0.1 * m_pClientRect->Height();
		s.second.first = 1250;
		s.second.second = (0.8 * m_pClientRect->Height() / SIZE_LINES) * i + 0.1 * m_pClientRect->Height();

		lines.push_back(s);
	}

	std::unique_ptr<CoordinateSystem> cs{ new CoordinateSystem(LeftTop, MiddlePoint, BottomRight, lines) };

	cs->paintCoordinateSystemWithLines(pDC, maxSortTime);

	pDC->SelectObject(pOldPen);
}

void CSortowaniaView::drawRectangle(CDC* pDC, const int& sortTime, int positionOnX, COLORREF color)
{
	POINT p1;
	POINT p2;

	p1.x = positionOnX;
	double temp = 1 - ((double)sortTime / (double)maxSortTime);
	p1.y = (bottomCoordinateSystem.y - topCoordinateSystem.y) * temp + topCoordinateSystem.y;

	p2.x = positionOnX + 88;
	p2.y = bottomCoordinateSystem.y;

	CRect r1(p1, p2);
	CColorRect cr1(&r1, 1, BLACK, color);

	cr1.PaintColorRect(pDC);
}
