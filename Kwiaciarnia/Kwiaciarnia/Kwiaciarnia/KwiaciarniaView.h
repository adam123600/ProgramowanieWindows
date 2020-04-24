
// KwiaciarniaView.h : interface of the CKwiaciarniaView class
//

#pragma once


class CKwiaciarniaView : public CView
{
protected: // create from serialization only
	CKwiaciarniaView();
	DECLARE_DYNCREATE(CKwiaciarniaView)

// Attributes
public:
	CKwiaciarniaDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CKwiaciarniaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKwiaciarnia();
};

#ifndef _DEBUG  // debug version in KwiaciarniaView.cpp
inline CKwiaciarniaDoc* CKwiaciarniaView::GetDocument() const
   { return reinterpret_cast<CKwiaciarniaDoc*>(m_pDocument); }
#endif

