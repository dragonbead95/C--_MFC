// CalenDlg.h : header file
//

#if !defined(AFX_CALENDLG_H__1A5B7159_3052_40C7_AF96_3BA4CA4FF50C__INCLUDED_)
#define AFX_CALENDLG_H__1A5B7159_3052_40C7_AF96_3BA4CA4FF50C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalenDlg dialog

class CCalenDlg : public CDialog
{
// Construction
public:
	void DatePrint();
	void BackGround();
	int m_nMonth;
	int m_nYear;
	CCalenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalenDlg)
	enum { IDD = IDD_CALEN_DIALOG };
	CComboBox	m_ctlMonth;
	
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnButtExit();
	afx_msg void OnSelchangeComboMonth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALENDLG_H__1A5B7159_3052_40C7_AF96_3BA4CA4FF50C__INCLUDED_)
