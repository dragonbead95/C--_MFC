
// Chapter11_MazeDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter11_Maze.h"
#include "Chapter11_MazeDlg.h"
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


// CChapter11MazeDlg 대화 상자



CChapter11MazeDlg::CChapter11MazeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER11_MAZE_DIALOG, pParent)
	, m_strLeft(_T(""))
	, m_strUp(_T(""))
	, m_strRight(_T(""))
	, m_strDown(_T(""))
	, m_strFrag(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter11MazeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_LEFT, m_strLeft);
	DDX_Text(pDX, IDC_STATIC_UP, m_strUp);
	DDX_Text(pDX, IDC_STATIC_RIGHT, m_strRight);
	DDX_Text(pDX, IDC_STATIC_DOWN, m_strDown);
	DDX_Text(pDX, IDC_STATIC_FRAG, m_strFrag);
}

BEGIN_MESSAGE_MAP(CChapter11MazeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_LOAD, &CChapter11MazeDlg::OnFileLoad)
	ON_COMMAND(ID_FILE_EXIT, &CChapter11MazeDlg::OnFileExit)
	ON_BN_CLICKED(IDC_BUTT_RESTART, &CChapter11MazeDlg::OnClickedButtRestart)
	ON_BN_CLICKED(IDC_BUTT_START, &CChapter11MazeDlg::OnClickedButtStart)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter11MazeDlg::OnClickedButtExit)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CChapter11MazeDlg 메시지 처리기

BOOL CChapter11MazeDlg::OnInitDialog()
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
	InitMaze();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter11MazeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter11MazeDlg::OnPaint()
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
	CPoint p = 0;

	for (int y = 0;y < 20;y++)
	{
		for (int x = 0;x < 20;x++)
		{
			p.y = y;
			p.x = x;
			DrawBack(p);
		}
	}

}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter11MazeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter11MazeDlg::InitMaze()
{
	// TODO: 여기에 구현 코드 추가.
	for (int y = 0;y < 20;y++)
	{
		for (int x = 0;x < 20;x++)
		{
			m_nMaze[y][x] = 0;
		}
	}
}


void CChapter11MazeDlg::DrawBack(CPoint pMus)
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	CBrush BlueBrush(RGB(0, 0, 255));
	CBrush *oldBlueBrush = 0;
	CPen BluePen(PS_SOLID, 1, RGB(0, 0, 255));
	CPen *oldBluePen = 0;

	CBrush GreenBrush(RGB(0, 255, 0));
	CBrush *oldGreenBrush = 0;
	CPen GreenPen(PS_SOLID, 1, RGB(0, 255, 0));
	CPen *oldGreenPen = 0;

	CBrush BlackBrush(RGB(0, 0, 0));
	CBrush *oldBlackBrush = 0;
	CPen BlackPen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *oldBlackPen = 0;

	CBrush WhiteBrush(RGB(255, 255, 255));
	CBrush *oldWhiteBrush = 0;
	CPen WhitePen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen *oldWhitePen = 0;

	switch (m_nMaze[pMus.y][pMus.x])
	{
	case 5://시작지점
		oldBlueBrush = dc.SelectObject(&BlueBrush);
		oldBluePen = dc.SelectObject(&BluePen);
		break;
	case 6://끝지점
		oldGreenBrush = dc.SelectObject(&GreenBrush);
		oldGreenPen = dc.SelectObject(&GreenPen);
		break;
	case 1://블럭
		oldBlackBrush = dc.SelectObject(&BlackBrush);
		oldBlackPen = dc.SelectObject(&BlackPen);
		break;
	case 0://길
		oldWhiteBrush = dc.SelectObject(&WhiteBrush);
		oldWhitePen = dc.SelectObject(&WhitePen);
		break;
	}

	dc.Rectangle(10 + (pMus.x * 20), 10 + (pMus.y * 20), 10 + (pMus.x * 20) + 20, 10 + (pMus.y * 20) + 20);

	dc.SelectObject(oldBluePen);
	dc.SelectObject(oldGreenPen);
	dc.SelectObject(oldBlackPen);
	dc.SelectObject(oldWhitePen);

	dc.SelectObject(oldBlueBrush);
	dc.SelectObject(oldGreenBrush);
	dc.SelectObject(oldBlackBrush);
	dc.SelectObject(oldWhiteBrush);
}


BOOL CChapter11MazeDlg::StartPoint(CPoint &p)
{
	// TODO: 여기에 구현 코드 추가.

	for (int y = 0;y < 20;y++)
	{
		for (int x = 0;x < 20;x++)
		{
			if (m_nMaze[y][x] == 5)
			{
				p.y = y;
				p.x = x;
				return TRUE;
			}
		}
	}
	return FALSE;
}


void CChapter11MazeDlg::DrawChar(int nMovY, int nMovX, CPoint p)
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	CPen RedPen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *oldRedPen = dc.SelectObject(&RedPen);

	CBrush RedBrush(RGB(255, 0, 0));
	CBrush *oldRedBrush = dc.SelectObject(&RedBrush);
	
	dc.Ellipse(15 + (p.x * 20) + nMovX,
		15 + (p.y * 20) + nMovY,
		15 + (p.x * 20) + 10 + nMovX,
		15 + (p.y * 20) + 10 + nMovY);

	dc.SelectObject(oldRedPen);
	dc.SelectObject(oldRedBrush);
}


void CChapter11MazeDlg::CleanChar(int nMovY, int nMovX, CPoint p)
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	
	CBrush WhiteBrush(RGB(255, 255, 255));
	CBrush *oldWhiteBrush = dc.SelectObject(&WhiteBrush);
	CPen WhitePen(PS_SOLID, 1, RGB(255, 255, 255));
	CPen *oldWhitePen = dc.SelectObject(&WhitePen);

	dc.Rectangle(10 + (p.x * 20) + nMovX,
		10 + (p.y * 20) + nMovY,
		10 + (p.x * 20) + 20 + nMovX,
		10 + (p.y * 20) + 20 + nMovY);

	dc.SelectObject(oldWhiteBrush);
	dc.SelectObject(oldWhitePen);
}


BOOL CChapter11MazeDlg::CharPostion(CPoint &p)
{
	// TODO: 여기에 구현 코드 추가.

	for (int y = 0;y < 20;y++)
	{
		for (int x = 0;x < 20;x++)
		{
			if (m_nMaze[y][x] == -1)
			{
				p.y = y;
				p.x = x;
				return TRUE;
			}
		}
	}
	return FALSE;
}


void CChapter11MazeDlg::RoadPostion(CPoint p, int &nLeft, int &nUp, int &nRight, int &nDown)
{
	// TODO: 여기에 구현 코드 추가.
	//왼쪽
	if (m_nMaze[p.y][p.x - 1] == 0)
		nLeft = 1;
	else
		nLeft = 0;

	//위쪽
	if (m_nMaze[p.y - 1][p.x] == 0)
		nUp = 2;
	else
		nUp = 0;

	//오른쪽
	if (m_nMaze[p.y][p.x + 1] == 0)
		nRight = 3;
	else
		nRight = 0;

	//아래쪽
	if (m_nMaze[p.y + 1][p.x] == 0)
		nDown = 4;
	else
		nDown = 0;
}


void CChapter11MazeDlg::MoveChar()
{
	// TODO: 여기에 구현 코드 추가.
	//방향
	static int a = 1;
	CPoint p = 0;
	static int c = 0;

	//캐릭터의 위치 찾기
	CharPostion(p);

	switch (a)
	{
	case 1: //왼쪽에 벽이 없다면
		if (m_nMaze[p.y][p.x - 1] != 1)
		{
			// 끝지점인지 체크
			if (m_nMaze[p.y][p.x - 1] == 6)
			{
				c--;
				CleanChar(0, c, p);
				DrawChar(0, c, p);

				if (c == -20)
				{
					m_strFrag = "끝";
					KillTimer(1);
				}
			}
			else //끝지점이 아니라면 왼쪽으로 이동
			{
				m_strFrag = "왼쪽";
				c--;
				CleanChar(0, c, p);
				DrawChar(0, c, p);

				if (c == -20)
				{
					m_nMaze[p.y][p.x] = 0;
					m_nMaze[p.y][p.x - 1] = -1;

					c = 0;
				}
			}
		}
		else {//벽이라면
			Ai(a);
		}
		break;
	case 2:	// 위쪽에 벽이 없다면
		if (m_nMaze[p.y - 1][p.x] != 1)
		{
			//끝지점인지 체크
			if (m_nMaze[p.y - 1][p.x] == 6)
			{
				c--;
				CleanChar(c, 0, p);
				DrawChar(c, 0, p);

				if (c == -20)
				{
					m_strFrag == "끝";
					KillTimer(1);
				}
			}
			else {	//끝지점이 아니라면 위쪽으로 이동
				m_strFrag = "위쪽";
				c--;
				CleanChar(c, 0, p);
				DrawChar(c, 0, p);

				if (c == -20)
				{
					m_nMaze[p.y][p.x] = 0;
					m_nMaze[p.y - 1][p.x] = -1;
					c = 0;
				}

			}
		}
		else {
			Ai(a);
		}
		break;
	case 3:// 오른쪽에 벽이 없다면
		if (m_nMaze[p.y][p.x+1] != 1)
		{
			//끝지점인지 체크
			if (m_nMaze[p.y][p.x+1] == 6)
			{
				c++;
				CleanChar(0,c, p);
				DrawChar(0, c, p);

				if (c == 20)
				{
					m_strFrag == "끝";
					KillTimer(1);
				}
			}
			else {	//끝지점이 아니라면 위쪽으로 이동
				m_strFrag = "오른쪽";
				c++;
				CleanChar(0, c, p);
				DrawChar(0, c, p);

				if (c == 20)
				{
					m_nMaze[p.y][p.x] = 0;
					m_nMaze[p.y][p.x+1] = -1;
					c = 0;
				}

			}
		}
		else {
			Ai(a);
		}
		break;
	case 4:// 아래쪽에 벽이 없다면
		if (m_nMaze[p.y + 1][p.x] != 1)
		{
			//끝지점인지 체크
			if (m_nMaze[p.y + 1][p.x] == 6)
			{
				c++;
				CleanChar(c, 0, p);
				DrawChar(c, 0, p);

				if (c == 20)
				{
					m_strFrag == "끝";
					KillTimer(1);
				}
			}
			else {	//끝지점이 아니라면 위쪽으로 이동
				m_strFrag = "위쪽";
				c++;
				CleanChar(c, 0, p);
				DrawChar(c, 0, p);

				if (c == 20)
				{
					m_nMaze[p.y][p.x] = 0;
					m_nMaze[p.y + 1][p.x] = -1;
					c = 0;
				}

			}
		}
		else {
			Ai(a);
		}
		break;
	}
	UpdateData(FALSE);
}


void CChapter11MazeDlg::Ai(int &a)
{
	// TODO: 여기에 구현 코드 추가.
	CPoint pChar = 0;
	int nLeft = 0, nUp = 0, nRight = 0, nDown = 0;

	if (CharPostion(pChar))
	{
		// 어느 쪽에 길이 있는지를 찾는다.
		RoadPostion(pChar, nLeft, nUp, nRight, nDown);
		m_strLeft.Format("Left: %d", nLeft);
		m_strUp.Format("Up: %d", nUp);
		m_strRight.Format("Right: %d", nRight);
		m_strDown.Format("Down: %d", nDown);

		UpdateData(FALSE);

		//왼쪽에 길이 있으면
		if ((nLeft) && (nUp == 0) && (nRight == 0) && (nDown == 0))
			a = 1;

		//위쪽에 길이 있으면
		if ((nLeft == 0) && (nUp) && (nRight == 0) && (nDown == 0))
			a = 2;

		//오른쪽에 길이 있으면
		if ((nLeft == 0) && (nUp == 0) && (nRight) && (nDown == 0))
			a = 3;

		//아래쪽에 길이 있으면
		if ((nLeft == 0) && (nUp == 0) && (nRight == 0) && (nDown))
			a = 4;

		//왼쪽과 아래쪽에 길이있으면
		if ((nLeft) && (nUp == 0) && (nRight == 0) && (nDown))
		{
			//캐릭터의 현재 방향이 위쪽이라면..
			if (a == 2)
				a = 1;

			//캐릭터의 현재 방향이 오른쪽이라면..
			if (a == 3)
				a = 4;
		}

		// 윈쪽과 위쪽에 길이 있으면
		if ((nLeft) && (nUp) && (nRight == 0) && (nDown==0))
		{
			if (a == 4)
				a = 1;
			if (a == 3)
				a = 2;
		}

		// 오른쪽과 아래쪽에 길이 있으면
		if ((nLeft==0) && (nUp==0) && (nRight) && (nDown))
		{
			if (a == 0)
				a = 3;
			if (a == 1)
				a = 4;
			if (a == 2)
				a = 3;
		}

		// 오른쪽과 위쪽에 길이 있으면
		if ((nLeft==0) && (nUp) && (nRight) && (nDown==0))
		{
			if (a == 4)
				a = 3;
			if (a == 1)
				a = 2;
		}

		// 윈쪽과 오른쪽과 위쪽에 길이 있으면
		if ((nLeft) && (nUp) && (nRight) && (nDown == 0))
		{
			a = 3;
		}

		// 윈쪽과 위쪽과 아래쪽에 길이 있으면
		if ((nLeft) && (nUp) && (nRight == 0) && (nDown))
		{
			a = 4;
		}

		// 윈쪽과 오른쪽과 아래쪽에 길이 있으면
		if ((nLeft) && (nUp==0) && (nRight) && (nDown))
		{
			a = 3;
		}
	}
}


void CChapter11MazeDlg::OnFileLoad()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFileDialog dlgFileOpen(TRUE, "roa", NULL, OFN_FILEMUSTEXIST, "미로(*.roa)|*.roa||", NULL);
	
	long IBoard = 0;
	if (dlgFileOpen.DoModal() == IDOK)
	{
		if (dlgFileOpen.GetFileExt() == "roa")
		{
			CFile BoardFile(dlgFileOpen.GetPathName(), CFile::modeRead);

			CArchive caBoard(&BoardFile, CArchive::load);
			for (int y = 0;y < 20;y++)
			{
				for (int x = 0;x < 20;x++)
				{
					caBoard >> IBoard;
					m_nMaze[y][x] = IBoard;
				}
			}
			caBoard.Close();
			BoardFile.Close();

			Invalidate();

			m_strLeft = "";
			m_strUp = "";
			m_strRight = "";
			m_strDown = "";
			UpdateData(FALSE);
		}
		else {
			MessageBox("미로 파일이 아닙니다.", "알림", NULL);
		}
	}
}


void CChapter11MazeDlg::OnFileExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}


void CChapter11MazeDlg::OnClickedButtRestart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CPoint p = 0;
	KillTimer(1);

	//시작지점
	m_nMaze[m_pStart.y][m_pStart.x] = 5;

	//캐릭터가 있던 지점을 길로 바꾼다.
	if (CharPostion(p))
		m_nMaze[p.y][p.x] = 0;

	m_strLeft = "";
	m_strUp = "";
	m_strRight = "";
	m_strDown = "";
	UpdateData(FALSE);

	Invalidate();
}


void CChapter11MazeDlg::OnClickedButtStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//시작지점 찾기
	CPoint pStart = 0;

	if (StartPoint(pStart))
	{
		//시작지점에 캐릭터를 놓는다.
		m_pStart = pStart;
		m_nMaze[pStart.y][pStart.x] = -1;

		CleanChar(0, 0, pStart);
		DrawChar(0, 0, pStart);

		SetTimer(1, 1, NULL);
		UpdateData(FALSE);
	}
}


void CChapter11MazeDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CChapter11MazeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	MoveChar();
	CDialogEx::OnTimer(nIDEvent);
}
