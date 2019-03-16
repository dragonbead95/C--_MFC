// ctlPro.h : main header file for the CTLPRO application
//

#if !defined(AFX_CTLPRO_H__51A5F447_4E97_44AA_87D2_96647E571500__INCLUDED_)
#define AFX_CTLPRO_H__51A5F447_4E97_44AA_87D2_96647E571500__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtlProApp:
// See ctlPro.cpp for the implementation of this class
//

class CCtlProApp : public CWinApp
{
public:
	CCtlProApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCtlProApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTLPRO_H__51A5F447_4E97_44AA_87D2_96647E571500__INCLUDED_)
