
// SortowaniaView.h : interface of the CSortowaniaView class
//

#pragma once


class CSortowaniaView : public CView
{
protected: // create from serialization only
	CSortowaniaView();
	DECLARE_DYNCREATE(CSortowaniaView)

// Attributes
public:
	CSortowaniaDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSortowaniaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	void drawCoordinateSystem(CDC* pDC);
	void drawRectangle(CDC* pDC);

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

public:
	CRect* m_pClientRect;
};

#ifndef _DEBUG  // debug version in SortowaniaView.cpp
inline CSortowaniaDoc* CSortowaniaView::GetDocument() const
   { return reinterpret_cast<CSortowaniaDoc*>(m_pDocument); }
#endif

