
// Sortowania.h : main header file for the Sortowania application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSortowaniaApp:
// See Sortowania.cpp for the implementation of this class
//

class CSortowaniaApp : public CWinApp
{
public:
	CSortowaniaApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSortowaniaApp theApp;
