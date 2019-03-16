// ColorDlg.h : main header file for the COLORDLG application
//

#if !defined(AFX_COLORDLG_H__A3A523FA_6C1E_40A4_BCDE_633C7EE2B5A4__INCLUDED_)
#define AFX_COLORDLG_H__A3A523FA_6C1E_40A4_BCDE_633C7EE2B5A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorDlgApp:
// See ColorDlg.cpp for the implementation of this class
//

class CColorDlgApp : public CWinApp
{
public:
	CColorDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CColorDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORDLG_H__A3A523FA_6C1E_40A4_BCDE_633C7EE2B5A4__INCLUDED_)
