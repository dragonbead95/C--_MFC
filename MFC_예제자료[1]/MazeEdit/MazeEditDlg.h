// MazeEditDlg.h : header file
//

#if !defined(AFX_MAZEEDITDLG_H__2A9FF281_92B2_4634_8855_6E5A5F2837EF__INCLUDED_)
#define AFX_MAZEEDITDLG_H__2A9FF281_92B2_4634_8855_6E5A5F2837EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMazeEditDlg dialog

class CMazeEditDlg : public CDialog
{
// Construction
public:
	void DrawNum();
	BOOL PosToIndex(CPoint pClkMus, CPoint &pMus);
	int m_nMaze[20][20];
	int m_nBlock;
	void InitMaze();
	void DrawBlock(CPoint pMus);
	CMazeEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMazeEditDlg)
	enum { IDD = IDD_MAZEEDIT_DIALOG };
	CString	m_strMus;
	CString	m_strBlock;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMazeEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtRedraw();
	afx_msg void OnButtStart();
	afx_msg void OnButtEnd();
	afx_msg void OnButtBlock();
	afx_msg void OnButtRoad();
	afx_msg void OnButtExit();
	afx_msg void OnLoad();
	afx_msg void OnSave();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZEEDITDLG_H__2A9FF281_92B2_4634_8855_6E5A5F2837EF__INCLUDED_)
