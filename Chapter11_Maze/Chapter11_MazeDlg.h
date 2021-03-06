
// Chapter11_MazeDlg.h: 헤더 파일
//

#pragma once


// CChapter11MazeDlg 대화 상자
class CChapter11MazeDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter11MazeDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER11_MAZE_DIALOG };
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
	CString m_strLeft;
	CString m_strUp;
	CString m_strRight;
	CString m_strDown;
	CString m_strFrag;
	int m_nMaze[20][20];
	void InitMaze();
	void DrawBack(CPoint pMus);
	BOOL StartPoint(CPoint &p);
	void DrawChar(int nMovY, int nMovX, CPoint p);
	void CleanChar(int nMovY, int nMovX, CPoint p);
	BOOL CharPostion(CPoint &p);
	void RoadPostion(CPoint p, int &nLeft, int &nUp, int &nRight, int &nDown);
	void MoveChar();
	void Ai(int &a);
	afx_msg void OnFileLoad();
	afx_msg void OnFileExit();
	CPoint m_pStart;
	afx_msg void OnClickedButtRestart();
	afx_msg void OnClickedButtStart();
	afx_msg void OnClickedButtExit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
