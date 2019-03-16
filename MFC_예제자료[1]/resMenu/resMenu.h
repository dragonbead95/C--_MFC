// resMenu.h : main header file for the RESMENU application
//

#if !defined(AFX_RESMENU_H__30D8C1B0_32D0_4D67_B6F0_B61AFBC267CF__INCLUDED_)
#define AFX_RESMENU_H__30D8C1B0_32D0_4D67_B6F0_B61AFBC267CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CResMenuApp:
// See resMenu.cpp for the implementation of this class
//

class CResMenuApp : public CWinApp
{
public:
	CResMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CResMenuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESMENU_H__30D8C1B0_32D0_4D67_B6F0_B61AFBC267CF__INCLUDED_)
