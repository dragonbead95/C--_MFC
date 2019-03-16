// SpinDlg.h : header file
//

#if !defined(AFX_SPINDLG_H__4AF64876_807A_45D3_B16F_E2F301380098__INCLUDED_)
#define AFX_SPINDLG_H__4AF64876_807A_45D3_B16F_E2F301380098__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSpinDlg dialog

class CSpinDlg : public CDialog
{
// Construction
public:
	CSpinDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSpinDlg)
	enum { IDD = IDD_SPIN_DIALOG };
	CSpinButtonCtrl	m_ctlSpin;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpinDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSpinDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINDLG_H__4AF64876_807A_45D3_B16F_E2F301380098__INCLUDED_)
