// MouseMess.h : main header file for the MOUSEMESS application
//

#if !defined(AFX_MOUSEMESS_H__9796BAB3_35B8_4B1D_9F1C_BBCA5823B763__INCLUDED_)
#define AFX_MOUSEMESS_H__9796BAB3_35B8_4B1D_9F1C_BBCA5823B763__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMouseMessApp:
// See MouseMess.cpp for the implementation of this class
//

class CMouseMessApp : public CWinApp
{
public:
	CMouseMessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseMessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMouseMessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEMESS_H__9796BAB3_35B8_4B1D_9F1C_BBCA5823B763__INCLUDED_)
