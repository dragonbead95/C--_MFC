// Maze.h : main header file for the MAZE application
//

#if !defined(AFX_MAZE_H__085A7FD0_DDCB_407C_A902_25C9ACD7DEF9__INCLUDED_)
#define AFX_MAZE_H__085A7FD0_DDCB_407C_A902_25C9ACD7DEF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMazeApp:
// See Maze.cpp for the implementation of this class
//

class CMazeApp : public CWinApp
{
public:
	CMazeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMazeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZE_H__085A7FD0_DDCB_407C_A902_25C9ACD7DEF9__INCLUDED_)
