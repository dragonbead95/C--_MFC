// BmpLoadDlg.h : header file
//

#if !defined(AFX_BMPLOADDLG_H__28F00FF3_4068_4FF2_9EFB_DDA4E9D44FC5__INCLUDED_)
#define AFX_BMPLOADDLG_H__28F00FF3_4068_4FF2_9EFB_DDA4E9D44FC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmpLoadDlg dialog

class CBmpLoadDlg : public CDialog
{
// Construction
public:
	CBmpLoadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBmpLoadDlg)
	enum { IDD = IDD_BMPLOAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpLoadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmpLoadDlg)
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

#endif // !defined(AFX_BMPLOADDLG_H__28F00FF3_4068_4FF2_9EFB_DDA4E9D44FC5__INCLUDED_)
