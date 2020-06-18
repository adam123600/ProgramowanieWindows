
// DrzewaView.cpp : implementation of the CDrzewaView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Drzewa.h"
#endif

#include "DrzewaDoc.h"
#include "DrzewaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrzewaView

IMPLEMENT_DYNCREATE(CDrzewaView, CView)

BEGIN_MESSAGE_MAP(CDrzewaView, CView)
END_MESSAGE_MAP()

// CDrzewaView construction/destruction

CDrzewaView::CDrzewaView()
{
	// TODO: add construction code here

}

CDrzewaView::~CDrzewaView()
{
}

BOOL CDrzewaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDrzewaView drawing

void CDrzewaView::OnDraw(CDC* /*pDC*/)
{
	CDrzewaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDrzewaView diagnostics

#ifdef _DEBUG
void CDrzewaView::AssertValid() const
{
	CView::AssertValid();
}

void CDrzewaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrzewaDoc* CDrzewaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrzewaDoc)));
	return (CDrzewaDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrzewaView message handlers
