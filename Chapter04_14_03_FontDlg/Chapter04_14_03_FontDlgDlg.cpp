
// Chapter04_14_03_FontDlgDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter04_14_03_FontDlg.h"
#include "Chapter04_14_03_FontDlgDlg.h"
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


// CChapter041403FontDlgDlg 대화 상자



CChapter041403FontDlgDlg::CChapter041403FontDlgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER04_14_03_FONTDLG_DIALOG, pParent)
	, m_strEdit1(_T(""))
	, m_strEdit2(_T(""))
	, m_strEdit3(_T(""))
	, m_strEdit4(_T(""))
	, m_strEdit5(_T(""))
	, m_strEdit6(_T(""))
	, m_strEdit7(_T(""))
	, m_strEdit8(_T(""))
	, m_strEdit9(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter041403FontDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
	DDX_Text(pDX, IDC_EDIT2, m_strEdit2);
	DDX_Text(pDX, IDC_EDIT3, m_strEdit3);
	DDX_Text(pDX, IDC_EDIT4, m_strEdit4);
	DDX_Text(pDX, IDC_EDIT5, m_strEdit5);
	DDX_Text(pDX, IDC_EDIT6, m_strEdit6);
	DDX_Text(pDX, IDC_EDIT7, m_strEdit7);
	DDX_Text(pDX, IDC_EDIT8, m_strEdit8);
	DDX_Text(pDX, IDC_EDIT9, m_strEdit9);
}

BEGIN_MESSAGE_MAP(CChapter041403FontDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CChapter041403FontDlgDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChapter041403FontDlgDlg::OnClickedButton2)
END_MESSAGE_MAP()


// CChapter041403FontDlgDlg 메시지 처리기

BOOL CChapter041403FontDlgDlg::OnInitDialog()
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

void CChapter041403FontDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter041403FontDlgDlg::OnPaint()
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
HCURSOR CChapter041403FontDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter041403FontDlgDlg::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CClientDC dc(this);
	CFontDialog Fontdlg;
	COLORREF color;

	CFont MyFont, *pOldFont;

	if (Fontdlg.DoModal() == IDOK)
	{
		//폰트의 페이스
		m_strEdit1 = Fontdlg.GetFaceName();

		// 폰트의 스타일
		m_strEdit2 = Fontdlg.GetStyleName();

		//폰트의 크기
		m_strEdit3.Format("%d", Fontdlg.GetSize() / 10);

		//색상
		color = Fontdlg.GetColor();

		m_strEdit4.Format("Red: %d, Green: %d, Blue: %d", GetRValue(color), GetGValue(color), GetBValue(color));

		//두께
		m_strEdit5.Format("%d", Fontdlg.GetWeight());

		//취소선
		if (Fontdlg.IsStrikeOut())
			m_strEdit6 = "예";
		else
			m_strEdit6 = "아니오";

		//진하게
		if (Fontdlg.IsBold())
			m_strEdit7 = "예";
		else
			m_strEdit7 = "아니오";

		//이탤릭(기울임꼴)
		if (Fontdlg.IsItalic())
			m_strEdit8 = "예";
		else
			m_strEdit8 = "아니오";

		//밑줄
		if (Fontdlg.IsUnderline())
			m_strEdit9 = "예";
		else
			m_strEdit9 = "아니오";

		//폰트 생성
		MyFont.CreateFont(Fontdlg.GetSize() / 10, 0, 0, 0,
			Fontdlg.GetWeight(),
			Fontdlg.IsItalic(),
			Fontdlg.IsUnderline(),
			Fontdlg.IsStrikeOut(),
			ANSI_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			VARIABLE_PITCH | FF_SWISS,
			Fontdlg.GetFaceName());

		pOldFont = dc.SelectObject(&MyFont);
		dc.SetTextColor(color);
		dc.TextOut(300, 30, "안녕하세요 필자입니다.");
		dc.SelectObject(pOldFont);

		UpdateData(FALSE);
	}
}


void CChapter041403FontDlgDlg::OnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
