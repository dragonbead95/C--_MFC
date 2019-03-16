// AniDlg.h : header file
//

#if !defined(AFX_ANIDLG_H__91710C6C_060F_4C50_80AA_275C941257D3__INCLUDED_)
#define AFX_ANIDLG_H__91710C6C_060F_4C50_80AA_275C941257D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAniDlg dialog

class CAniDlg : public CDialog
{
// Construction
public:
	CAniDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAniDlg)
	enum { IDD = IDD_ANI_DIALOG };
	CAnimateCtrl	m_ctlAni;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAniDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAniDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtPlay();
	afx_msg void OnButtStop();
	afx_msg void OnDestroy();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIDLG_H__91710C6C_060F_4C50_80AA_275C941257D3__INCLUDED_)
