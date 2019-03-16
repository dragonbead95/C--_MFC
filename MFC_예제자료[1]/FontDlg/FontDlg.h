// FontDlg.h : main header file for the FONTDLG application
//

#if !defined(AFX_FONTDLG_H__6A6D4751_9103_453A_A01C_52F75566F4B4__INCLUDED_)
#define AFX_FONTDLG_H__6A6D4751_9103_453A_A01C_52F75566F4B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFontDlgApp:
// See FontDlg.cpp for the implementation of this class
//

class CFontDlgApp : public CWinApp
{
public:
	CFontDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFontDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTDLG_H__6A6D4751_9103_453A_A01C_52F75566F4B4__INCLUDED_)
