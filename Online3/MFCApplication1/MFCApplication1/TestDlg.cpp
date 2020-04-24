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
	srand((unsigned int)time(NULL));
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
	DDX_Control(pDX, IDC_SPIN_NUM, m_Spin);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_BN_CLICKED(IDC_GENER_RANDOM, &CTestDlg::OnGenerRandom)
	ON_BN_CLICKED(IDOK, &CTestDlg::OnOK)
END_MESSAGE_MAP()


// CTestDlg message handlers


BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	m_ComboLetters.SetCurSel(3);
	m_Spin.SetRange(0, UD_MAXVAL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CTestDlg::OnGenerRandom()
{
	// TODO: Add your control notification handler code here
	//UpdateData();

	int randNum = rand();
	CString str;
	str.Format(L"%d", randNum);
	CWnd* pWnd = GetDlgItem(IDC_RESULT);
	pWnd->SetWindowTextW(str);

}


void CTestDlg::OnOK()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CString str;

	int pos = -1;
	CString s;
	pos = m_ComboLetters.GetCurSel();
	m_ComboLetters.GetLBText(pos, s);

	str.Format(L"num=%d, first=%d, second=%d, third=%d, LKind=%d, AKind=%d, Combo_pos=%d Combo_str=%s",
		m_nNum, m_bFirst, m_bSecond, m_bthird, m_nLectureKind, m_nAcceptanceKind, pos, s);

	AfxMessageBox(str);
	CDialog::OnOK();
}
