// ButtBmp.h : main header file for the BUTTBMP application
//

#if !defined(AFX_BUTTBMP_H__EB1D0590_599C_42C7_B7B2_AAC38CFE377E__INCLUDED_)
#define AFX_BUTTBMP_H__EB1D0590_599C_42C7_B7B2_AAC38CFE377E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CButtBmpApp:
// See ButtBmp.cpp for the implementation of this class
//

class CButtBmpApp : public CWinApp
{
public:
	CButtBmpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtBmpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CButtBmpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTBMP_H__EB1D0590_599C_42C7_B7B2_AAC38CFE377E__INCLUDED_)
