// GetWindowsDlg.h : header file
//

#if !defined(AFX_GETWINDOWSDLG_H__5B18D467_7E86_448C_8C34_F2223720D4D8__INCLUDED_)
#define AFX_GETWINDOWSDLG_H__5B18D467_7E86_448C_8C34_F2223720D4D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetWindowsDlg dialog

class CGetWindowsDlg : public CDialog
{
// Construction
public:
	CGetWindowsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetWindowsDlg)
	enum { IDD = IDD_GETWINDOWS_DIALOG };
	CString	m_strEdit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetWindowsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetWindowsDlg)
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

#endif // !defined(AFX_GETWINDOWSDLG_H__5B18D467_7E86_448C_8C34_F2223720D4D8__INCLUDED_)
