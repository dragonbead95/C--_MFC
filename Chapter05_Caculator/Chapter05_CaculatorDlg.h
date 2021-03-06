
// Chapter05_CaculatorDlg.h: 헤더 파일
//

#pragma once


// CChapter05CaculatorDlg 대화 상자
class CChapter05CaculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter05CaculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER05_CACULATOR_DIALOG };
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
	CString m_strLed;
	afx_msg void OnClickedButt9();
	afx_msg void OnClickedButt8();
	afx_msg void OnClickedButt7();
	afx_msg void OnClickedButt6();
	afx_msg void OnClickedButt5();
	afx_msg void OnClickedButt4();
	afx_msg void OnClickedButt3();
	afx_msg void OnClickedButt2();
	afx_msg void OnClickedButt1();
	afx_msg void OnClickedButt0();
	afx_msg void OnClickedButtAdd();
	afx_msg void OnClickedButtDiv();
	afx_msg void OnClickedButtExit();
	afx_msg void OnClickedButtMul();
	afx_msg void OnClickedButtResult();
	afx_msg void OnClickedButtSub();
	afx_msg void OnClickedButtZero();
	CString m_strNumer;
	int m_iOne;
	int m_iTwo;
	int m_iCal;
	int m_iSwitch;
	void Number(int a);
	void Cal(int a);
};
