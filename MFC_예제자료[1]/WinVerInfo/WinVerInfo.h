// WinVerInfo.h : main header file for the WINVERINFO application
//

#if !defined(AFX_WINVERINFO_H__8BCE3726_36C1_4070_B2CB_D37C9330ADA0__INCLUDED_)
#define AFX_WINVERINFO_H__8BCE3726_36C1_4070_B2CB_D37C9330ADA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWinVerInfoApp:
// See WinVerInfo.cpp for the implementation of this class
//

class CWinVerInfoApp : public CWinApp
{
public:
	CWinVerInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinVerInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWinVerInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINVERINFO_H__8BCE3726_36C1_4070_B2CB_D37C9330ADA0__INCLUDED_)
