
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

#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define BALLSIZE 60

// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	ON_COMMAND(ID_START_STOP, &CMFCApplication1View::OnStart)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_DODAJKULKE, &CMFCApplication1View::OnDodajkulke)
	ON_COMMAND(ID_USUNKULKE, &CMFCApplication1View::OnUsunkulke)
END_MESSAGE_MAP()

void CALLBACK ZfxTimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
	::SendMessage(hWnd, WM_TIMER, 0, 0);
}


// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: add construction code here
	srand(time(NULL));

	m_pBall = new CRect(20, 20, 20 + BALLSIZE, 20 + BALLSIZE);
	m_pBallPen = new CPen(PS_SOLID, 1, RGB(0, 0, 255));
	m_pBallBrush = new CBrush(RGB(0, 0, 255));

	m_nBallOffX = 3;
	m_nBallOffY = 1;

	m_bStart = false;

	m_pClientRect = new CRect(0, 0, 0, 0);
	amountBalls = 0;
}

CMFCApplication1View::~CMFCApplication1View()
{
	delete m_pBall;
	delete m_pBallPen;
	delete m_pBallBrush;
	delete m_pClientRect;
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

	//CPen* pOldPen = pDC->SelectObject(m_pBallPen);
	//CBrush* pOldBrush = pDC->SelectObject(m_pBallBrush);
	//pDC->Ellipse(m_pBall);
	//pDC->SelectObject(pOldPen);
	//pDC->SelectObject(pOldBrush);

	// ****
	//CBall* b2 = new CBall(20, 20, 100, 100, RGB(255, 0, 0));
	//m_pBalls.push_back(b2);
	
	// ****

	CDC memDC;
	BOOL b = memDC.CreateCompatibleDC(pDC);
	ASSERT(b);

	CBitmap bmp;
	b = bmp.CreateCompatibleBitmap(pDC, m_pClientRect->Width(), m_pClientRect->Height());
	ASSERT(b);
	CBitmap* pOldBitmap = memDC.SelectObject(&bmp);
	memDC.FillSolidRect(m_pClientRect, RGB(230, 230, 200));

	CPen* pOldPen = memDC.SelectObject(m_pBallPen);
	CBrush* pOldBrush = memDC.SelectObject(m_pBallBrush);

	//memDC.Ellipse(m_pBall);
	
	for (int i = 0; i < amountBalls; i++)
	{	
		pOldPen = memDC.SelectObject(m_pBalls[i]->getBallPen());
		pOldBrush = memDC.SelectObject(m_pBalls[i]->getBallBrush());
		memDC.Ellipse(m_pBalls[i]);
	}

	for (int i = 0; i < amountBalls; i++)
		bounceBalls(m_pBalls[i]);
	//memDC.SelectObject(m_pBalls[0]);
	
	//memDC.Ellipse(m_pBalls[0]);
	//bounceBalls(m_pBalls[0]);

	memDC.SelectObject(pOldPen);
	memDC.SelectObject(pOldBrush);

	b = pDC->BitBlt(0, 0, m_pClientRect->Width(), m_pClientRect->Height(), &memDC, 0, 0, SRCCOPY);
	ASSERT(b);

	memDC.SelectObject(pOldBitmap);
	bmp.DeleteObject();
	memDC.DeleteDC();
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


void CMFCApplication1View::OnStart()
{
	// TODO: Add your command handler code here
	m_bStart = !m_bStart;
}



void CMFCApplication1View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	m_nTimerID = SetTimer(WM_USER + 1, 20, ZfxTimerProc);
}


void CMFCApplication1View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(m_nTimerID);
	CView::OnDestroy();
}


void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if (m_bStart)
	{
		/*if ( m_pBall->bottom >= m_pClientRect->bottom)
			m_pBall->OffsetRect(-3*(m_nBallOffX), -3*(m_nBallOffY+5));
		else
			m_pBall->OffsetRect(3*m_nBallOffX, 3*m_nBallOffY);
		*/
		
		/*if (m_pBall->right >= m_pClientRect->right)
			m_nBallOffX *= -1;

		if (m_pBall->bottom >= m_pClientRect->bottom)
			m_nBallOffY *= -1;

		if (m_pBall->left < m_pClientRect->left)
			m_nBallOffX *= -1;

		if (m_pBall->top < m_pClientRect->top )
			m_nBallOffY *= -1;*/

		
		//if ( amountBalls > 0)
		for(int i = 0; i < amountBalls; i++)
			m_pBalls[i]->OffsetRect(5*m_pBalls[i]->getOffX(), 5*m_pBalls[i]->getOffY());

		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}


BOOL CMFCApplication1View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	//return CView::OnEraseBkgnd(pDC);
	return 1;
}


void CMFCApplication1View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	GetClientRect(m_pClientRect);

	CView::OnPrepareDC(pDC, pInfo);
}


void CMFCApplication1View::bounceBalls(CBall * pBall)
{/*
	if (m_pBall->right >= m_pClientRect->right)
		m_nBallOffX *= -1;

	if (m_pBall->bottom >= m_pClientRect->bottom)
		m_nBallOffY *= -1;

	if (m_pBall->left < m_pClientRect->left)
		m_nBallOffX *= -1;

	if (m_pBall->top < m_pClientRect->top)
		m_nBallOffY *= -1;*/

	if (pBall->right >= m_pClientRect->right)
		pBall->SetOffset(-1, 1);

	if (pBall->bottom >= m_pClientRect->bottom)
		pBall->SetOffset(1, -1);

	if (pBall->left < m_pClientRect->left)
		pBall->SetOffset(-1, 1);

	if (pBall->top < m_pClientRect->top)
		pBall->SetOffset(1, -1);
}


void CMFCApplication1View::OnDodajkulke()
{
	// TODO: Add your command handler code here
	if (amountBalls >= 0 && amountBalls < 10)
	{
		int temp = rand() % 100;
		CBall* pBall = new CBall(20, 20, 20 + temp, 20 + temp, RGB(rand()%255, rand()%255, rand()%255), 1 + rand()% 10, 1 + rand()%10);
		//CBall pBall(20, 20, 20 + temp, 20 + temp, RGB(rand() % 255, rand() % 255, rand() % 255), 1 + rand() % 10, 1 + rand() % 10);
		m_pBalls.push_back(pBall);
		amountBalls++;

		if (amountBalls > 10)
			amountBalls = 10;
	}
}


void CMFCApplication1View::OnUsunkulke()
{
	// TODO: Add your command handler code here
	if (amountBalls > 0 && amountBalls <= 10)
	{
		//m_pBalls.pop_back();

		CBall* pBall = m_pBalls.back();
		delete pBall;
		m_pBalls.pop_back();

		amountBalls--;
		
		if (amountBalls < 0)
			amountBalls = 0;
	}
}
