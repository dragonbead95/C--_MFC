// MyFontDlg.h : header file
//

#if !defined(AFX_MYFONTDLG_H__60EDAA07_7D71_40A8_A96C_6B54261550A1__INCLUDED_)
#define AFX_MYFONTDLG_H__60EDAA07_7D71_40A8_A96C_6B54261550A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyFontDlg dialog

class CMyFontDlg : public CDialog
{
// Construction
public:
	CMyFontDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyFontDlg)
	enum { IDD = IDD_MYFONT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyFontDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyFontDlg)
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

#endif // !defined(AFX_MYFONTDLG_H__60EDAA07_7D71_40A8_A96C_6B54261550A1__INCLUDED_)
