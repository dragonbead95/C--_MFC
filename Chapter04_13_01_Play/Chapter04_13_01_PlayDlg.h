
// Chapter04_13_01_PlayDlg.h: 헤더 파일
//

#pragma once


// CChapter041301PlayDlg 대화 상자
class CChapter041301PlayDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter041301PlayDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER04_13_01_PLAY_DIALOG };
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
	afx_msg void OnClickedButtExit();
	afx_msg void OnClickedButtFirst();
	afx_msg void OnClickedButtOpen();
	afx_msg void OnClickedButtPause();
	afx_msg void OnClickedButtPlay();
	afx_msg void OnClickedButtResume();
	afx_msg void OnClickedButtStop();
	DWORD m_dwID;
	afx_msg void OnDestroy();
};
