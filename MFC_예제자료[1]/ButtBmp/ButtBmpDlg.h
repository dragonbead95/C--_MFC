// ButtBmpDlg.h : header file
//

#if !defined(AFX_BUTTBMPDLG_H__B53C98B2_4E32_4B6E_97BE_580861F2AAA1__INCLUDED_)
#define AFX_BUTTBMPDLG_H__B53C98B2_4E32_4B6E_97BE_580861F2AAA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CButtBmpDlg dialog

class CButtBmpDlg : public CDialog
{
// Construction
public:
	CButtBmpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CButtBmpDlg)
	enum { IDD = IDD_BUTTBMP_DIALOG };
	CButton	m_Butt;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtBmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CButtBmpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTBMPDLG_H__B53C98B2_4E32_4B6E_97BE_580861F2AAA1__INCLUDED_)
