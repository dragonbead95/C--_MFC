
// Chapter08_RealMemDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter08_RealMem.h"
#include "Chapter08_RealMemDlg.h"
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


// CChapter08RealMemDlg 대화 상자



CChapter08RealMemDlg::CChapter08RealMemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER08_REALMEM_DIALOG, pParent)
	, m_strEdit1(_T(""))
	, m_strEdit2(_T(""))
	, m_strEdit3(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter08RealMemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
	DDX_Text(pDX, IDC_EDIT2, m_strEdit2);
	DDX_Text(pDX, IDC_EDIT3, m_strEdit3);
}

BEGIN_MESSAGE_MAP(CChapter08RealMemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter08RealMemDlg::OnClickedButtExit)
END_MESSAGE_MAP()


// CChapter08RealMemDlg 메시지 처리기

BOOL CChapter08RealMemDlg::OnInitDialog()
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
	SetTimer(1, 100, NULL);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter08RealMemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter08RealMemDlg::OnPaint()
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
HCURSOR CChapter08RealMemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



CString CChapter08RealMemDlg::ComMa(CString strNum)
{
	// TODO: 여기에 구현 코드 추가.
	CString strTemp;
	int a = 0, k = 0;

	// 수와 영문은 1바이트씩 차지하므로 이 문자열의 길이를 구하면 몇 자리의 숫자인지를 구할 수가 있다.
	a = strNum.GetLength();
	k = a;

	/* 수의 자릿수만큼 for문을 돌려서 거꾸로 되게 만든다.
	예를들어 1234567이라는 숫자가 있는데 처음의 자릿수부터 콤마를 찍으면 123,456,7이 될것이다.
	하지만 콤마는 알다시피 수의 뒷자리부터 다음과 같이 1,234,567로 찍는 것이다. 그래서 우선 입력된 숫자를
	거꾸로 돌린다. 그 다음에 콤마를 찍으면 다음과 같이 765,432,1이 될 것이다. 다시 이 수를 거꾸로 돌리면
	우리는 원하는 결과 값인 1,234,567를 얻을 수 있을 것이다.
	*/
	for (int c = 1;c <= a;c++)
	{
		k--;
		strTemp += strNum.GetAt(k);
	}

	// 콤마를 찍는다.
	int o = 0;
	a = a / 3;
	
	for (int b = 1;b <= a;b++)
	{
		if (b == 1)
		{
			strTemp.Insert(b * 3, ",");
		}
		else {
			o++;
			strTemp.Insert(b * 3 + o, ",");
		}
	}
	/* 처음의 3자리에만 콤마를 찍는다.
	그 이유는 콤마도 문자이므로 공간을 차지하기 때문이다. 그래서 그 다음 수부터는
	콤마도 계산해서 찍어줘야 한다. */

	CString strTemp2;
	int z = 0, u = 0;
	z = strTemp.GetLength();
	u = z;

	for (int y = 1;y <= z;y++)
	{
		u--;
		strTemp2 += strTemp.GetAt(u);
	}
	//↑수를 다시 거꾸로 덜려서 원상 복귀 한다.

	/* 첫번째에 콤마가 있으면 이를 제거한다.
	만약 123456이라는 수가 있다고 치자.
	그러면 이 수를 거꾸로 돌려서 콤마를 찍으면 654,321,가 된다.
	이 수를 보면 알겠지만 맨 뒤에 쓸 대없이 콤마가 찍혀 있는 것을 볼 수 있을 것이다.
	즉, 3자리마다 콤마를 찍기 때문에 어쩔 수 없이 수의 맨뒤에 콤마가 쓸 대 없이 붙는 것이다.
	그러기 때문에 콤마를 제거해주어야 한다. 콤마가 뒤에 붙어 있을때보다 ,123,456과 같이 콤마가
	앞에 붙어있는것이 제거하기 편하다.*/
	if (strTemp2.Find(",", 0) == 0)
	{
		strTemp2.Delete(0, 1);
	}

	return strTemp2;
}


void CChapter08RealMemDlg::MemoryInfo()
{
	// TODO: 여기에 구현 코드 추가.
	MEMORYSTATUS MemInfo;
	MemInfo.dwLength = sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(&MemInfo);

	int nMemoryLoad = 0;
	nMemoryLoad = MemInfo.dwMemoryLoad;
	char szMem[10] = "";

	CClientDC dc(this);

	CPen MyPenBlue(PS_SOLID, 1, RGB(0, 0, 255));
	CBrush MyBrushBlue(RGB(0, 0, 255));

	CPen *pOldPenBlue = dc.SelectObject(&MyPenBlue);
	CBrush *pOldBrushBlue = dc.SelectObject(&MyBrushBlue);
	
	//파란색의 그래프를 출력한다.
	// 이 그래프는 메모리의 남은 용률을 출력하는 것이다.
	dc.Rectangle(nMemoryLoad + 30, 100, 160, 120);
	
	dc.SelectObject(pOldPenBlue);
	dc.SelectObject(pOldBrushBlue);

	CPen MyPenRed(PS_SOLID, 1, RGB(255, 0, 0));
	CBrush MyBrushRed(RGB(255, 0, 0));

	CPen *pOldPenRed = dc.SelectObject(&MyPenRed);
	CBrush *pOldBrushRed = dc.SelectObject(&MyBrushRed);

	// 빨간색의 그래프를 출력한다.
	// 이 그래프는 메모리의 사용률을 출력하는 것이다.
	dc.Rectangle(30, 100, nMemoryLoad + 60, 120);
	
	dc.SelectObject(pOldPenRed);
	dc.SelectObject(pOldBrushRed);

	// 메모리의 사용률을 출력한다.
	sprintf_s(szMem, "%d%%", nMemoryLoad);
	dc.SetTextColor(RGB(255, 255, 255));
	dc.SetBkMode(TRANSPARENT);
	dc.TextOut(70, 100, szMem);
	dc.SetTextColor(RGB(0, 0, 0));
	dc.TextOut(30, 70, "메모리 사용률");
	
	// 전체 메모리 용량을 출력한다.
	CString AllMemory;
	AllMemory.Format("%d", MemInfo.dwTotalPhys);
	m_strEdit1 = ComMa(AllMemory);

	//메모리의 사용량을 출력한다.
	CString UserMemory;
	//전체 메모리에섯 남은 메모리의 용량을 빼주면 지긤 사용하고 있는 메모리의 사용량이 도리것이다.
	UserMemory.Format("%d", MemInfo.dwTotalPhys - MemInfo.dwAvailPhys);
	m_strEdit2 = ComMa(UserMemory);

	//남은 메모리를 출력한다.
	CString FreeMemory;
	FreeMemory.Format("%d", MemInfo.dwAvailPhys);
	m_strEdit3 = ComMa(FreeMemory);

	UpdateData(FALSE);
}


void CChapter08RealMemDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	MemoryInfo();
	CDialogEx::OnTimer(nIDEvent);
}


void CChapter08RealMemDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	KillTimer(1);
}


void CChapter08RealMemDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
