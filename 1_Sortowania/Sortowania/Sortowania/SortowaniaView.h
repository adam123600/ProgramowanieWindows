
// SortowaniaView.h : interface of the CSortowaniaView class
//

#pragma once

#include "ColorRect.h"
#include "CoordinateSystem.h"
#include "Constants.h"
#include "resource.h"

#include <memory>



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

// Implementation
public:
	virtual ~CSortowaniaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
	CRect* m_pClientRect;
	CPen* m_pPenCoordinateSystem;

public:
	POINT topCoordinateSystem;
	POINT bottomCoordinateSystem;
	unsigned int maxSortTime;

private:
	void drawAllSorts(CDC* pDC, CSortowaniaDoc* pDoc);
	void drawBasicSorts(CDC* pDC, CSortowaniaDoc* pDoc);
	void drawQuickSorts(CDC* pDC, CSortowaniaDoc* pDoc);

public:
	void drawCoordinateSystem(CDC* pDC);
	void drawRectangle(CDC* pDC, const int& height, int positionOnX, COLORREF color);
};

#ifndef _DEBUG  // debug version in SortowaniaView.cpp
inline CSortowaniaDoc* CSortowaniaView::GetDocument() const
   { return reinterpret_cast<CSortowaniaDoc*>(m_pDocument); }
#endif

