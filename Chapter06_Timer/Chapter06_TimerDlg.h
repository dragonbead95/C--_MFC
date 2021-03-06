
// Chapter06_TimerDlg.h: 헤더 파일
//

#pragma once


// CChapter06TimerDlg 대화 상자
class CChapter06TimerDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter06TimerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER06_TIMER_DIALOG };
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
	int m_nHour;
	int m_nMin;
	int m_nSec;
	CString m_strSetTimer;
	afx_msg void OnClickedButtApply();
	afx_msg void OnClickedButtCancel();
	afx_msg void OnClickedButtExit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	BOOL m_bApply;
};
