
// Chapter09_DiskInfoDlg.h: 헤더 파일
//

#pragma once


// CChapter09DiskInfoDlg 대화 상자
class CChapter09DiskInfoDlg : public CDialogEx
{
// 생성입니다.
public:
	CChapter09DiskInfoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAPTER09_DISKINFO_DIALOG };
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
	CComboBox m_ctlDriver;
//	CString m_strType;
//	CString m_strLabel;
//	CString m_strFat;
	CString m_strSeldrv;
	CString m_strType;
	CString m_strLabel;
	CString m_strFat;
	CString m_strAlldisk;
	CString m_strUsedisk;
	CString m_strFreedisk;
	afx_msg void OnClickedButtExit();
	CString ComMa(CString strNum);
	DWORD m_dDriver;
	void DiskInfo(char* szDrv);
	afx_msg void OnSelchangeComboDriver();
};
