
// Chapter10_PuzzDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter10_Puzz.h"
#include "Chapter10_PuzzDlg.h"
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


// CChapter10PuzzDlg 대화 상자



CChapter10PuzzDlg::CChapter10PuzzDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER10_PUZZ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter10PuzzDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChapter10PuzzDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CChapter10PuzzDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChapter10PuzzDlg::OnClickedButton2)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CChapter10PuzzDlg 메시지 처리기

BOOL CChapter10PuzzDlg::OnInitDialog()
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
	m_bStart = FALSE;	// 변수에 FALSE 값을 주어서 아직 게임이 시작되지 않았음을 알린다.
	InitPuzz();	// 이함수를 호출해서 m_nPuzz 배열을 초기화한다.
	m_bitPuzz.LoadBitmap(IDB_puzz);	// 리소스에서 비트맵을 불러온다.
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter10PuzzDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter10PuzzDlg::OnPaint()
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

	if (m_bStart == FALSE)
		DrawBmp();
	else {
		DrawBack();
		for (int y = 0;y < 3;y++)
		{
			for (int x = 0;x < 3;x++)
			{
				DrawPuzzBmp(y, x, m_nPuzz[y][x]);
			}
		}
		DrawNum();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter10PuzzDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter10PuzzDlg::InitPuzz()
{
	// TODO: 여기에 구현 코드 추가.
	int nCount = 0;

	for (int y = 0;y < 3;y++)
	{
		for (int x = 0;x < 3;x++)
		{
			m_nPuzz[y][x] = nCount++;
		}
	}
	m_nPuzz[2][2] = -1;	//마지막칸은 빈칸이다.
}


void CChapter10PuzzDlg::DrawBmp()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	CDC memDC;

	memDC.CreateCompatibleDC(&dc);
	CBitmap *oldBitPuzz = memDC.SelectObject(&m_bitPuzz);
	//위치를 출력할 위치는 10,10이고 크기는 180,180이다 memDC는 이미지의 핸들이다.
	dc.BitBlt(10, 10, 180, 180, &memDC, 50, 50, SRCCOPY);
	
	memDC.SelectObject(oldBitPuzz);
}

// nRow와 nCol에는 배열의 첨자값이 들어가고 nNum에는 그 첨자 값에 해당하는 배열값이 들어간다.
void CChapter10PuzzDlg::DrawPuzzBmp(int nRow, int nCol, int nNum)
{
	// TODO: 여기에 구현 코드 추가.
	int nSize = 180 / 3;	// 비트맵의 크기는 180이다. 이 그림을 가로,세로 세 등분을 할것이므로 나누기 3을 한다.

	// 배열의 값이 -1이면, 즉 빈칸이면 ZeroRect()함수를 호출해서 빨간색 사각형을 그린다.
	if (nNum == -1)
	{
		ZeroRect(nRow, nCol);
	}

	// 배열의 값을 나누기 3을 해서 나눈 나머지를 메모리에 저장되어 있는 비트맵의 x좌료로 지정한다.
	int nX = int(nNum % 3);
	//배열의 값을 나누기 3을 해서 메모리에 저장되어 있는 비트맵의 y좌표로 지정한다.
	int nY = int(nNum / 3);

	// 메모리에 저장되어 있는 비트맵을 화면에 출력한다.
	CClientDC dc(this);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap *oldBitPuzz = memDC.SelectObject(&m_bitPuzz);

	// 10은 처음에 그림이 출력될 좌표이고, 3은 조각난 그리과 그림사이를 나타낸다.
	dc.BitBlt(10 + (nCol*(nSize + 3)), 10 + (nRow*(nSize + 3)), nSize, nSize, &memDC, (nX*nSize), (nY*nSize), SRCCOPY);

	memDC.SelectObject(oldBitPuzz);
}


void CChapter10PuzzDlg::DrawBack()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);

	//하얀색 사각형을 그린다.
	CPen WhitePen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen *oldWhitePen = dc.SelectObject(&WhitePen);

	CBrush WhiteBrush(RGB(255, 255, 255));
	CBrush *oldWhiteBrush = dc.SelectObject(&WhiteBrush);

	dc.Rectangle(8, 8, 8 + (63 * 3), 8 + (63 * 3));
	
	dc.SelectObject(oldWhitePen);
	dc.SelectObject(oldWhiteBrush);

	//빨간색 선을 가진 사각형을 그린다.
	CPen RedPen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *oldRedPen = dc.SelectObject(&RedPen);

	for (int x = 0;x < 4;x++)
	{
		dc.MoveTo(8, 8 + x * 63);
		dc.LineTo(8 + (63 * 8), 8 + x * 63);
	}

	for (int y = 0;y < 4;y++)
	{
		dc.MoveTo(8+y*63,8);
		dc.LineTo(8+y*63, 8+(63*3));
	}
}


void CChapter10PuzzDlg::DrawNum()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0, 0, 255));
	char szText[2] = "";

	for (int y = 0;y < 3;y++)
	{
		for (int x = 0;x < 3;x++)
		{
			if (m_nPuzz[y][x] != -1)
			{
				sprintf_s(szText, "%d", m_nPuzz[y][x]);
				dc.TextOut(10 + (63 * x), 10 + (63 * y), szText);
			}
		}
	}
}


void CChapter10PuzzDlg::ZeroRect(int nZeroY, int nZeroX)
{
	// TODO: 여기에 구현 코드 추가.
	int nSize = 180 / 3;

	CClientDC dc(this);
	CPen RedPen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *oldRedPen = dc.SelectObject(&RedPen);
	CBrush RedBrush(RGB(255, 0, 0));
	CBrush *oldRedBrush = dc.SelectObject(&RedBrush);

	dc.Rectangle(10 + (nZeroX*(nSize + 3)),
		10 + (nZeroY*(nSize + 3)),
			10 + (nZeroX*(nSize + 3)) + 60,
			10 + (nZeroY*(nSize + 3)) + 60);
	
	dc.SelectObject(oldRedPen);
	dc.SelectObject(oldRedBrush);

}


BOOL CChapter10PuzzDlg::ZeroPosition(int nMusY, int nMusX, int &nZeroY, int &nZeroX)
{
	// TODO: 여기에 구현 코드 추가.
	int i = 0;
	for (i = 0;i < 3;i++)
	{
		if (m_nPuzz[i][nMusX] == -1)
		{
			nZeroY = i;
			nZeroX = nMusX;
			return TRUE;
		}
	}

	for (i = 0;i < 3;i++)
	{
		if (m_nPuzz[nMusY][i] == -1)
		{
			nZeroY = nMusY;
			nZeroX = i;
			return TRUE;
		}
	}
	return FALSE;
}

/* nMusY와 nMusX는 마우스가 클릭된 곳의 값이고, nZeroY와 nZeroX는 -1이 있는곳의 값이다.*/
void CChapter10PuzzDlg::MovePuzzBmp(int nMusY, int nMusX, int nZeroY, int nZeroX)
{
	// TODO: 여기에 구현 코드 추가.
	int nY = nMusY - nZeroY;	/*조각난 그림을 아래에서 위로 또는 위에서 아래로 옮길때에는 
								마우스가 클릭된 곳의 Y값에서 -1이 있는곳의 Y값을 빼주면 된다.*/
	int nX = nMusX - nZeroX;	/*조각난 그림을 아래에서 왼쪽에서 오른쪽으로, 오른쪽에서 왼쪽으로
								옮길 때는 마우스가 클릭된 곳의 X값에서 -1이 있는 곳의 X값을 빼주면 된다.*/

	int a = 0;

	/* 0을 기준으로 nY값이 0보다 크면*/
	if (nY > 0)
	{
		/* 조각난 그림을 아래서 위로 올린다.*/
		for (a = nZeroY;a < nMusY;a++)
		{
			m_nPuzz[a][nMusX] = m_nPuzz[a + 1][nMusX];
			DrawPuzzBmp(a, nMusX, m_nPuzz[a + 1][nMusX]);
		}
	}
	
	/*0을 기준으로 0보다 작으면*/
	if (nY < 0)
	{
		/* 조각난 그림을 위에서 아래로 옮긴다.*/
		for (a = nZeroY;a > nMusY;a--)
		{
			m_nPuzz[a][nMusX] = m_nPuzz[a - 1][nMusX];
			DrawPuzzBmp(a, nMusX, m_nPuzz[a - 1][nMusX]);
		}
	}

	/* 0을 기준으로 nX값이 0보다 크면*/
	if (nX > 0)
	{
		/* 조각난 그림을 오른쪽에서 왼쪽으로 옮긴다.*/
		for (a = nZeroX; a < nMusX;a++)
		{
			m_nPuzz[nMusY][a] = m_nPuzz[nMusY][a + 1];
			DrawPuzzBmp(nMusY, a, m_nPuzz[nMusY][a + 1]);
		}
	}

	/* 0을 기준으로 nX값이 0보다 작으면 조각난 그림을 왼쪽에서 오른쪽으로 옮긴다.*/
	if (nX < 0)
	{
		for (a = nZeroX;a > nMusX;a--)
		{
			m_nPuzz[nMusY][a] = m_nPuzz[nMusY][a - 1];
			DrawPuzzBmp(nMusY, a, m_nPuzz[nMusY][a - 1]);
		}
	}

	// 마우스가 클릭 되었떤 조각그림이 있는곳에 -1을 대입한다.
	m_nPuzz[nMusY][nMusX] = -1;
	ZeroRect(nMusY, nMusX);	// -1이 있는 곳에 빨간색 사각형을 그린다.
}


BOOL CChapter10PuzzDlg::PosToIndex(CPoint pos, int &nY, int &nX)
{
	// TODO: 여기에 구현 코드 추가.
	int x, y;
	
	// y좌표 값을 검사한다.
	for (y = 0;y < 3;y++)
	{
		if ((pos.y > 10 + y * 63) && (pos.y < 10 + (y + 1) * 63 - 3))
			break;
	}

	// x좌표 값을 검사한다.
	for (x = 0;x < 3;x++)
	{
		if ((pos.x > 10 + x * 63) && (pos.x < 10 + (x + 1) * 63 - 3))
			break;
	}

	//만약 조각난 그림의 바같을 클릭하였다면
	if (y == 3 || x == 3)
		return FALSE;
	else {	/*조각난 버튼을 클릭하면 마우스의 버튼이 클릭된 좌표 값에 해당하는
			배열의 첨자 값을 nY,nX변수에 저장하고 TRUE값을 리턴한다.*/
		nY = y;
		nX = x;
		return TRUE;
	}
	return 0;
}


void CChapter10PuzzDlg::RandPuzzBmp()
{
	// TODO: 여기에 구현 코드 추가.
	srand((unsigned)time(NULL));	// rand()함수를 초기화한다.

	int nRandY, nRandX;
	int nY, nX;

	BOOL bBool = FALSE;

	for (int i = 0;i < 500;i++)
	{
		nRandY = rand() % 3;
		nRandX = rand() % 3;

		bBool = ZeroPosition(nRandY, nRandX, nY, nX);	// ZeroPosition() 함수가 -1이 있는 곳을 찾으면

		if (bBool)
		{
			MovePuzzBmp(nRandY, nRandX, nY, nX);	// 조각난 그림을 옮긴다.
			DrawNum();	// 수를 출력한다.
		}
	}
}


BOOL CChapter10PuzzDlg::CheckPuzz()
{
	// TODO: 여기에 구현 코드 추가.
	for (int y = 0;y < 3;y++)
	{
		for (int x = 0;x < 3;x++)
		{
			if (y == 2 && x == 2)
			{
				//배열의 맨 마지막 첨자 값에 해당하면
				if (m_nPuzz[y][x] != -1)	// 그 첨자 값에 있는 배열의 값이 -1이 아니면
					return FALSE;	// FALSE 리턴
			}
			else {
				if (m_nPuzz[y][x] != y * 3 + x)	// 배열의 값과 Y*3+X 한 값을 비교해서 다르면 FALSE 리턴
					return FALSE;
			}
		}
	}
	return TRUE;	// TRUE는 조각난 그림을 다 맞추었다는 것이다.
}


void CChapter10PuzzDlg::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bStart = TRUE;	// TRUE값을주어 게임이 시작되었음을 알림
	DrawBack();	// 배경을 그린다.
	RandPuzzBmp();	// 마구잡이로 섞인 조각난 그림을 출력한다.
	
}


void CChapter10PuzzDlg::OnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CChapter10PuzzDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nMusY = 0, nMusX = 0;
	int nZeroY = 0, nZeroX = 0;
	if (m_bStart == TRUE)
	{
		if (PosToIndex(point, nMusY, nMusX))
		{
			if (ZeroPosition(nMusY, nMusX, nZeroY, nZeroX))
			{
				MovePuzzBmp(nMusY, nMusX, nZeroY, nZeroX);
				DrawNum();
				if (CheckPuzz())
				{
					MessageBox("게임 성공!", "알림", NULL);
					m_bStart = FALSE;
					Invalidate();
				}
			}
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
