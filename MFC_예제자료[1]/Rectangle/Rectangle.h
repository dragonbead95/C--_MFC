// Rectangle.h : main header file for the RECTANGLE application
//

#if !defined(AFX_RECTANGLE_H__8D6DFFF3_1A52_49D9_8E3F_E1AB3F088E19__INCLUDED_)
#define AFX_RECTANGLE_H__8D6DFFF3_1A52_49D9_8E3F_E1AB3F088E19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRectangleApp:
// See Rectangle.cpp for the implementation of this class
//

class CRectangleApp : public CWinApp
{
public:
	CRectangleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRectangleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRectangleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECTANGLE_H__8D6DFFF3_1A52_49D9_8E3F_E1AB3F088E19__INCLUDED_)
