// KwiaciarniaDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Kwiaciarnia.h"
#include "KwiaciarniaDialog.h"
#include "afxdialogex.h"


// CKwiaciarniaDialog dialog

IMPLEMENT_DYNAMIC(CKwiaciarniaDialog, CDialog)

CKwiaciarniaDialog::CKwiaciarniaDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_KWIACIARNIA, pParent)
	, m_TulipanQuantity(0)
	, m_RozeQuantity(0)
	, m_FrezjaQuantity(0)
	, m_RodzajOpakowania(0)
	, m_Rabat(0)
{
	m_TulipanQuantity = 0;
	m_RozeQuantity = 0;
	m_FrezjaQuantity = 0;
}

CKwiaciarniaDialog::~CKwiaciarniaDialog()
{
}

void CKwiaciarniaDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TULIPAN, m_TulipanQuantity);
	DDV_MinMaxInt(pDX, m_TulipanQuantity, 0, INT_MAX);
	DDX_Text(pDX, IDC_ROZE, m_RozeQuantity);
	DDV_MinMaxInt(pDX, m_RozeQuantity, 0, INT_MAX);
	DDX_Text(pDX, IDC_FREZJA, m_FrezjaQuantity);
	DDV_MinMaxInt(pDX, m_FrezjaQuantity, 0, INT_MAX);
	DDX_Radio(pDX, IDC_OPAKOWANIE_FOLIA, m_RodzajOpakowania);
	DDX_Text(pDX, IDC_RABAT, m_Rabat);
	DDV_MinMaxInt(pDX, m_Rabat, 0, 100);
}


BEGIN_MESSAGE_MAP(CKwiaciarniaDialog, CDialog)
	ON_BN_CLICKED(IDC_OBLICZ_CENE, &CKwiaciarniaDialog::OnBnClickedObliczCene)
	ON_BN_CLICKED(IDC_ZAMKNIJ_SKLEP, &CKwiaciarniaDialog::OnBnClickedZamknijSklep)
END_MESSAGE_MAP()


// CKwiaciarniaDialog message handlers


void CKwiaciarniaDialog::OnBnClickedObliczCene()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	
	double result;
	double rabat = m_Rabat;
	int opakowanie;

	switch (m_RodzajOpakowania)
	{
		case 0:
			opakowanie = 2;
			break;
		case 1:
			opakowanie = 1;
			break;
		default:
			opakowanie = 0;
	}

	result = m_TulipanQuantity * 4 + m_RozeQuantity * 3 + m_FrezjaQuantity * 2 + opakowanie;
	result = result - (rabat/100)*result;
	
	CString str; str.Format(L"%.2f", result);
	
	CWnd* pWnd = GetDlgItem(IDC_NALEZNOSC);
	pWnd->SetWindowTextW(str);
	
}


void CKwiaciarniaDialog::OnBnClickedZamknijSklep()
{
	// TODO: Add your control notification handler code here
	
	EndDialog(0);
}
