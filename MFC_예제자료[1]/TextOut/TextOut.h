// TextOut.h : main header file for the TEXTOUT application
//

#if !defined(AFX_TEXTOUT_H__E964FCB8_AE15_48FF_8DC0_5B4E794CF1A7__INCLUDED_)
#define AFX_TEXTOUT_H__E964FCB8_AE15_48FF_8DC0_5B4E794CF1A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextOutApp:
// See TextOut.cpp for the implementation of this class
//

class CTextOutApp : public CWinApp
{
public:
	CTextOutApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextOutApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTextOutApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTOUT_H__E964FCB8_AE15_48FF_8DC0_5B4E794CF1A7__INCLUDED_)
