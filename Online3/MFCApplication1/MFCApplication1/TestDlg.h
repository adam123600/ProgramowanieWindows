#pragma once
#include "afxwin.h"


// CTestDlg dialog

class CTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTestDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	// Liczba naturalna
	int m_nNum;
	int m_nAcceptanceKind;
	BOOL m_bFirst;
	CComboBox m_ComboLetters;
	BOOL m_bSecond;
	BOOL m_bthird;
	int m_nLectureKind;
};
