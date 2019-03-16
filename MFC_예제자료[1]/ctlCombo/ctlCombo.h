// ctlCombo.h : main header file for the CTLCOMBO application
//

#if !defined(AFX_CTLCOMBO_H__95A8A9C0_9921_41AF_9F77_32A1041A93B0__INCLUDED_)
#define AFX_CTLCOMBO_H__95A8A9C0_9921_41AF_9F77_32A1041A93B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtlComboApp:
// See ctlCombo.cpp for the implementation of this class
//

class CCtlComboApp : public CWinApp
{
public:
	CCtlComboApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlComboApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCtlComboApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTLCOMBO_H__95A8A9C0_9921_41AF_9F77_32A1041A93B0__INCLUDED_)
