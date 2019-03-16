// ctlProDlg.h : header file
//

#if !defined(AFX_CTLPRODLG_H__1B7708C9_13E3_4F31_892A_636307FD68E3__INCLUDED_)
#define AFX_CTLPRODLG_H__1B7708C9_13E3_4F31_892A_636307FD68E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCtlProDlg dialog

class CCtlProDlg : public CDialog
{
// Construction
public:
	CCtlProDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCtlProDlg)
	enum { IDD = IDD_CTLPRO_DIALOG };
	CProgressCtrl	m_ctlPro;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlProDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCtlProDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtStart();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTLPRODLG_H__1B7708C9_13E3_4F31_892A_636307FD68E3__INCLUDED_)
