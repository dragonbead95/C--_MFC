// FileOpenDlgDlg.h : header file
//

#if !defined(AFX_FILEOPENDLGDLG_H__3FDC04F5_5B5C_4426_AF54_A163910D7F97__INCLUDED_)
#define AFX_FILEOPENDLGDLG_H__3FDC04F5_5B5C_4426_AF54_A163910D7F97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileOpenDlgDlg dialog

class CFileOpenDlgDlg : public CDialog
{
// Construction
public:
	CFileOpenDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileOpenDlgDlg)
	enum { IDD = IDD_FILEOPENDLG_DIALOG };
	CString	m_strEdit1;
	CString	m_strEdit2;
	CString	m_strEdit3;
	CString	m_strEdit4;
	CString	m_strEdit5;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileOpenDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileOpenDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtOpen();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEOPENDLGDLG_H__3FDC04F5_5B5C_4426_AF54_A163910D7F97__INCLUDED_)
