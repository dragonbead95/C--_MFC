// ScoCtlDlg.h : header file
//

#if !defined(AFX_SCOCTLDLG_H__773D6F3F_57EF_4D6B_ACAF_AD1C18C3C489__INCLUDED_)
#define AFX_SCOCTLDLG_H__773D6F3F_57EF_4D6B_ACAF_AD1C18C3C489__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScoCtlDlg dialog

class CScoCtlDlg : public CDialog
{
// Construction
public:
	CScoCtlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScoCtlDlg)
	enum { IDD = IDD_SCOCTL_DIALOG };
	CScrollBar	m_scrHori;
	CScrollBar	m_scrVert;
	int		m_iEdit;
	int		m_iEdit2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoCtlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScoCtlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iGreen;
	int m_iRed;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCOCTLDLG_H__773D6F3F_57EF_4D6B_ACAF_AD1C18C3C489__INCLUDED_)
