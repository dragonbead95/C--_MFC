
// Chapter06_TimerDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter06_Timer.h"
#include "Chapter06_TimerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChapter06TimerDlg 대화 상자



CChapter06TimerDlg::CChapter06TimerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER06_TIMER_DIALOG, pParent)
	, m_nHour(0)
	, m_nMin(0)
	, m_nSec(0)
	, m_strSetTimer(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter06TimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_HOUR, m_nHour);
	DDX_Text(pDX, IDC_EDIT_MIN, m_nMin);
	DDX_Text(pDX, IDC_EDIT_SEC, m_nSec);
	DDX_Text(pDX, IDC_STATIC_SETTIMER, m_strSetTimer);
}

BEGIN_MESSAGE_MAP(CChapter06TimerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_APPLY, &CChapter06TimerDlg::OnClickedButtApply)
	ON_BN_CLICKED(IDC_BUTT_CANCEL, &CChapter06TimerDlg::OnClickedButtCancel)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter06TimerDlg::OnClickedButtExit)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CChapter06TimerDlg 메시지 처리기

BOOL CChapter06TimerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SetTimer(10, 1000, NULL);

	m_strSetTimer = "현재 시간이 설정되지 않았습니다.";

	GetDlgItem(IDC_BUTT_CANCEL)->EnableWindow(false);
	
	m_bApply = FALSE;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter06TimerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChapter06TimerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter06TimerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter06TimerDlg::OnClickedButtApply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);
	if (m_nHour != 0)
	{
		if (m_nHour > 24 || m_nMin > 59 || m_nSec > 59)
		{
			m_strSetTimer = "시간 설정이 잘못 되었습니다.";
		}
		else {
			m_bApply = TRUE;
			
			GetDlgItem(IDC_BUTT_APPLY)->EnableWindow(false);
			GetDlgItem(IDC_BUTT_CANCEL)->EnableWindow(true);

			GetDlgItem(IDC_EDIT_HOUR)->EnableWindow(false);
			GetDlgItem(IDC_EDIT_MIN)->EnableWindow(false);
			GetDlgItem(IDC_EDIT_SEC)->EnableWindow(false);

			m_strSetTimer.Format("%d시 %d분 %d초에 종료", m_nHour, m_nMin, m_nSec);
		}
	}
	else {
		m_strSetTimer = "시간 설정이 잘못 되었습니다.";
	}
	UpdateData(FALSE);

}


void CChapter06TimerDlg::OnClickedButtCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bApply = FALSE;

	GetDlgItem(IDC_BUTT_APPLY)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTT_CANCEL)->EnableWindow(FALSE);

	GetDlgItem(IDC_EDIT_HOUR)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_MIN)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_SEC)->EnableWindow(true);
}


void CChapter06TimerDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CChapter06TimerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	
	COleDateTime mm;
	mm = COleDateTime::GetCurrentTime();
	CString strTemp;
	strTemp = mm.Format("%H:%M:%S");
	
	GetDlgItem(IDC_STATIC_TIME1)->SetWindowText(strTemp);

	if (m_bApply == TRUE)
	{
		if (m_nHour == mm.GetHour() && m_nMin == mm.GetMinute() && m_nSec == mm.GetSecond())
		{
			m_bApply = FALSE;
			m_strSetTimer = "윈도우즈를 종료합니다.";
			ExitWindows(EWX_SHUTDOWN, 0);

		}
	}
	
	CDialogEx::OnTimer(nIDEvent);
}
