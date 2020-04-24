
// Kwiaciarnia.h : main header file for the Kwiaciarnia application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CKwiaciarniaApp:
// See Kwiaciarnia.cpp for the implementation of this class
//

class CKwiaciarniaApp : public CWinApp
{
public:
	CKwiaciarniaApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKwiaciarniaApp theApp;
