
// KwiaciarniaView.cpp : implementation of the CKwiaciarniaView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Kwiaciarnia.h"
#endif

#include "KwiaciarniaDoc.h"
#include "KwiaciarniaView.h"
#include "KwiaciarniaDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKwiaciarniaView

IMPLEMENT_DYNCREATE(CKwiaciarniaView, CView)

BEGIN_MESSAGE_MAP(CKwiaciarniaView, CView)
	ON_COMMAND(ID_KWIACIARNIA, &CKwiaciarniaView::OnKwiaciarnia)
END_MESSAGE_MAP()

// CKwiaciarniaView construction/destruction

CKwiaciarniaView::CKwiaciarniaView()
{
	// TODO: add construction code here

}

CKwiaciarniaView::~CKwiaciarniaView()
{
}

BOOL CKwiaciarniaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CKwiaciarniaView drawing

void CKwiaciarniaView::OnDraw(CDC* /*pDC*/)
{
	CKwiaciarniaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CKwiaciarniaView diagnostics

#ifdef _DEBUG
void CKwiaciarniaView::AssertValid() const
{
	CView::AssertValid();
}

void CKwiaciarniaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKwiaciarniaDoc* CKwiaciarniaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKwiaciarniaDoc)));
	return (CKwiaciarniaDoc*)m_pDocument;
}
#endif //_DEBUG


// CKwiaciarniaView message handlers


void CKwiaciarniaView::OnKwiaciarnia()
{
	// TODO: Add your command handler code here
	CKwiaciarniaDialog dlg;
	dlg.DoModal();
}
