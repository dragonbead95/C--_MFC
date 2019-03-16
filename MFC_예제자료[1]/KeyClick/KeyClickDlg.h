// KeyClickDlg.h : header file
//

#if !defined(AFX_KEYCLICKDLG_H__8561E8BC_2EDD_4710_A740_AC6A23E90F07__INCLUDED_)
#define AFX_KEYCLICKDLG_H__8561E8BC_2EDD_4710_A740_AC6A23E90F07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKeyClickDlg dialog

class CKeyClickDlg : public CDialog
{
// Construction
public:
	CKeyClickDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKeyClickDlg)
	enum { IDD = IDD_KEYCLICK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyClickDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKeyClickDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYCLICKDLG_H__8561E8BC_2EDD_4710_A740_AC6A23E90F07__INCLUDED_)
