
// Chapter07_CalenderDlg.h: 헤더 파일
//

#pragma once


// CChapter07CalenderDlg 대화 상자
class CChapter07CalenderDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter07CalenderDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER07_CALENDER_DIALOG };
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
	int m_nMonth;
//	CString m_nYear;
//	CString m_ctlMonth;
	CComboBox m_ctlMonth;
//	int m_nYear;
	int m_nYear;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSelchangeComboMonth();
	void BackGround();
	void DatePrint();
	afx_msg void OnClickedButtExit();
};
