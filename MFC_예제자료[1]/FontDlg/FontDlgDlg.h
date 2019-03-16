// FontDlgDlg.h : header file
//

#if !defined(AFX_FONTDLGDLG_H__E3DC9423_BE57_4C00_B2CF_1626153F1649__INCLUDED_)
#define AFX_FONTDLGDLG_H__E3DC9423_BE57_4C00_B2CF_1626153F1649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFontDlgDlg dialog

class CFontDlgDlg : public CDialog
{
// Construction
public:
	CFontDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFontDlgDlg)
	enum { IDD = IDD_FONTDLG_DIALOG };
	CString	m_strEdit1;
	CString	m_strEdit2;
	CString	m_strEdit3;
	CString	m_strEdit4;
	CString	m_strEdit6;
	CString	m_strEdit7;
	CString	m_strEdit8;
	CString	m_strEdit5;
	CString	m_strEdit9;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFontDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFontDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FONTDLGDLG_H__E3DC9423_BE57_4C00_B2CF_1626153F1649__INCLUDED_)
