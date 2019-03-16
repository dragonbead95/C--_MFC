// MyFont.h : main header file for the MYFONT application
//

#if !defined(AFX_MYFONT_H__89B358E4_F665_4114_9EEA_048C1F729FC7__INCLUDED_)
#define AFX_MYFONT_H__89B358E4_F665_4114_9EEA_048C1F729FC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyFontApp:
// See MyFont.cpp for the implementation of this class
//

class CMyFontApp : public CWinApp
{
public:
	CMyFontApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFontApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyFontApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYFONT_H__89B358E4_F665_4114_9EEA_048C1F729FC7__INCLUDED_)
