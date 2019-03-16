// CalCuDlg.h : header file
//

#if !defined(AFX_CALCUDLG_H__D6E9C07C_5B30_452D_86D9_1C183CBC6588__INCLUDED_)
#define AFX_CALCUDLG_H__D6E9C07C_5B30_452D_86D9_1C183CBC6588__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalCuDlg dialog

class CCalCuDlg : public CDialog
{
// Construction
public:
	void Cal(int a);
	CString m_strNumber;
	int m_iTwo;
	int m_iCal;
	int m_iSwitch;
	int m_iOne;
	void Number(int a);
	CCalCuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalCuDlg)
	enum { IDD = IDD_CALCU_DIALOG };
	CString	m_strLed;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalCuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalCuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButt0();
	afx_msg void OnButt1();
	afx_msg void OnButtAdd();
	afx_msg void OnButtResult();
	afx_msg void OnButtZero();
	afx_msg void OnButt2();
	afx_msg void OnButt3();
	afx_msg void OnButt4();
	afx_msg void OnButt5();
	afx_msg void OnButt6();
	afx_msg void OnButt7();
	afx_msg void OnButt8();
	afx_msg void OnButt9();
	afx_msg void OnButtSub();
	afx_msg void OnButtMul();
	afx_msg void OnButtDiv();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCUDLG_H__D6E9C07C_5B30_452D_86D9_1C183CBC6588__INCLUDED_)
