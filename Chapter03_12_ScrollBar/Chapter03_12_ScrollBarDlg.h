
// Chapter03_12_ScrollBarDlg.h: 헤더 파일
//

#pragma once


// CChapter0312ScrollBarDlg 대화 상자
class CChapter0312ScrollBarDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter0312ScrollBarDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER03_12_SCROLLBAR_DIALOG };
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
	int m_iEdit;
	int m_iEdit2;
	CScrollBar m_scrVert;
	CScrollBar m_scrHori;
	afx_msg void OnClickedButtExit();
private:
	int m_iRed;
	int m_iGeen;
public:
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
