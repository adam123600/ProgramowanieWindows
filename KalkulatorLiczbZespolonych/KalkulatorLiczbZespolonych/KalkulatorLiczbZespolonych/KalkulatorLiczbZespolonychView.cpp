
// KalkulatorLiczbZespolonychView.cpp : implementation of the CKalkulatorLiczbZespolonychView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "KalkulatorLiczbZespolonych.h"
#endif

#include "TestDlg.h"

#include "KalkulatorLiczbZespolonychDoc.h"
#include "KalkulatorLiczbZespolonychView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKalkulatorLiczbZespolonychView

IMPLEMENT_DYNCREATE(CKalkulatorLiczbZespolonychView, CView)

BEGIN_MESSAGE_MAP(CKalkulatorLiczbZespolonychView, CView)
	ON_COMMAND(ID_DLG_KALKULATOR, &CKalkulatorLiczbZespolonychView::OnDlgKalkulator)
END_MESSAGE_MAP()

// CKalkulatorLiczbZespolonychView construction/destruction

CKalkulatorLiczbZespolonychView::CKalkulatorLiczbZespolonychView()
{
	// TODO: add construction code here

}

CKalkulatorLiczbZespolonychView::~CKalkulatorLiczbZespolonychView()
{
}

BOOL CKalkulatorLiczbZespolonychView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CKalkulatorLiczbZespolonychView drawing

void CKalkulatorLiczbZespolonychView::OnDraw(CDC* /*pDC*/)
{
	CKalkulatorLiczbZespolonychDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CKalkulatorLiczbZespolonychView diagnostics

#ifdef _DEBUG
void CKalkulatorLiczbZespolonychView::AssertValid() const
{
	CView::AssertValid();
}

void CKalkulatorLiczbZespolonychView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKalkulatorLiczbZespolonychDoc* CKalkulatorLiczbZespolonychView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKalkulatorLiczbZespolonychDoc)));
	return (CKalkulatorLiczbZespolonychDoc*)m_pDocument;
}
#endif //_DEBUG


// CKalkulatorLiczbZespolonychView message handlers


void CKalkulatorLiczbZespolonychView::OnDlgKalkulator()
{
	// TODO: Add your command handler code here
	CTestDlg dlg;
	dlg.DoModal();
}
