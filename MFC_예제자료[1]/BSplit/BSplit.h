// BSplit.h : main header file for the BSPLIT application
//

#if !defined(AFX_BSPLIT_H__32B646E7_C89E_43EB_8DB1_9460B9CC3ED2__INCLUDED_)
#define AFX_BSPLIT_H__32B646E7_C89E_43EB_8DB1_9460B9CC3ED2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBSplitApp:
// See BSplit.cpp for the implementation of this class
//

class CBSplitApp : public CWinApp
{
public:
	CBSplitApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBSplitApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBSplitApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BSPLIT_H__32B646E7_C89E_43EB_8DB1_9460B9CC3ED2__INCLUDED_)
