
// Chapter03_06_ListBoxDlg.h: 헤더 파일
//

#pragma once


// CChapter0306ListBoxDlg 대화 상자
class CChapter0306ListBoxDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter0306ListBoxDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER03_06_LISTBOX_DIALOG };
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
	CListBox m_cListBox;
	CString m_strInput;
	afx_msg void OnClickedButtAdd();
	afx_msg void OnClickedButtDelete();
	afx_msg void OnClickedButtExit();
};
