// ASplit.h : main header file for the ASPLIT application
//

#if !defined(AFX_ASPLIT_H__D0C0C4E7_BA57_4A06_BE2A_6A90F2FD236F__INCLUDED_)
#define AFX_ASPLIT_H__D0C0C4E7_BA57_4A06_BE2A_6A90F2FD236F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CASplitApp:
// See ASplit.cpp for the implementation of this class
//

class CASplitApp : public CWinApp
{
public:
	CASplitApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CASplitApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CASplitApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASPLIT_H__D0C0C4E7_BA57_4A06_BE2A_6A90F2FD236F__INCLUDED_)
