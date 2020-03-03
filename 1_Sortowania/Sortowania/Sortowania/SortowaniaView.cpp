
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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

}

CSortowaniaView::~CSortowaniaView()
{
}

BOOL CSortowaniaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSortowaniaView drawing

void CSortowaniaView::OnDraw(CDC* /*pDC*/)
{
	CSortowaniaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

//	CRect* s;
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
