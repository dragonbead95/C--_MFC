
// Chapter11_MazeEditDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter11_MazeEdit.h"
#include "Chapter11_MazeEditDlg.h"
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


// CChapter11MazeEditDlg 대화 상자



CChapter11MazeEditDlg::CChapter11MazeEditDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER11_MAZEEDIT_DIALOG, pParent)
	, m_strMus(_T(""))
	, m_strBlock(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter11MazeEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_MUS, m_strMus);
	DDX_Text(pDX, IDC_STATIC_BLOCK, m_strBlock);
}

BEGIN_MESSAGE_MAP(CChapter11MazeEditDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILE_LOAD, &CChapter11MazeEditDlg::OnFileLoad)
	ON_COMMAND(ID_FILE_SAVE, &CChapter11MazeEditDlg::OnFileSave)
	ON_COMMAND(ID_FILE_EXIT, &CChapter11MazeEditDlg::OnFileExit)
	ON_BN_CLICKED(IDC_BUTT_REDRAW, &CChapter11MazeEditDlg::OnClickedButtRedraw)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter11MazeEditDlg::OnClickedButtExit)
	ON_BN_CLICKED(IDC_BUTT_END, &CChapter11MazeEditDlg::OnClickedButtEnd)
	ON_BN_CLICKED(IDC_BUTT_BLOCK, &CChapter11MazeEditDlg::OnClickedButtBlock)
	ON_BN_CLICKED(IDC_BUTT_ROAD, &CChapter11MazeEditDlg::OnClickedButtRoad)
	ON_BN_CLICKED(IDC_BUTT_START, &CChapter11MazeEditDlg::OnClickedButtStart)
END_MESSAGE_MAP()


// CChapter11MazeEditDlg 메시지 처리기

BOOL CChapter11MazeEditDlg::OnInitDialog()
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
	m_nBlock = 1;
	m_strBlock = "1: 블럭";
	UpdateData(FALSE);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter11MazeEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter11MazeEditDlg::OnPaint()
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
			DrawBlock(p);
		}
	}
	DrawNum();

}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter11MazeEditDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter11MazeEditDlg::InitMaze()
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


void CChapter11MazeEditDlg::DrawBlock(CPoint pMus)
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	CBrush BlueBrush(RGB(0, 0, 255));
	CBrush *oldBlueBrush = 0;

	CBrush GreenBrush(RGB(0, 255, 0));
	CBrush *oldGreenBrush = 0;

	CBrush BlackBrush(RGB(0, 0, 0));
	CBrush *oldBlackBrush = 0;

	CBrush WhiteBrush(RGB(255, 255, 255));
	CBrush *oldWhiteBrush = 0;

	switch (m_nMaze[pMus.y][pMus.x])
	{
	case 5://시작지점
		oldBlueBrush = dc.SelectObject(&BlueBrush);
		break;
	case 6://끝지점
		oldGreenBrush = dc.SelectObject(&GreenBrush);
		break;
	case 1://블럭
		oldBlackBrush = dc.SelectObject(&BlackBrush);
		break;
	case 0://길
		oldWhiteBrush = dc.SelectObject(&WhiteBrush);
		break;
	}

	dc.Rectangle(10 + (pMus.x * 20), 10 + (pMus.y * 20), 10 + (pMus.x * 20) + 20, 10 + (pMus.y * 20) + 20);

	dc.SelectObject(oldBlueBrush);
	dc.SelectObject(oldGreenBrush);
	dc.SelectObject(oldBlackBrush);
	dc.SelectObject(oldWhiteBrush);
}


void CChapter11MazeEditDlg::DrawNum()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	char szText[2];

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255, 0, 0));
	
	for (int y = 0;y < 20;y++)
	{
		for (int x = 0;x < 20;x++)
		{
			sprintf_s(szText, "%d", m_nMaze[y][x]);
			dc.TextOut(10 + (20 * x) + 6, 10 + (20 * y) + 2, szText);
		}
	}
}


BOOL CChapter11MazeEditDlg::PosToIndex(CPoint pClkMus, CPoint &pMus)
{
	// TODO: 여기에 구현 코드 추가.
	int x, y;
	for (y = 0;y < 20;y++)
	{
		if ((pClkMus.y > 10 + y * 20) && (pClkMus.y <10 + (y + 1) * 20))
			break;
	}

	for (x = 0;x < 20;x++)
	{
		if ((pClkMus.x > 10 + x * 20) && (pClkMus.x < 10 + (x + 1) * 20))
			break;
	}

	if (y == 20 || x == 20)
		return FALSE;
	else {
		pMus.y = y;
		pMus.x = x;
		return TRUE;
	}
	return 0;
}


void CChapter11MazeEditDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CPoint pMus = 0;

	if (PosToIndex(point, pMus))
	{
		m_strMus.Format("[Mus] y:%d, x:%d", pMus.y, pMus.x);
		m_nMaze[pMus.y][pMus.x] = m_nBlock;
		DrawBlock(pMus);
		DrawNum();
	}
	UpdateData(FALSE);

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CChapter11MazeEditDlg::OnFileLoad()
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
		}
		else {
			MessageBox("미로 파일이 아닙니다.", "알림", NULL);
		}
	}
}


void CChapter11MazeEditDlg::OnFileSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFileDialog dlgFileOpen(FALSE, "roa", NULL, OFN_FILEMUSTEXIST, "미로(*.roa)|*.roa||", NULL);

	
	if (dlgFileOpen.DoModal() == IDOK)
	{
		if (dlgFileOpen.GetFileExt() == "roa")
		{
			CFile BoardFile(dlgFileOpen.GetPathName(), CFile::modeCreate|CFile::modeWrite);
			CArchive caBoard(&BoardFile, CArchive::store);

			for (int y = 0;y < 20;y++)
			{
				for (int x = 0;x < 20;x++)
				{
					caBoard << (long)m_nMaze[y][x];
				}
			}

			caBoard.Close();
			BoardFile.Close();

		}
		
	}
}


void CChapter11MazeEditDlg::OnFileExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}


void CChapter11MazeEditDlg::OnClickedButtRedraw()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InitMaze();
	m_nBlock = 1;
	m_strBlock = "1: 블럭";
	UpdateData(FALSE);
	Invalidate();
}


void CChapter11MazeEditDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CChapter11MazeEditDlg::OnClickedButtEnd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nBlock = 6;
	m_strBlock = "6: 끝지점";
	UpdateData(FALSE);
}


void CChapter11MazeEditDlg::OnClickedButtBlock()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nBlock = 1;
	m_strBlock = "1: 블럭";
	UpdateData(FALSE);
}


void CChapter11MazeEditDlg::OnClickedButtRoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nBlock = 0;
	m_strBlock = "0: 길";
	UpdateData(FALSE);
}


void CChapter11MazeEditDlg::OnClickedButtStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nBlock = 5;
	m_strBlock = "5: 시작지점";
	UpdateData(FALSE);
}
