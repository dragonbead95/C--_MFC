// NumTimer.h : main header file for the NUMTIMER application
//

#if !defined(AFX_NUMTIMER_H__894E79BC_5B81_412B_A392_E3F404792FDB__INCLUDED_)
#define AFX_NUMTIMER_H__894E79BC_5B81_412B_A392_E3F404792FDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNumTimerApp:
// See NumTimer.cpp for the implementation of this class
//

class CNumTimerApp : public CWinApp
{
public:
	CNumTimerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumTimerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNumTimerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMTIMER_H__894E79BC_5B81_412B_A392_E3F404792FDB__INCLUDED_)
