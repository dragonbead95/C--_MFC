// SystemInfoDlg.h : header file
//

#if !defined(AFX_SYSTEMINFODLG_H__411FAE85_3224_4989_B491_3EC754E02146__INCLUDED_)
#define AFX_SYSTEMINFODLG_H__411FAE85_3224_4989_B491_3EC754E02146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSystemInfoDlg dialog

class CSystemInfoDlg : public CDialog
{
// Construction
public:
	CSystemInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSystemInfoDlg)
	enum { IDD = IDD_SYSTEMINFO_DIALOG };
	CString	m_strBooting;
	CString	m_strMusButt;
	CString	m_strVga;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSystemInfoDlg)
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

#endif // !defined(AFX_SYSTEMINFODLG_H__411FAE85_3224_4989_B491_3EC754E02146__INCLUDED_)
