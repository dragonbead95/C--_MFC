// ButtonDlg.h : header file
//

#if !defined(AFX_BUTTONDLG_H__AEC3ED11_00E7_4C1E_9F4B_E1532BD05ED0__INCLUDED_)
#define AFX_BUTTONDLG_H__AEC3ED11_00E7_4C1E_9F4B_E1532BD05ED0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CButtonDlg dialog

class CButtonDlg : public CDialog
{
// Construction
public:
	CButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CButtonDlg)
	enum { IDD = IDD_BUTTON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtTitle();
	afx_msg void OnButtHide();
	afx_msg void OnButtDisable();
	afx_msg void OnButtExit();
	afx_msg void OnButtTarget();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString m_szTitle;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONDLG_H__AEC3ED11_00E7_4C1E_9F4B_E1532BD05ED0__INCLUDED_)
