// ctlEditDlg.h : header file
//

#if !defined(AFX_CTLEDITDLG_H__877C1A84_C199_477A_A6A8_3DD85319D73E__INCLUDED_)
#define AFX_CTLEDITDLG_H__877C1A84_C199_477A_A6A8_3DD85319D73E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCtlEditDlg dialog

class CCtlEditDlg : public CDialog
{
// Construction
public:
	CCtlEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCtlEditDlg)
	enum { IDD = IDD_CTLEDIT_DIALOG };
	CString	m_strEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCtlEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtPrint();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTLEDITDLG_H__877C1A84_C199_477A_A6A8_3DD85319D73E__INCLUDED_)
