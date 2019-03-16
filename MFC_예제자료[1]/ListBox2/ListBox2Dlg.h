// ListBox2Dlg.h : header file
//

#if !defined(AFX_LISTBOX2DLG_H__37BBE56E_4629_42EB_85F4_227F2F5D6F3C__INCLUDED_)
#define AFX_LISTBOX2DLG_H__37BBE56E_4629_42EB_85F4_227F2F5D6F3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListBox2Dlg dialog

class CListBox2Dlg : public CDialog
{
// Construction
public:
	CListBox2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListBox2Dlg)
	enum { IDD = IDD_LISTBOX2_DIALOG };
	CListBox	m_cListBox;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListBox2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListBox2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOX2DLG_H__37BBE56E_4629_42EB_85F4_227F2F5D6F3C__INCLUDED_)
