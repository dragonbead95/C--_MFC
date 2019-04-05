
// Chapter04_14_03_FontDlgDlg.h: 헤더 파일
//

#pragma once


// CChapter041403FontDlgDlg 대화 상자
class CChapter041403FontDlgDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter041403FontDlgDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER04_14_03_FONTDLG_DIALOG };
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
	CString m_strEdit4;
	CString m_strEdit5;
	CString m_strEdit6;
	CString m_strEdit7;
	CString m_strEdit8;
	CString m_strEdit9;
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
};
