// RectangleDlg.h : header file
//

#if !defined(AFX_RECTANGLEDLG_H__08C8C893_37C0_4532_991A_F3F2DB330A52__INCLUDED_)
#define AFX_RECTANGLEDLG_H__08C8C893_37C0_4532_991A_F3F2DB330A52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRectangleDlg dialog

class CRectangleDlg : public CDialog
{
// Construction
public:
	CRectangleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRectangleDlg)
	enum { IDD = IDD_RECTANGLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRectangleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRectangleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtEllipse();
	afx_msg void OnButtRectangle();
	afx_msg void OnButtExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECTANGLEDLG_H__08C8C893_37C0_4532_991A_F3F2DB330A52__INCLUDED_)
