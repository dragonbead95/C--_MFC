// ColorDlgDlg.h : header file
//

#if !defined(AFX_COLORDLGDLG_H__5EFADBD0_D345_4A64_9E81_09615B2882AA__INCLUDED_)
#define AFX_COLORDLGDLG_H__5EFADBD0_D345_4A64_9E81_09615B2882AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CColorDlgDlg dialog

class CColorDlgDlg : public CDialog
{
// Construction
public:
	COLORREF m_Color;
	CColorDlgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CColorDlgDlg)
	enum { IDD = IDD_COLORDLG_DIALOG };
	CString	m_strEdit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CColorDlgDlg)
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

#endif // !defined(AFX_COLORDLGDLG_H__5EFADBD0_D345_4A64_9E81_09615B2882AA__INCLUDED_)
