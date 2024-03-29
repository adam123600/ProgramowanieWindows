#pragma once


// CKwiaciarniaDialog dialog

class CKwiaciarniaDialog : public CDialog
{
	DECLARE_DYNAMIC(CKwiaciarniaDialog)

public:
	CKwiaciarniaDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKwiaciarniaDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KWIACIARNIA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int m_TulipanQuantity;
	int m_RozeQuantity;
	int m_FrezjaQuantity;
	int m_RodzajOpakowania;
	// Discount in % (percent)
	int m_Rabat;
public:
	afx_msg void OnBnClickedObliczCene();
	afx_msg void OnBnClickedZamknijSklep();
};
