// Prop.h : main header file for the PROP application
//

#if !defined(AFX_PROP_H__38CAC2BE_7BD6_4BA9_A0FB_425A1038D4B3__INCLUDED_)
#define AFX_PROP_H__38CAC2BE_7BD6_4BA9_A0FB_425A1038D4B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPropApp:
// See Prop.cpp for the implementation of this class
//

class CPropApp : public CWinApp
{
public:
	CPropApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPropApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROP_H__38CAC2BE_7BD6_4BA9_A0FB_425A1038D4B3__INCLUDED_)
