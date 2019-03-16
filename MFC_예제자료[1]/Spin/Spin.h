// Spin.h : main header file for the SPIN application
//

#if !defined(AFX_SPIN_H__D4674BDF_BD64_4B7C_A7E5_22F5D4DE1DCC__INCLUDED_)
#define AFX_SPIN_H__D4674BDF_BD64_4B7C_A7E5_22F5D4DE1DCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpinApp:
// See Spin.cpp for the implementation of this class
//

class CSpinApp : public CWinApp
{
public:
	CSpinApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSpinApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPIN_H__D4674BDF_BD64_4B7C_A7E5_22F5D4DE1DCC__INCLUDED_)
