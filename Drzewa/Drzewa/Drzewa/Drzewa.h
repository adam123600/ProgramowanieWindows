
// Drzewa.h : main header file for the Drzewa application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrzewaApp:
// See Drzewa.cpp for the implementation of this class
//

class CDrzewaApp : public CWinApp
{
public:
	CDrzewaApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrzewaApp theApp;
