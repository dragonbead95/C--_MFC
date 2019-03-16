// RealMemDlg.h : header file
//

#if !defined(AFX_REALMEMDLG_H__0BAE021B_C614_4008_B905_8657062DB78A__INCLUDED_)
#define AFX_REALMEMDLG_H__0BAE021B_C614_4008_B905_8657062DB78A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRealMemDlg dialog

class CRealMemDlg : public CDialog
{
// Construction
public:
	CString ComMa(CString strNum);
	void MemoryInfo();
	CRealMemDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRealMemDlg)
	enum { IDD = IDD_REALMEM_DIALOG };
	CString	m_strEdit1;
	CString	m_strEdit2;
	CString	m_strEdit3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRealMemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRealMemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtExit();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REALMEMDLG_H__0BAE021B_C614_4008_B905_8657062DB78A__INCLUDED_)
