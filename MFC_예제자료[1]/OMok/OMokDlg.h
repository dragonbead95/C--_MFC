// OMokDlg.h : header file
//

#if !defined(AFX_OMOKDLG_H__6D2393B9_19B3_4CD7_9DFD_0E1360C5751E__INCLUDED_)
#define AFX_OMOKDLG_H__6D2393B9_19B3_4CD7_9DFD_0E1360C5751E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COMokDlg dialog

class COMokDlg : public CDialog
{
// Construction
public:
	BOOL m_bTurn;
	void DrawAl();
	void InitBoard();
	int m_nBoard[10][10];
	BOOL m_bStart;
	void DrawBack();
	COMokDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COMokDlg)
	enum { IDD = IDD_OMOK_DIALOG };
	CString	m_strColAl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COMokDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COMokDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButtRestart();
	afx_msg void OnOpen();
	afx_msg void OnSave();
	afx_msg void OnExit();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OMOKDLG_H__6D2393B9_19B3_4CD7_9DFD_0E1360C5751E__INCLUDED_)
