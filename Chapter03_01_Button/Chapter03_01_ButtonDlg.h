
// Chapter03_01_ButtonDlg.h: 헤더 파일
//

#pragma once


// CChapter0301ButtonDlg 대화 상자
class CChapter0301ButtonDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter0301ButtonDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER03_01_BUTTON_DIALOG };
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
	afx_msg void OnClickedButtTitle();
private:
	CString m_szTitle;
public:
	afx_msg void OnClickedButtHide();
	afx_msg void OnClickedButtDisable();
	afx_msg void OnClickedButtExit();
};
