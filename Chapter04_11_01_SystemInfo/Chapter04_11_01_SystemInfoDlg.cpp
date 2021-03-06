
// Chapter04_11_01_SystemInfoDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter04_11_01_SystemInfo.h"
#include "Chapter04_11_01_SystemInfoDlg.h"
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


// CChapter041101SystemInfoDlg 대화 상자



CChapter041101SystemInfoDlg::CChapter041101SystemInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER04_11_01_SYSTEMINFO_DIALOG, pParent)
	, m_strMusButt(_T(""))
	, m_strBooting(_T(""))
	, m_strVga(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter041101SystemInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MUSBUIT, m_strMusButt);
	DDX_Text(pDX, IDC_EDIT_BOOTING, m_strBooting);
	DDX_Text(pDX, IDC_EDIT_VGA, m_strVga);
}

BEGIN_MESSAGE_MAP(CChapter041101SystemInfoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_PRINT, &CChapter041101SystemInfoDlg::OnClickedButtPrint)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter041101SystemInfoDlg::OnClickedButtExit)
END_MESSAGE_MAP()


// CChapter041101SystemInfoDlg 메시지 처리기

BOOL CChapter041101SystemInfoDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter041101SystemInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter041101SystemInfoDlg::OnPaint()
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
HCURSOR CChapter041101SystemInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter041101SystemInfoDlg::OnClickedButtPrint()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nMusButt = 0;	// 마우스 버튼의 수
	nMusButt = GetSystemMetrics(SM_CMOUSEBUTTONS);
	if (nMusButt > 0)
		m_strMusButt.Format("%d개", nMusButt);
	else
		m_strMusButt = "마우스가 설치되어 있지 않음";

	//부팅상태
	int nBoot = 0;
	nBoot = GetSystemMetrics(SM_CLEANBOOT);
	switch (nBoot)
	{
	case 0:
		m_strBooting = "정상부팅";
		break;
	case 1:
		m_strBooting = "안전모드 부팅";
		break;
	case 2:
		m_strBooting = "네트워크 부팅";
		break;
	}

	//해상도
	m_strVga.Format("%d * %d", GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

	UpdateData(FALSE);
		
}


void CChapter041101SystemInfoDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
