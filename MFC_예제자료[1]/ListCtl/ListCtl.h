// ListCtl.h : main header file for the LISTCTL application
//

#if !defined(AFX_LISTCTL_H__945CCF92_5677_45E1_B36C_B75C701FA7EA__INCLUDED_)
#define AFX_LISTCTL_H__945CCF92_5677_45E1_B36C_B75C701FA7EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListCtlApp:
// See ListCtl.cpp for the implementation of this class
//

class CListCtlApp : public CWinApp
{
public:
	CListCtlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListCtlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTL_H__945CCF92_5677_45E1_B36C_B75C701FA7EA__INCLUDED_)
