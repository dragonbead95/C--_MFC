// ctlEdit.h : main header file for the CTLEDIT application
//

#if !defined(AFX_CTLEDIT_H__09DBCC8E_5F6A_4722_9DD7_6CCE091B31F2__INCLUDED_)
#define AFX_CTLEDIT_H__09DBCC8E_5F6A_4722_9DD7_6CCE091B31F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtlEditApp:
// See ctlEdit.cpp for the implementation of this class
//

class CCtlEditApp : public CWinApp
{
public:
	CCtlEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCtlEditApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTLEDIT_H__09DBCC8E_5F6A_4722_9DD7_6CCE091B31F2__INCLUDED_)
