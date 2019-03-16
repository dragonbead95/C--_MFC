// NumTimerDlg.h : header file
//

#if !defined(AFX_NUMTIMERDLG_H__B4CB4970_F96A_4EF9_A249_64159DD05E96__INCLUDED_)
#define AFX_NUMTIMERDLG_H__B4CB4970_F96A_4EF9_A249_64159DD05E96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNumTimerDlg dialog

class CNumTimerDlg : public CDialog
{
// Construction
public:
	CNumTimerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNumTimerDlg)
	enum { IDD = IDD_NUMTIMER_DIALOG };
	CString	m_strMess;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumTimerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNumTimerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtStart();
	afx_msg void OnButtStop();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMTIMERDLG_H__B4CB4970_F96A_4EF9_A249_64159DD05E96__INCLUDED_)
