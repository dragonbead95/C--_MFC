
// Chapter10_OMokDlg.h: 헤더 파일
//

#pragma once


// CChapter10OMokDlg 대화 상자
class CChapter10OMokDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter10OMokDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER10_OMOK_DIALOG };
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
	CString m_strColAl;
	afx_msg void OnFileOpen();
	void DrawBack();
	BOOL m_bStart;
	afx_msg void OnClickedButtStart();
	int m_nBoard[10][10];
	void InitBoard();
	void DrawAI();
	BOOL m_bTurn;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnClickedButtRestart();
	afx_msg void OnFileSave();
	afx_msg void OnClickedButtExit();
};
