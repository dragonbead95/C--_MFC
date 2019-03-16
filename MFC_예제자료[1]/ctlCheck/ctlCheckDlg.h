// ctlCheckDlg.h : header file
//

#if !defined(AFX_CTLCHECKDLG_H__1774B77C_B97E_4BC3_8F3C_DDCA7B80F38C__INCLUDED_)
#define AFX_CTLCHECKDLG_H__1774B77C_B97E_4BC3_8F3C_DDCA7B80F38C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCtlCheckDlg dialog

class CCtlCheckDlg : public CDialog
{
// Construction
public:
	CCtlCheckDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCtlCheckDlg)
	enum { IDD = IDD_CTLCHECK_DIALOG };
	BOOL	m_ctlCheck;
	CString	m_strEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlCheckDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCtlCheckDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheckMess();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTLCHECKDLG_H__1774B77C_B97E_4BC3_8F3C_DDCA7B80F38C__INCLUDED_)
