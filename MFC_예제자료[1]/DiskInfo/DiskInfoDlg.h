// DiskInfoDlg.h : header file
//

#if !defined(AFX_DISKINFODLG_H__E3258906_F7E6_4B4F_9F0E_CA32A3EF2D47__INCLUDED_)
#define AFX_DISKINFODLG_H__E3258906_F7E6_4B4F_9F0E_CA32A3EF2D47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDiskInfoDlg dialog

class CDiskInfoDlg : public CDialog
{
// Construction
public:
	CString ComMa(CString strNum);
	void DiskInfo(char *szDrv);
	DWORD m_dDriver;
	CDiskInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDiskInfoDlg)
	enum { IDD = IDD_DISKINFO_DIALOG };
	CComboBox	m_ctlDriver;
	CString	m_strAlldisk;
	CString	m_strFat;
	CString	m_strFreedisk;
	CString	m_strLabel;
	CString	m_strType;
	CString	m_strUsedisk;
	CString	m_strSeldrv;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiskInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDiskInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeComboDriver();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISKINFODLG_H__E3258906_F7E6_4B4F_9F0E_CA32A3EF2D47__INCLUDED_)
