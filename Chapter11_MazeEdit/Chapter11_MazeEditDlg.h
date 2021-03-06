
// Chapter11_MazeEditDlg.h: 헤더 파일
//

#pragma once


// CChapter11MazeEditDlg 대화 상자
class CChapter11MazeEditDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter11MazeEditDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER11_MAZEEDIT_DIALOG };
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
	CString m_strMus;
	CString m_strBlock;
	int m_nMaze[20][20];
	void InitMaze();
	void DrawBlock(CPoint pMus);
	void DrawNum();
	BOOL PosToIndex(CPoint pClkMus, CPoint &pMus);
	int m_nBlock;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileLoad();
	afx_msg void OnFileSave();
	afx_msg void OnFileExit();
	afx_msg void OnClickedButtRedraw();
	afx_msg void OnClickedButtExit();
	afx_msg void OnClickedButtEnd();
	afx_msg void OnClickedButtBlock();
	afx_msg void OnClickedButtRoad();
	afx_msg void OnClickedButtStart();
};
