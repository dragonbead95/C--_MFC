
// Chapter10_PuzzDlg.h: 헤더 파일
//

#pragma once


// CChapter10PuzzDlg 대화 상자
class CChapter10PuzzDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter10PuzzDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER10_PUZZ_DIALOG };
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
	int m_nPuzz[3][3];
	BOOL m_bStart;
	CBitmap m_bitPuzz;
	void InitPuzz();
	void DrawBmp();
	void DrawPuzzBmp(int nRow, int nCol, int nNum);
	void DrawBack();
	void DrawNum();
	void ZeroRect(int nZeroY, int nZeroX);
	BOOL ZeroPosition(int nMusY, int nMusX, int &nZeroY, int &nZeroX);
	void MovePuzzBmp(int nMusY, int nMusX, int nZeroY, int nZeroX);
	BOOL PosToIndex(CPoint pos, int &nY, int &nX);
	void RandPuzzBmp();
	BOOL CheckPuzz();
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
