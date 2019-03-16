// MemoryInfoDlg.h : header file
//

#if !defined(AFX_MEMORYINFODLG_H__DBCE5E0F_14E3_49EC_BF05_3E78E3289546__INCLUDED_)
#define AFX_MEMORYINFODLG_H__DBCE5E0F_14E3_49EC_BF05_3E78E3289546__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMemoryInfoDlg dialog

class CMemoryInfoDlg : public CDialog
{
// Construction
public:
	CMemoryInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMemoryInfoDlg)
	enum { IDD = IDD_MEMORYINFO_DIALOG };
	CString	m_strEdit1;
	int		m_strEdit2;
	int		m_strEdit3;
	int		m_strEdit4;
	int		m_strEdit5;
	int		m_strEdit6;
	int		m_strEdit7;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemoryInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMemoryInfoDlg)
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

#endif // !defined(AFX_MEMORYINFODLG_H__DBCE5E0F_14E3_49EC_BF05_3E78E3289546__INCLUDED_)
