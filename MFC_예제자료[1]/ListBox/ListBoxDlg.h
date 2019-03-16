// ListBoxDlg.h : header file
//

#if !defined(AFX_LISTBOXDLG_H__509FBFED_62D0_45CE_A526_2A0FD9504911__INCLUDED_)
#define AFX_LISTBOXDLG_H__509FBFED_62D0_45CE_A526_2A0FD9504911__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListBoxDlg dialog

class CListBoxDlg : public CDialog
{
// Construction
public:
	CListBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListBoxDlg)
	enum { IDD = IDD_LISTBOX_DIALOG };
	CListBox	m_cListBox;
	CString	m_strInput;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtAdd();
	afx_msg void OnButtDelete();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOXDLG_H__509FBFED_62D0_45CE_A526_2A0FD9504911__INCLUDED_)
