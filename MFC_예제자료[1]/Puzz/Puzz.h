// Puzz.h : main header file for the PUZZ application
//

#if !defined(AFX_PUZZ_H__8D8D6A73_661E_4B00_A5D3_8D9881E8A7E6__INCLUDED_)
#define AFX_PUZZ_H__8D8D6A73_661E_4B00_A5D3_8D9881E8A7E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPuzzApp:
// See Puzz.cpp for the implementation of this class
//

class CPuzzApp : public CWinApp
{
public:
	CPuzzApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPuzzApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPuzzApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUZZ_H__8D8D6A73_661E_4B00_A5D3_8D9881E8A7E6__INCLUDED_)
