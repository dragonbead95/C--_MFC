// FileOpenNextDlg.h : header file
//

#if !defined(AFX_FILEOPENNEXTDLG_H__8DF5ED3C_213F_446D_87B9_E4D6CA1549C7__INCLUDED_)
#define AFX_FILEOPENNEXTDLG_H__8DF5ED3C_213F_446D_87B9_E4D6CA1549C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileOpenNextDlg dialog

class CFileOpenNextDlg : public CDialog
{
// Construction
public:
	CFileOpenNextDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileOpenNextDlg)
	enum { IDD = IDD_FILEOPENNEXT_DIALOG };
	CListBox	m_ctlList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileOpenNextDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileOpenNextDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtOpen();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEOPENNEXTDLG_H__8DF5ED3C_213F_446D_87B9_E4D6CA1549C7__INCLUDED_)
