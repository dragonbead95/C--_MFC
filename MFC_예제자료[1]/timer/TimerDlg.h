// TimerDlg.h : header file
//

#if !defined(AFX_TIMERDLG_H__F959C444_6C33_4D8D_8EED_E42C58FF6862__INCLUDED_)
#define AFX_TIMERDLG_H__F959C444_6C33_4D8D_8EED_E42C58FF6862__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg dialog

class CTimerDlg : public CDialog
{
// Construction
public:
	BOOL m_bApply;
	CTimerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTimerDlg)
	enum { IDD = IDD_TIMER_DIALOG };
	int		m_nSec;
	int		m_nMin;
	int		m_nHour;
	CString	m_strSetTimer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTimerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtApply();
	afx_msg void OnButtCancel();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMERDLG_H__F959C444_6C33_4D8D_8EED_E42C58FF6862__INCLUDED_)
