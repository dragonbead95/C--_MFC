// TextOutDlg.h : header file
//

#if !defined(AFX_TEXTOUTDLG_H__18B5E75E_A158_45A2_AF70_39F13178CCD1__INCLUDED_)
#define AFX_TEXTOUTDLG_H__18B5E75E_A158_45A2_AF70_39F13178CCD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTextOutDlg dialog

class CTextOutDlg : public CDialog
{
// Construction
public:
	CTextOutDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTextOutDlg)
	enum { IDD = IDD_TEXTOUT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextOutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTextOutDlg)
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

#endif // !defined(AFX_TEXTOUTDLG_H__18B5E75E_A158_45A2_AF70_39F13178CCD1__INCLUDED_)
