// ClkMouse.h : main header file for the CLKMOUSE application
//

#if !defined(AFX_CLKMOUSE_H__6F94F5CD_34E2_4A19_AB21_1D65CCB846D5__INCLUDED_)
#define AFX_CLKMOUSE_H__6F94F5CD_34E2_4A19_AB21_1D65CCB846D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClkMouseApp:
// See ClkMouse.cpp for the implementation of this class
//

class CClkMouseApp : public CWinApp
{
public:
	CClkMouseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClkMouseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClkMouseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLKMOUSE_H__6F94F5CD_34E2_4A19_AB21_1D65CCB846D5__INCLUDED_)
