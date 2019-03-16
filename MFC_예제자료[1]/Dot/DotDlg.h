// DotDlg.h : header file
//

#if !defined(AFX_DOTDLG_H__C9C8019B_FBDF_4E9B_B1D2_87F1003558C9__INCLUDED_)
#define AFX_DOTDLG_H__C9C8019B_FBDF_4E9B_B1D2_87F1003558C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDotDlg dialog

class CDotDlg : public CDialog
{
// Construction
public:
	CDotDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDotDlg)
	enum { IDD = IDD_DOT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDotDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDotDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButtExit();
	afx_msg void OnButtClean();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOTDLG_H__C9C8019B_FBDF_4E9B_B1D2_87F1003558C9__INCLUDED_)
