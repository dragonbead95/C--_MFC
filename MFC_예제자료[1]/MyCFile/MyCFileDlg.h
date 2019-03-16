// MyCFileDlg.h : header file
//

#if !defined(AFX_MYCFILEDLG_H__56B6730C_0238_4CE7_9DF1_D3993225702A__INCLUDED_)
#define AFX_MYCFILEDLG_H__56B6730C_0238_4CE7_9DF1_D3993225702A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyCFileDlg dialog

class CMyCFileDlg : public CDialog
{
// Construction
public:
	CMyCFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyCFileDlg)
	enum { IDD = IDD_MYCFILE_DIALOG };
	CString	m_strMess;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyCFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtWrite();
	afx_msg void OnButtRead();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCFILEDLG_H__56B6730C_0238_4CE7_9DF1_D3993225702A__INCLUDED_)
