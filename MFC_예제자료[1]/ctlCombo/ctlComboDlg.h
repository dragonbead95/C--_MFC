// ctlComboDlg.h : header file
//

#if !defined(AFX_CTLCOMBODLG_H__763A5BE0_CD71_45BE_A8CF_9CB5AE310832__INCLUDED_)
#define AFX_CTLCOMBODLG_H__763A5BE0_CD71_45BE_A8CF_9CB5AE310832__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCtlComboDlg dialog

class CCtlComboDlg : public CDialog
{
// Construction
public:
	CCtlComboDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCtlComboDlg)
	enum { IDD = IDD_CTLCOMBO_DIALOG };
	CString	m_strCombo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlComboDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCtlComboDlg)
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

#endif // !defined(AFX_CTLCOMBODLG_H__763A5BE0_CD71_45BE_A8CF_9CB5AE310832__INCLUDED_)
