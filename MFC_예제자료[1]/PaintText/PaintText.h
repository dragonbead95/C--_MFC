// PaintText.h : main header file for the PAINTTEXT application
//

#if !defined(AFX_PAINTTEXT_H__9B9DAE6C_F5F1_45AC_A2A4_EE866597BA1A__INCLUDED_)
#define AFX_PAINTTEXT_H__9B9DAE6C_F5F1_45AC_A2A4_EE866597BA1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPaintTextApp:
// See PaintText.cpp for the implementation of this class
//

class CPaintTextApp : public CWinApp
{
public:
	CPaintTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPaintTextApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTTEXT_H__9B9DAE6C_F5F1_45AC_A2A4_EE866597BA1A__INCLUDED_)
