// OMok.h : main header file for the OMOK application
//

#if !defined(AFX_OMOK_H__693F7CC5_5A03_492D_BA61_2643D939EB71__INCLUDED_)
#define AFX_OMOK_H__693F7CC5_5A03_492D_BA61_2643D939EB71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COMokApp:
// See OMok.cpp for the implementation of this class
//

class COMokApp : public CWinApp
{
public:
	COMokApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COMokApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COMokApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OMOK_H__693F7CC5_5A03_492D_BA61_2643D939EB71__INCLUDED_)
