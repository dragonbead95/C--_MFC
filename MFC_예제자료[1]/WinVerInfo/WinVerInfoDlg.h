// WinVerInfoDlg.h : header file
//

#if !defined(AFX_WINVERINFODLG_H__B1AD8534_0464_4499_96E3_0E617CFF927A__INCLUDED_)
#define AFX_WINVERINFODLG_H__B1AD8534_0464_4499_96E3_0E617CFF927A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWinVerInfoDlg dialog

class CWinVerInfoDlg : public CDialog
{
// Construction
public:
	CWinVerInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWinVerInfoDlg)
	enum { IDD = IDD_WINVERINFO_DIALOG };
	CString	m_strEdit1;
	int		m_strEdit2;
	CString	m_strEdit3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinVerInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWinVerInfoDlg)
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

#endif // !defined(AFX_WINVERINFODLG_H__B1AD8534_0464_4499_96E3_0E617CFF927A__INCLUDED_)
