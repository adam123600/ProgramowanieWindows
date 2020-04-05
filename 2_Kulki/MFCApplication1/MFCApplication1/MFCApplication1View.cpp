
// MFCApplication1View.cpp : implementation of the CMFCApplication1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	ON_COMMAND(ID_DODAJKULKE, &CMFCApplication1View::OnDodajkulke)
	ON_COMMAND(ID_USUNKULKE, &CMFCApplication1View::OnUsunkulke)
	ON_COMMAND(ID_ANIMACJA, &CMFCApplication1View::OnAnimacja)
END_MESSAGE_MAP()

// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: add construction code here
	m_bAnimacja = false;
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View drawing

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	
	//CBall* mBall = new CBall(5, 5, 100, 100, RGB(0, 255, 0));
	CBall b1(5, 5, 100, 100, RGB(255, 0, 0));
	m_pBalls.push_back(&b1);
	

	CPen* pOldPen = pDC->SelectObject(m_pBalls[0]->getBallPen()); 
	CBrush* pOldBrush = pDC->SelectObject(m_pBalls[0]->getBallBrush());

	pDC->Ellipse(m_pBalls[0]);
}


// CMFCApplication1View diagnostics

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View message handlers


void CMFCApplication1View::OnDodajkulke()
{
	// TODO: Add your command handler code here
}


void CMFCApplication1View::OnUsunkulke()
{
	// TODO: Add your command handler code here
}


void CMFCApplication1View::OnAnimacja()
{
	// TODO: Add your command handler code here
	m_bAnimacja = !m_bAnimacja;
	CMainFrame* pFrame = (CMainFrame*)GetParentFrame();
	pFrame->ResetButton(m_bAnimacja);
}
