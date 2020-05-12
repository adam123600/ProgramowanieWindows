
// KalkulatorLiczbZespolonychView.h : interface of the CKalkulatorLiczbZespolonychView class
//

#pragma once


class CKalkulatorLiczbZespolonychView : public CView
{
protected: // create from serialization only
	CKalkulatorLiczbZespolonychView();
	DECLARE_DYNCREATE(CKalkulatorLiczbZespolonychView)

// Attributes
public:
	CKalkulatorLiczbZespolonychDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CKalkulatorLiczbZespolonychView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDlgKalkulator();
};

#ifndef _DEBUG  // debug version in KalkulatorLiczbZespolonychView.cpp
inline CKalkulatorLiczbZespolonychDoc* CKalkulatorLiczbZespolonychView::GetDocument() const
   { return reinterpret_cast<CKalkulatorLiczbZespolonychDoc*>(m_pDocument); }
#endif

