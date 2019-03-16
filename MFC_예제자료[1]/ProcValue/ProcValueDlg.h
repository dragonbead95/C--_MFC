// ProcValueDlg.h : header file
//

#if !defined(AFX_PROCVALUEDLG_H__8F9ECB22_DEF8_4370_8768_86928AA2E18D__INCLUDED_)
#define AFX_PROCVALUEDLG_H__8F9ECB22_DEF8_4370_8768_86928AA2E18D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProcValueDlg dialog

class CProcValueDlg : public CDialog
{
// Construction
public:
	CProcValueDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProcValueDlg)
	enum { IDD = IDD_PROCVALUE_DIALOG };
	CListCtrl	m_ListValue;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcValueDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProcValueDlg)
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

#endif // !defined(AFX_PROCVALUEDLG_H__8F9ECB22_DEF8_4370_8768_86928AA2E18D__INCLUDED_)
