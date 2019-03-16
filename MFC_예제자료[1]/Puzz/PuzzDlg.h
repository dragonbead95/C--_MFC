// PuzzDlg.h : header file
//

#if !defined(AFX_PUZZDLG_H__CD059025_2105_4BDA_B010_7112708A15BB__INCLUDED_)
#define AFX_PUZZDLG_H__CD059025_2105_4BDA_B010_7112708A15BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPuzzDlg dialog

class CPuzzDlg : public CDialog
{
// Construction
public:
	BOOL m_bStart;
	int m_nPuzz[3][3];
	CBitmap m_bitPuzz;
	BOOL CheckPuzz();
	void RandPuzzBmp();
	void ZeroRect(int nZeroY, int nZeroX);
	void MovePuzzBmp(int nMusY,int nMusX,int nZeroY,int nZeroX);
	BOOL ZeroPostion(int nMusY,int nMusX,int &nZeroY,int &nZeroX);
	BOOL PosToIndex(CPoint pos,int &nY, int &nX);
	void DrawNum();
	void DrawBack();
	void InitPuzz();
	void DrawPuzzBmp(int nRow,int nCol,int nNum);
	void DrawBmp();
	CPuzzDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPuzzDlg)
	enum { IDD = IDD_PUZZ_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPuzzDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPuzzDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUZZDLG_H__CD059025_2105_4BDA_B010_7112708A15BB__INCLUDED_)
