
// Chapter07_CalenderDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter07_Calender.h"
#include "Chapter07_CalenderDlg.h"
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


// CChapter07CalenderDlg 대화 상자



CChapter07CalenderDlg::CChapter07CalenderDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER07_CALENDER_DIALOG, pParent)

	, m_nYear(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter07CalenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_YEAR, m_nYear);
	//  DDX_CBString(pDX, IDC_COMBO_MONTH, m_ctlMonth);
	DDX_Control(pDX, IDC_COMBO_MONTH, m_ctlMonth);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_nYear);
}

BEGIN_MESSAGE_MAP(CChapter07CalenderDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_VSCROLL()
	ON_CBN_SELCHANGE(IDC_COMBO_MONTH, &CChapter07CalenderDlg::OnSelchangeComboMonth)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter07CalenderDlg::OnClickedButtExit)
END_MESSAGE_MAP()


// CChapter07CalenderDlg 메시지 처리기

BOOL CChapter07CalenderDlg::OnInitDialog()
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
	COleDateTime mm;
	mm = COleDateTime::GetCurrentTime();
	m_nYear = mm.GetYear();

	m_nMonth = mm.GetMonth();
	m_ctlMonth.SetCurSel(m_nMonth - 1);

	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter07CalenderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter07CalenderDlg::OnPaint()
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
	BackGround();
	DatePrint();
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter07CalenderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter07CalenderDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	switch (nSBCode)
	{
	case SB_LINELEFT:
		if (m_nYear < 2099)
		{
			m_nYear++;
		}
		break;
	case SB_LINERIGHT:
		if (m_nYear > 1980)
		{
			m_nYear--;
		}
		break;
	}
	Invalidate(FALSE);
	UpdateData(FALSE);

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CChapter07CalenderDlg::OnSelchangeComboMonth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nMonth = m_ctlMonth.GetCurSel() + 1;
	Invalidate(FALSE);
}


void CChapter07CalenderDlg::BackGround()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	dc.Rectangle(50, 100, 250, 350);
	dc.SetTextColor(RGB(0, 255, 0));
	dc.TextOut(95, 110, "간단한 달력");
	dc.SetTextColor(RGB(0, 0, 0));
	dc.TextOut(65, 140, "일 월 화 수 목 금 토");

}


void CChapter07CalenderDlg::DatePrint()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	COleDateTime mm;
	mm = COleDateTime::GetCurrentTime();
	int w = 0, b = 0, c = 0, t = 0;
	char szText[3] = "";
	t = mm.GetDay();	// 오늘이 무슨 요일인지 알아낸다.


	//해당 일의 요일을 알고 싶으면 우선 이 함수로 년과 월과 일을 입력하고 다음의 함수로 알아내야 한다.
	mm.SetDate(m_nYear, m_nMonth, 1);

	// 현재의 요일을 알아낸다.
	// 1을 기준으로 일요일 ~ 7은 토요일이다.
	w = mm.GetDayOfWeek();

	// 요일을 x,y좌표에 맞추어서 출력할 때는 2중 for문을 사용하는 것이 좋다.
	/* 1일은 처음에 출력 되는 수이다. 그러므로 이 수를 해당 요일에 맞추어서
	 출력해야 다음의 수부터는 해당 요일을 출력하게 된다.
	 w에는 현재의 욜일이 들어있다. 만약 월요일이라고 하면 2라는 수가 들어있고
	 1이라는 숫자는 월요일부터 출력될 것이다.*/
	/*예를들어 4월 1일이 월요일이면 위의 문장의 w에는 2가 들어간다.
	이중 for문 안에서 w안에 있는 2를 b에 넣고 토요일까지 출력하고
	w를 1로 계속 초기화해서 다음주부터는 일요일부터 토요일까지 완전하게 출력한다.*/
	for (int a = 1;a <= 6;a++)
	{
		for (b = w;b <= 7;b++)
		{
			w = 1;
			c = c + 1;
			mm.SetDate(m_nYear, m_nMonth, c);
			if (mm.GetDay() != -1)	// 해당일이 없으면 -1을 리턴
			{
				if (c == t)
					dc.SetTextColor(RGB(0, 0, 255));
				else if (mm.GetDayOfWeek() == 1)
					dc.SetTextColor(RGB(255, 0, 0));
				else
					dc.SetTextColor(RGB(0, 0, 0));

				sprintf_s(szText, "%d", c);
				dc.TextOut((b * 25)+40, 150 + a * 25, szText);
			}
		}
	}
}


void CChapter07CalenderDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
