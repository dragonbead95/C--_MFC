
// Chapter03_14_SpinCtlDlg.h: 헤더 파일
//

#pragma once


// CChapter0314SpinCtlDlg 대화 상자
class CChapter0314SpinCtlDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter0314SpinCtlDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER03_14_SPINCTL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_ctlSpin;
	afx_msg void OnClickedButton1();
};
