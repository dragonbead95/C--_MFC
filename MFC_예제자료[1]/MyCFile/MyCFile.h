// MyCFile.h : main header file for the MYCFILE application
//

#if !defined(AFX_MYCFILE_H__A077F7E8_69ED_436C_9BC9_8638751F661A__INCLUDED_)
#define AFX_MYCFILE_H__A077F7E8_69ED_436C_9BC9_8638751F661A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyCFileApp:
// See MyCFile.cpp for the implementation of this class
//

class CMyCFileApp : public CWinApp
{
public:
	CMyCFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyCFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCFILE_H__A077F7E8_69ED_436C_9BC9_8638751F661A__INCLUDED_)
