// Calen.h : main header file for the CALEN application
//

#if !defined(AFX_CALEN_H__97D6C605_8B11_4BE5_9C9E_6877D88CCA95__INCLUDED_)
#define AFX_CALEN_H__97D6C605_8B11_4BE5_9C9E_6877D88CCA95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCalenApp:
// See Calen.cpp for the implementation of this class
//

class CCalenApp : public CWinApp
{
public:
	CCalenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCalenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALEN_H__97D6C605_8B11_4BE5_9C9E_6877D88CCA95__INCLUDED_)
