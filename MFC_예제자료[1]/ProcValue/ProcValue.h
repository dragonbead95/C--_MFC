// ProcValue.h : main header file for the PROCVALUE application
//

#if !defined(AFX_PROCVALUE_H__BDBB26F9_1C04_4B3A_A458_5500B6DDC033__INCLUDED_)
#define AFX_PROCVALUE_H__BDBB26F9_1C04_4B3A_A458_5500B6DDC033__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProcValueApp:
// See ProcValue.cpp for the implementation of this class
//

class CProcValueApp : public CWinApp
{
public:
	CProcValueApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcValueApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProcValueApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCVALUE_H__BDBB26F9_1C04_4B3A_A458_5500B6DDC033__INCLUDED_)
