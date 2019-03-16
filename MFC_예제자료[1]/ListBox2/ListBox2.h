// ListBox2.h : main header file for the LISTBOX2 application
//

#if !defined(AFX_LISTBOX2_H__0DF1C473_0C86_4A16_8D2F_868EBD2F7469__INCLUDED_)
#define AFX_LISTBOX2_H__0DF1C473_0C86_4A16_8D2F_868EBD2F7469__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListBox2App:
// See ListBox2.cpp for the implementation of this class
//

class CListBox2App : public CWinApp
{
public:
	CListBox2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListBox2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListBox2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOX2_H__0DF1C473_0C86_4A16_8D2F_868EBD2F7469__INCLUDED_)
