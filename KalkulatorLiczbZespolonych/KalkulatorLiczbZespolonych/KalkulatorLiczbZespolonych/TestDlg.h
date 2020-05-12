#pragma once


// CTestDlg dialog
#include "Complex.h"

class CTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTestDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	double m_liczba1RE;

	//CComplex c1;
	double m_liczba1IM;
	double m_liczba2RE;
	double m_liczba2IM;
public:
	int m_RodzajObliczenia;
	afx_msg void OnBnClickedButtonResult();
};
