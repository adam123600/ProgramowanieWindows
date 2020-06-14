
// MFCApplication1View.h : interface of the CMFCApplication1View class
//

#pragma once
#include <vector>
#include "Ball.h"

class CMFCApplication1View : public CView
{
protected: // create from serialization only
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

// Attributes
public:
	CMFCApplication1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStartStop();
	afx_msg void OnDodajkulke();
	afx_msg void OnUsunkulke();

private:
	bool m_bStartStopButton;
	UINT_PTR m_nTimerID;
	CRect* m_pBall;
	CPen* m_pBallPen;
	CBrush* m_pBallBrush;

	bool m_bStartAnimation;

	int m_nBallOffX;
	int m_nBallOffY;

	CRect* m_pClientRect;

	short int amountBalls;

	std::vector<CBall*> m_pBalls;

private:
	void bounceBalls(CBall* pBall);

public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in MFCApplication1View.cpp
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

