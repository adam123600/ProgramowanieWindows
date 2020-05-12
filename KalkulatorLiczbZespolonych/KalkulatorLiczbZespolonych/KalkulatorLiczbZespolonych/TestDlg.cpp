// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KalkulatorLiczbZespolonych.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// CTestDlg dialog

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_liczba1RE(0)
	, m_liczba1IM(0)
	, m_liczba2RE(0)
	, m_liczba2IM(0)
	, m_RodzajObliczenia(0)
{
	
}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, ID_LICZBA1_RE, m_liczba1RE);
	DDX_Text(pDX, ID_LICZBA1_IM, m_liczba1IM);
	DDX_Text(pDX, ID_LICZBA2_RE, m_liczba2RE);
	DDX_Text(pDX, ID_LICZBA2_IM, m_liczba2IM);
	DDX_Radio(pDX, ID_DODAJ, m_RodzajObliczenia);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_BN_CLICKED(ID_BUTTON_RESULT, &CTestDlg::OnBnClickedButtonResult)
END_MESSAGE_MAP()


// CTestDlg message handlers


void CTestDlg::OnBnClickedButtonResult()
{
	// TODO: Add your control notification handler code here
	UpdateData();

	CComplex c1(m_liczba1RE, m_liczba1IM);
	CComplex c2(m_liczba2RE, m_liczba2IM);
	CComplex result(0, 0);

	switch (m_RodzajObliczenia)
	{
		case 0:
			result = c1 + c2;
			break;
		case 1:
			result = c1 - c2;
			break;
		case 2:
			result = c1 * c2;
			break;
		case 3:
			result = c1 / c2;
			break;
		case 4:
			result = c1.Module();
			break;
		case 5:
			result = c1.Coupled();
			break;
	}
	

	CString str1;
	
	if (m_RodzajObliczenia != 4)
	{
		if (result.getIm() > 0)
			str1.Format(L"%.2f + %.2f*i", result.getRe(), result.getIm());
		else if (result.getIm() < 0)
			str1.Format(L"%.2f  %.2f*i", result.getRe(), result.getIm());
		else
			str1.Format(L"%.2f", result.getRe());
	}

	else if (m_RodzajObliczenia == 4)
		str1.Format(L"%.2f", result.getRe());


	CWnd* pWnd = GetDlgItem(ID_RESULT_RE1);
	pWnd->SetWindowTextW(str1);

	
	
}
