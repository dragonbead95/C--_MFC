// PaintTextDlg.h : header file
//

#if !defined(AFX_PAINTTEXTDLG_H__DDF2224E_2DD2_4803_B315_5C1691AE25AC__INCLUDED_)
#define AFX_PAINTTEXTDLG_H__DDF2224E_2DD2_4803_B315_5C1691AE25AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPaintTextDlg dialog

class CPaintTextDlg : public CDialog
{
// Construction
public:
	CPaintTextDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPaintTextDlg)
	enum { IDD = IDD_PAINTTEXT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintTextDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPaintTextDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTTEXTDLG_H__DDF2224E_2DD2_4803_B315_5C1691AE25AC__INCLUDED_)
