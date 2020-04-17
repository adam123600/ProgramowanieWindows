// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// CTestDlg dialog

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TEST, pParent)
	, m_nNum(1)
	, m_nAcceptanceKind(2)
	, m_bFirst(FALSE)
	, m_bSecond(TRUE)
	, m_bthird(FALSE)
	, m_nLectureKind(0)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DATANUM, m_nNum);
	DDX_Radio(pDX, IDC_EGZ, m_nAcceptanceKind);
	DDX_Check(pDX, IDC_FIRST, m_bFirst);
	DDX_Control(pDX, IDC_LETTERS, m_ComboLetters);
	DDX_Check(pDX, IDC_SECOND, m_bSecond);
	DDX_Check(pDX, IDC_THIRD, m_bthird);
	DDX_Radio(pDX, IDC_WYKL, m_nLectureKind);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
END_MESSAGE_MAP()


// CTestDlg message handlers
