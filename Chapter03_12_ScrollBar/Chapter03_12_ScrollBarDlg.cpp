
// Chapter03_12_ScrollBarDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter03_12_ScrollBar.h"
#include "Chapter03_12_ScrollBarDlg.h"
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


// CChapter0312ScrollBarDlg 대화 상자



CChapter0312ScrollBarDlg::CChapter0312ScrollBarDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER03_12_SCROLLBAR_DIALOG, pParent)
	, m_iEdit(0)
	, m_iEdit2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter0312ScrollBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM, m_iEdit);
	DDX_Text(pDX, IDC_EDIT_NUM2, m_iEdit2);
	DDX_Control(pDX, IDC_SCR_VERT, m_scrVert);
	DDX_Control(pDX, IDC_SCR_HORI, m_scrHori);
}

BEGIN_MESSAGE_MAP(CChapter0312ScrollBarDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter0312ScrollBarDlg::OnClickedButtExit)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CChapter0312ScrollBarDlg 메시지 처리기

BOOL CChapter0312ScrollBarDlg::OnInitDialog()
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
	m_iRed = 0;
	m_iGeen = 0;

	m_scrVert.SetScrollRange(0, 255);
	m_scrVert.SetScrollPos(0);

	m_scrHori.SetScrollRange(0, 255);	// 범위
	m_scrHori.SetScrollPos(0);	//초기위치
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter0312ScrollBarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter0312ScrollBarDlg::OnPaint()
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
	CClientDC dc(this);	//dc를 만든다
	CBrush br;	// 브러시를 만든다
	br.CreateSolidBrush(RGB(m_iRed, m_iGeen, 0));	// 브러시의 색을 지정한다.

	CBrush * Oldbr = dc.SelectObject(&br);	//ㅇ ㅣ러한 색을 사용할 것이라는 것을 지정한다.
	dc.Rectangle(30, 30, 100, 100);	// 사각형을 그린다.
	dc.SelectObject(br);	// 메모리를 반환한다.
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter0312ScrollBarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter0312ScrollBarDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CChapter0312ScrollBarDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	// 스크롤바의 위치값을 에디터상자로 보낸다.
	switch (nSBCode)
	{
	case SB_LINELEFT:
		m_iRed--;
		break;
	case SB_LINERIGHT:
		m_iRed++;
		break;
	case SB_PAGELEFT:
		m_iRed--;
		break;
	case SB_PAGERIGHT:
		m_iRed++;
		break;
	case SB_THUMBPOSITION:
		m_iRed = nPos;
		break;
	}
	m_iEdit = m_scrVert.GetScrollPos();
	m_scrVert.SetScrollPos(m_iRed);	// 스크롤바의 위치를 지정한다.
	Invalidate(FALSE);	// 화면을 갱신하지 않고 WM_PAINT메시지를 호출한다.
	UpdateData(FALSE);
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);

	
}


void CChapter0312ScrollBarDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nSBCode)
	{
	case SB_LINELEFT:
		m_iGeen--;
		break;
	case SB_LINERIGHT:
		m_iGeen++;
		break;
	case SB_PAGELEFT:
		m_iGeen--;
		break;
	case SB_PAGERIGHT:
		m_iGeen++;
		break;
	case SB_THUMBPOSITION:
		m_iGeen = nPos;
		break;
	}
	m_iEdit2 = m_scrHori.GetScrollPos();
	m_scrHori.SetScrollPos(m_iGeen);	// 스크롤바의 위치를 지정한다.
	Invalidate(FALSE);	// 화면을 갱신하지 않고 WM_PAINT메시지를 호출한다.
	UpdateData(FALSE);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
