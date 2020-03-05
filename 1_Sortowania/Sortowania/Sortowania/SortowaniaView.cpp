
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
}

CSortowaniaView::~CSortowaniaView()
{
	delete this->m_pClientRect;
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
	/*CRect r1(50, 50, 500, 500);
	CColorRect* colorRect = new CColorRect(&r1, 2, RED, GREEN);
	colorRect->PaintColorRect(pDC);*/

	//rysowanieSiatki(pDC);


	
	//GetWindowRect(this->m_pClientRect);
	/*CRect* ASD = new CRect();

	GetClientRect(ASD);
	CRect r1(50, 50, ASD->right * 0.6, ASD->bottom * 0.7);
	CRect r2(50, 50, 200, 200);
	pDC->Rectangle(&r1);*/
	//CColorRect* cRect = new CColorRect(&r1, 2, RED, GREEN);

	drawCoordinateSystem(pDC);
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
	
	std::pair<int, int> LT(20, 20);
	std::pair<int, int> MP( 20, 0.9 * m_pClientRect->bottom);
	std::pair<int, int> BR(0.8 * m_pClientRect->right, 0.9 * m_pClientRect->bottom);

	if (MP.second < 20)
	{
		MP.second = 20;
		BR.second = 20;
	}

	if (BR.first < 200)
	{
		BR.first = 200;
	}

	std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> lines;

	for (int i = 0; i < SIZE_LINES - 1; i++)
	{

		std::pair<std::pair<int, int>, std::pair<int, int>> s;
		s.first.first = 20;
		s.first.second = m_pClientRect->bottom * i / SIZE_LINES;
		s.second.first = 0.8 * m_pClientRect->right;
		s.second.second = i * m_pClientRect->bottom / SIZE_LINES;
		
		if (s.second.first < 200)
		{
			s.second.first = 200;
		}

		if (s.first.second < 20)
		{
			s.first.second = 20;
			s.second.second = 20;
		}

		lines.push_back(s);
	}

	CoordinateSystem* cs = new CoordinateSystem(LT, MP, BR, lines);
	cs->paintCoordinateSystemWithLines(pDC);

}