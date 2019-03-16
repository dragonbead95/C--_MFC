// ListBox.h : main header file for the LISTBOX application
//

#if !defined(AFX_LISTBOX_H__3006C356_A300_40FC_9149_49A3E43E4B1D__INCLUDED_)
#define AFX_LISTBOX_H__3006C356_A300_40FC_9149_49A3E43E4B1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListBoxApp:
// See ListBox.cpp for the implementation of this class
//

class CListBoxApp : public CWinApp
{
public:
	CListBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOX_H__3006C356_A300_40FC_9149_49A3E43E4B1D__INCLUDED_)
