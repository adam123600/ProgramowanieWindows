
// KalkulatorLiczbZespolonych.h : main header file for the KalkulatorLiczbZespolonych application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CKalkulatorLiczbZespolonychApp:
// See KalkulatorLiczbZespolonych.cpp for the implementation of this class
//

class CKalkulatorLiczbZespolonychApp : public CWinApp
{
public:
	CKalkulatorLiczbZespolonychApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKalkulatorLiczbZespolonychApp theApp;
