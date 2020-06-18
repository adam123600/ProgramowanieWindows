
// DrzewaView.h : interface of the CDrzewaView class
//

#pragma once


class CDrzewaView : public CView
{
protected: // create from serialization only
	CDrzewaView();
	DECLARE_DYNCREATE(CDrzewaView)

// Attributes
public:
	CDrzewaDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CDrzewaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrzewaView.cpp
inline CDrzewaDoc* CDrzewaView::GetDocument() const
   { return reinterpret_cast<CDrzewaDoc*>(m_pDocument); }
#endif

