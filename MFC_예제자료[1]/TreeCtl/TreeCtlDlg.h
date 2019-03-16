// TreeCtlDlg.h : header file
//

#if !defined(AFX_TREECTLDLG_H__A2DA7974_0101_4621_A914_E8A006F3FCC6__INCLUDED_)
#define AFX_TREECTLDLG_H__A2DA7974_0101_4621_A914_E8A006F3FCC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTreeCtlDlg dialog

class CTreeCtlDlg : public CDialog
{
// Construction
public:
	CTreeCtlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTreeCtlDlg)
	enum { IDD = IDD_TREECTL_DIALOG };
	CTreeCtrl	m_ctlTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeCtlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTreeCtlDlg)
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

#endif // !defined(AFX_TREECTLDLG_H__A2DA7974_0101_4621_A914_E8A006F3FCC6__INCLUDED_)
