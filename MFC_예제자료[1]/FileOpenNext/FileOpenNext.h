// FileOpenNext.h : main header file for the FILEOPENNEXT application
//

#if !defined(AFX_FILEOPENNEXT_H__A3DB5222_7787_4B24_AC1D_41C0785D8E93__INCLUDED_)
#define AFX_FILEOPENNEXT_H__A3DB5222_7787_4B24_AC1D_41C0785D8E93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileOpenNextApp:
// See FileOpenNext.cpp for the implementation of this class
//

class CFileOpenNextApp : public CWinApp
{
public:
	CFileOpenNextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileOpenNextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileOpenNextApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEOPENNEXT_H__A3DB5222_7787_4B24_AC1D_41C0785D8E93__INCLUDED_)
