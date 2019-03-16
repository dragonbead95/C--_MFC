// ListCtlDlg.h : header file
//

#if !defined(AFX_LISTCTLDLG_H__A5B69E31_2690_473C_898C_7F3E627A3C90__INCLUDED_)
#define AFX_LISTCTLDLG_H__A5B69E31_2690_473C_898C_7F3E627A3C90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListCtlDlg dialog

class CListCtlDlg : public CDialog
{
// Construction
public:
	CListCtlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListCtlDlg)
	enum { IDD = IDD_LISTCTL_DIALOG };
	CListCtrl	m_ListC;
	CString	m_strName;
	CString	m_strMail;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListCtlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtAdd();
	afx_msg void OnDblclkListCtl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTLDLG_H__A5B69E31_2690_473C_898C_7F3E627A3C90__INCLUDED_)
