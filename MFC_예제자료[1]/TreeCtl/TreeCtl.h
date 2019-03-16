// TreeCtl.h : main header file for the TREECTL application
//

#if !defined(AFX_TREECTL_H__8E00CA66_EBE1_4D5D_9798_E5789080BE5A__INCLUDED_)
#define AFX_TREECTL_H__8E00CA66_EBE1_4D5D_9798_E5789080BE5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreeCtlApp:
// See TreeCtl.cpp for the implementation of this class
//

class CTreeCtlApp : public CWinApp
{
public:
	CTreeCtlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeCtlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTreeCtlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREECTL_H__8E00CA66_EBE1_4D5D_9798_E5789080BE5A__INCLUDED_)
