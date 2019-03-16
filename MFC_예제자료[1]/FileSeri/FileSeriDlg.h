// FileSeriDlg.h : header file
//

#if !defined(AFX_FILESERIDLG_H__673CF9FE_0097_4F07_98F7_DCAC448606BC__INCLUDED_)
#define AFX_FILESERIDLG_H__673CF9FE_0097_4F07_98F7_DCAC448606BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileSeriDlg dialog

class CFileSeriDlg : public CDialog
{
// Construction
public:
	CFileSeriDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileSeriDlg)
	enum { IDD = IDD_FILESERI_DIALOG };
	CString	m_strVar1;
	CString	m_strVar2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileSeriDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileSeriDlg)
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

#endif // !defined(AFX_FILESERIDLG_H__673CF9FE_0097_4F07_98F7_DCAC448606BC__INCLUDED_)
