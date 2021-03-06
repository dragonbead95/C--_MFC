
// Chapter04_14_03_ColorDlgDlg.h: 헤더 파일
//

#pragma once


// CChapter041403ColorDlgDlg 대화 상자
class CChapter041403ColorDlgDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter041403ColorDlgDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER04_14_03_COLORDLG_DIALOG };
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
	afx_msg void OnClickedButtOpen();
	afx_msg void OnClickedButtExit();
	COLORREF m_Color;
};
