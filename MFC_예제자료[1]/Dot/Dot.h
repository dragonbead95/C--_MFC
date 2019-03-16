// Dot.h : main header file for the DOT application
//

#if !defined(AFX_DOT_H__C586B239_668F_4B60_B660_5E2068C2956D__INCLUDED_)
#define AFX_DOT_H__C586B239_668F_4B60_B660_5E2068C2956D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDotApp:
// See Dot.cpp for the implementation of this class
//

class CDotApp : public CWinApp
{
public:
	CDotApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDotApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDotApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOT_H__C586B239_668F_4B60_B660_5E2068C2956D__INCLUDED_)
