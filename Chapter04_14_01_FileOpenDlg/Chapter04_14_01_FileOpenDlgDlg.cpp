
// Chapter04_14_01_FileOpenDlgDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter04_14_01_FileOpenDlg.h"
#include "Chapter04_14_01_FileOpenDlgDlg.h"
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


// CChapter041401FileOpenDlgDlg 대화 상자



CChapter041401FileOpenDlgDlg::CChapter041401FileOpenDlgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER04_14_01_FILEOPENDLG_DIALOG, pParent)
	, m_strEdit1(_T(""))
	, m_strEdit2(_T(""))
	, m_strEdit4(_T(""))
	, m_strEdit3(_T(""))
	, m_strEdit5(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter041401FileOpenDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
	DDX_Text(pDX, IDC_EDIT2, m_strEdit2);
	DDX_Text(pDX, IDC_EDIT4, m_strEdit4);
	DDX_Text(pDX, IDC_EDIT3, m_strEdit3);
	DDX_Text(pDX, IDC_EDIT5, m_strEdit5);
}

BEGIN_MESSAGE_MAP(CChapter041401FileOpenDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_OPEN, &CChapter041401FileOpenDlgDlg::OnClickedButtOpen)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter041401FileOpenDlgDlg::OnClickedButtExit)
END_MESSAGE_MAP()


// CChapter041401FileOpenDlgDlg 메시지 처리기

BOOL CChapter041401FileOpenDlgDlg::OnInitDialog()
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

void CChapter041401FileOpenDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter041401FileOpenDlgDlg::OnPaint()
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
HCURSOR CChapter041401FileOpenDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter041401FileOpenDlgDlg::OnClickedButtOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL bTrue = FALSE;

	CFileDialog dlgFileOpen(TRUE, "TXT", NULL, OFN_FILEMUSTEXIST, "메모장(*.txt) | *.txt | 모든파일(*.*) | *.*||", NULL);
	
	if (dlgFileOpen.DoModal() == IDOK)
	{
		m_strEdit1 = dlgFileOpen.GetPathName();
		m_strEdit2 = dlgFileOpen.GetFileName();
		m_strEdit3 = dlgFileOpen.GetFileTitle();
		m_strEdit4 = dlgFileOpen.GetFileExt();

		bTrue = dlgFileOpen.GetReadOnlyPref();
		if (bTrue == TRUE)
		{
			m_strEdit5 = "읽기 전용 파일입니다.";
		}
		else
		{
			m_strEdit5 = "읽기 전용 파일이 아닙니다.";
		}
		UpdateData(FALSE);
	}
	else {
		MessageBox("선택을 잘못했습니다.", "알림", NULL);
	}
}


void CChapter041401FileOpenDlgDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
