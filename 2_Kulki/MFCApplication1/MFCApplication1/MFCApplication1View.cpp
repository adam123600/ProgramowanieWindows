
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

#define BALLSIZE 60
// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	ON_COMMAND(ID_START_STOP, &CMFCApplication1View::OnStartStop)
	ON_COMMAND(ID_DODAJKULKE, &CMFCApplication1View::OnDodajkulke)
	ON_COMMAND(ID_USUNKULKE, &CMFCApplication1View::OnUsunkulke)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
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

	m_bStartStopButton = false;
	m_bStartAnimation = false;

	m_pBall = new CRect(20, 20, 20 + BALLSIZE, 20 + BALLSIZE);
	m_pBallPen = new CPen(PS_SOLID, 1, RGB(0, 0, 255));
	m_pBallBrush = new CBrush(RGB(0, 0, 255));

	m_nBallOffX = 3;
	m_nBallOffY = 1;

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


	for (int i = 0; i < amountBalls; i++)
	{
		pOldPen = memDC.SelectObject(m_pBalls[i]->getBallPen());
		pOldBrush = memDC.SelectObject(m_pBalls[i]->getBallBrush());
		memDC.Ellipse(m_pBalls[i]);
	}

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


void CMFCApplication1View::OnStartStop()
{
	// TODO: Add your command handler code here
	m_bStartStopButton = !m_bStartStopButton;
	m_bStartAnimation = !m_bStartAnimation;
	CMainFrame* pFrame = (CMainFrame*)GetParentFrame();
	pFrame->ResetButton(m_bStartStopButton);
}


void CMFCApplication1View::OnDodajkulke()
{
	// TODO: Add your command handler code here
	if (amountBalls >= 0 && amountBalls < 10)
	{
		int temp = rand() % 100;
		CBall* pBall = new CBall(20, 20, 20 + temp, 20 + temp, RGB(rand() % 255, rand() % 255, rand() % 255), 1 + rand() % 10, 1 + rand() % 10);
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
		CBall* pBall = m_pBalls.back();
		delete pBall;
		m_pBalls.pop_back();

		amountBalls--;

		if (amountBalls < 0)
			amountBalls = 0;
	}
}


void CMFCApplication1View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	m_nTimerID = SetTimer(WM_USER + 1, 20, ZfxTimerProc);
}


void CMFCApplication1View::OnDestroy()
{
	KillTimer(m_nTimerID);
	CView::OnDestroy();

	// TODO: Add your message handler code here
}


void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	for (int i = 0; i < amountBalls; i++)
		m_pBalls[i]->OffsetRect(0, 0);
	Invalidate();

	if (m_bStartAnimation)
	{
		for (int i = 0; i < amountBalls; i++)
		{
			m_pBalls[i]->OffsetRect(5*m_pBalls[i]->getOffX(), 5*m_pBalls[i]->getOffY());
			bounceBalls(m_pBalls[i]);
		}

		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}


BOOL CMFCApplication1View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return 1;
	//return CView::OnEraseBkgnd(pDC);
}


void CMFCApplication1View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: Add your specialized code here and/or call the base class
	GetClientRect(m_pClientRect);
	CView::OnPrepareDC(pDC, pInfo);
}

void CMFCApplication1View::bounceBalls(CBall * pBall)
{
	GetClientRect(m_pClientRect);

	int nOffX = 1;
	int nOffY = 1;
	if (pBall->right >= m_pClientRect->right)
	{
		pBall->SetOffset(-nOffX, nOffY);
		pBall->MoveToX(m_pClientRect->right - pBall->Size().cx);
	}
	else if (pBall->left <= m_pClientRect->left)
	{
		pBall->SetOffset(-nOffX, nOffY);
		pBall->MoveToX(0);
	}

	if (pBall->bottom >= m_pClientRect->bottom)
	{
		pBall->SetOffset(nOffX, -nOffY);
		pBall->MoveToY(m_pClientRect->bottom - pBall->Size().cy);
	}
	else if (pBall->top <= m_pClientRect->top)
	{
		pBall->SetOffset(nOffX, -nOffY);
		pBall->MoveToY(0);
	}
}



void CMFCApplication1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	GetClientRect(m_pClientRect);

	for (int i = 0; i < amountBalls; i++)
		bounceBalls(m_pBalls[i]);
}
