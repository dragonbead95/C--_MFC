// PlayWav.h : main header file for the PLAYWAV application
//

#if !defined(AFX_PLAYWAV_H__5AB9E15E_FB6F_4B2E_9A4E_D7A8E99C9D4D__INCLUDED_)
#define AFX_PLAYWAV_H__5AB9E15E_FB6F_4B2E_9A4E_D7A8E99C9D4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlayWavApp:
// See PlayWav.cpp for the implementation of this class
//

class CPlayWavApp : public CWinApp
{
public:
	CPlayWavApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayWavApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPlayWavApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYWAV_H__5AB9E15E_FB6F_4B2E_9A4E_D7A8E99C9D4D__INCLUDED_)
