// resMenuDlg.h : header file
//

#if !defined(AFX_RESMENUDLG_H__B999C3CE_8AAB_4062_A29B_D2DB4FB37FB4__INCLUDED_)
#define AFX_RESMENUDLG_H__B999C3CE_8AAB_4062_A29B_D2DB4FB37FB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CResMenuDlg dialog

class CResMenuDlg : public CDialog
{
// Construction
public:
	CResMenuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CResMenuDlg)
	enum { IDD = IDD_RESMENU_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CResMenuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtExit();
	afx_msg void OnOpen();
	afx_msg void OnExit();
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESMENUDLG_H__B999C3CE_8AAB_4062_A29B_D2DB4FB37FB4__INCLUDED_)
