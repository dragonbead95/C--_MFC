// FileSeri.h : main header file for the FILESERI application
//

#if !defined(AFX_FILESERI_H__A864F0AF_6A7C_41E2_A4A6_E9251BFC625A__INCLUDED_)
#define AFX_FILESERI_H__A864F0AF_6A7C_41E2_A4A6_E9251BFC625A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileSeriApp:
// See FileSeri.cpp for the implementation of this class
//

class CFileSeriApp : public CWinApp
{
public:
	CFileSeriApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileSeriApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileSeriApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILESERI_H__A864F0AF_6A7C_41E2_A4A6_E9251BFC625A__INCLUDED_)
