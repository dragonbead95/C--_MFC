// FileOpenDlg.h : main header file for the FILEOPENDLG application
//

#if !defined(AFX_FILEOPENDLG_H__EBAF606E_8AEA_4F5D_B7B9_CA11FC1CF44F__INCLUDED_)
#define AFX_FILEOPENDLG_H__EBAF606E_8AEA_4F5D_B7B9_CA11FC1CF44F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileOpenDlgApp:
// See FileOpenDlg.cpp for the implementation of this class
//

class CFileOpenDlgApp : public CWinApp
{
public:
	CFileOpenDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileOpenDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileOpenDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEOPENDLG_H__EBAF606E_8AEA_4F5D_B7B9_CA11FC1CF44F__INCLUDED_)
