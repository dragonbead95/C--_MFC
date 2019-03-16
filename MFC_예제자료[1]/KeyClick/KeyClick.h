// KeyClick.h : main header file for the KEYCLICK application
//

#if !defined(AFX_KEYCLICK_H__9D5ABFC0_719B_4DC0_B88A_77147328B0C9__INCLUDED_)
#define AFX_KEYCLICK_H__9D5ABFC0_719B_4DC0_B88A_77147328B0C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKeyClickApp:
// See KeyClick.cpp for the implementation of this class
//

class CKeyClickApp : public CWinApp
{
public:
	CKeyClickApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyClickApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKeyClickApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYCLICK_H__9D5ABFC0_719B_4DC0_B88A_77147328B0C9__INCLUDED_)
