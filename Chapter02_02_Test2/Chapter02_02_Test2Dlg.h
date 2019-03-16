
// Chapter02_02_Test2Dlg.h: 헤더 파일
//

#pragma once


// CChapter0202Test2Dlg 대화 상자
class CChapter0202Test2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter0202Test2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER02_02_TEST2_DIALOG };
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
	afx_msg void OnClickedButton1();
	afx_msg void OnBnClickedButton2();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void onButton1();
	afx_msg void onButton1();
	char m_;
	int m_nRes;
	void FuncDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
