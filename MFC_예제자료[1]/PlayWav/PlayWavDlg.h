// PlayWavDlg.h : header file
//

#if !defined(AFX_PLAYWAVDLG_H__84A0F0A2_7822_4401_82EE_D058AED54362__INCLUDED_)
#define AFX_PLAYWAVDLG_H__84A0F0A2_7822_4401_82EE_D058AED54362__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPlayWavDlg dialog

class CPlayWavDlg : public CDialog
{
// Construction
public:
	DWORD m_dwID;
	CPlayWavDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPlayWavDlg)
	enum { IDD = IDD_PLAYWAV_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayWavDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlayWavDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtOpen();
	afx_msg void OnButtPlay();
	afx_msg void OnButtFirst();
	afx_msg void OnButtStop();
	afx_msg void OnButtPause();
	afx_msg void OnButtResume();
	afx_msg void OnButtExit();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYWAVDLG_H__84A0F0A2_7822_4401_82EE_D058AED54362__INCLUDED_)
