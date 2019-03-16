// MazeDlg.h : header file
//

#if !defined(AFX_MAZEDLG_H__06D62B0F_E909_4B72_9293_A532CEDD3A8A__INCLUDED_)
#define AFX_MAZEDLG_H__06D62B0F_E909_4B72_9293_A532CEDD3A8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMazeDlg dialog

class CMazeDlg : public CDialog
{
// Construction
public:
	CPoint m_pStart;
	void Ai(int &a);
	void MovChar();
	void RoadPostion(CPoint p,int &nLeft, int &nUp, int &nRight, int &nDown);
	BOOL CharPostion(CPoint &p);
	void CleanChar(int nMovY,int nMovX,CPoint p);
	void DrawChar(int nMovY,int nMovX,CPoint p);
	BOOL StartPoint(CPoint &p);
	void DrawBlock(CPoint pMus);
	void InitMaze();
	int m_nMaze[20][20];
	CMazeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMazeDlg)
	enum { IDD = IDD_MAZE_DIALOG };
	CString	m_strDown;
	CString	m_strFrag;
	CString	m_strLeft;
	CString	m_strRight;
	CString	m_strUp;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMazeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLoad();
	afx_msg void OnButtStart();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtRestart();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZEDLG_H__06D62B0F_E909_4B72_9293_A532CEDD3A8A__INCLUDED_)
