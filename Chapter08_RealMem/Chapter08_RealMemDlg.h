
// Chapter08_RealMemDlg.h: 헤더 파일
//

#pragma once


// CChapter08RealMemDlg 대화 상자
class CChapter08RealMemDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter08RealMemDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER08_REALMEM_DIALOG };
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
	CString m_strEdit1;
	CString m_strEdit2;
	CString m_strEdit3;
	CString ComMa(CString strNum);
	void MemoryInfo();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnClickedButtExit();
};
