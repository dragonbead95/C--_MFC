// ctlCheck.h : main header file for the CTLCHECK application
//

#if !defined(AFX_CTLCHECK_H__18B73A7B_52B1_480C_B111_47085C03478B__INCLUDED_)
#define AFX_CTLCHECK_H__18B73A7B_52B1_480C_B111_47085C03478B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtlCheckApp:
// See ctlCheck.cpp for the implementation of this class
//

class CCtlCheckApp : public CWinApp
{
public:
	CCtlCheckApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlCheckApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCtlCheckApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTLCHECK_H__18B73A7B_52B1_480C_B111_47085C03478B__INCLUDED_)
