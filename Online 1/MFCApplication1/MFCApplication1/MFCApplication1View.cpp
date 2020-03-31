
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
	ON_COMMAND(ID_JAMAJKA, &CMFCApplication1View::OnJamajka)
	ON_COMMAND(ID_JAPAN, &CMFCApplication1View::OnJapan)
	ON_UPDATE_COMMAND_UI(ID_JAMAJKA, &CMFCApplication1View::OnUpdateJamajka)
	ON_UPDATE_COMMAND_UI(ID_JAPAN, &CMFCApplication1View::OnUpdateJapan)
	ON_COMMAND(ID_POLAND, &CMFCApplication1View::OnPoland)
END_MESSAGE_MAP()

// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: add construction code here
	m_bJamajka = true;
	m_bJapan = false;
	m_bPolFlag = false;
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

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
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


void CMFCApplication1View::OnJamajka()
{
	// TODO: Add your command handler code here
	m_bJamajka = false;
	m_bJapan = true;
}


void CMFCApplication1View::OnJapan()
{
	// TODO: Add your command handler code here
	m_bJamajka = true;
	m_bJapan = false;
}


void CMFCApplication1View::OnUpdateJamajka(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bJamajka);
}


void CMFCApplication1View::OnUpdateJapan(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bJapan);
}


void CMFCApplication1View::OnPoland()
{
	// TODO: Add your command handler code here
	m_bPolFlag = !m_bPolFlag;
	CMainFrame* pFrame = (CMainFrame*)GetParentFrame();
	pFrame->ResetButton(m_bPolFlag);
}
