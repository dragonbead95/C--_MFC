// ClkMouseDlg.h : header file
//

#if !defined(AFX_CLKMOUSEDLG_H__7EAF3E00_AC6E_4701_A02E_077D8B8AD3EC__INCLUDED_)
#define AFX_CLKMOUSEDLG_H__7EAF3E00_AC6E_4701_A02E_077D8B8AD3EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClkMouseDlg dialog

class CClkMouseDlg : public CDialog
{
// Construction
public:
	CClkMouseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClkMouseDlg)
	enum { IDD = IDD_CLKMOUSE_DIALOG };
	CString	m_strMouse;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClkMouseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClkMouseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLKMOUSEDLG_H__7EAF3E00_AC6E_4701_A02E_077D8B8AD3EC__INCLUDED_)
