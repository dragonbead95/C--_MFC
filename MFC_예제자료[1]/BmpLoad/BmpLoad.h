// BmpLoad.h : main header file for the BMPLOAD application
//

#if !defined(AFX_BMPLOAD_H__F2C82ED2_B5AB_4E36_9CD0_A7202A3C8F13__INCLUDED_)
#define AFX_BMPLOAD_H__F2C82ED2_B5AB_4E36_9CD0_A7202A3C8F13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmpLoadApp:
// See BmpLoad.cpp for the implementation of this class
//

class CBmpLoadApp : public CWinApp
{
public:
	CBmpLoadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpLoadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBmpLoadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPLOAD_H__F2C82ED2_B5AB_4E36_9CD0_A7202A3C8F13__INCLUDED_)
