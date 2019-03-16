// GetWindows.h : main header file for the GETWINDOWS application
//

#if !defined(AFX_GETWINDOWS_H__C35209BC_CB31_4A35_83B2_DD7D1621F666__INCLUDED_)
#define AFX_GETWINDOWS_H__C35209BC_CB31_4A35_83B2_DD7D1621F666__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetWindowsApp:
// See GetWindows.cpp for the implementation of this class
//

class CGetWindowsApp : public CWinApp
{
public:
	CGetWindowsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetWindowsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetWindowsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETWINDOWS_H__C35209BC_CB31_4A35_83B2_DD7D1621F666__INCLUDED_)
