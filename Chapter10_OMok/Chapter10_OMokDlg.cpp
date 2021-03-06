
// Chapter10_OMokDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter10_OMok.h"
#include "Chapter10_OMokDlg.h"
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


// CChapter10OMokDlg 대화 상자



CChapter10OMokDlg::CChapter10OMokDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER10_OMOK_DIALOG, pParent)
	, m_strColAl(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter10OMokDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_COLAL, m_strColAl);
}

BEGIN_MESSAGE_MAP(CChapter10OMokDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_OPEN, &CChapter10OMokDlg::OnFileOpen)
	ON_BN_CLICKED(IDC_BUTT_START, &CChapter10OMokDlg::OnClickedButtStart)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTT_RESTART, &CChapter10OMokDlg::OnClickedButtRestart)
	ON_COMMAND(ID_FILE_SAVE, &CChapter10OMokDlg::OnFileSave)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter10OMokDlg::OnClickedButtExit)
END_MESSAGE_MAP()


// CChapter10OMokDlg 메시지 처리기

BOOL CChapter10OMokDlg::OnInitDialog()
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
	m_bStart = FALSE;
	InitBoard();
	m_bTurn = FALSE;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter10OMokDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChapter10OMokDlg::OnPaint()
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

	if (m_bStart == TRUE)
	{
		DrawBack();
		DrawAI();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter10OMokDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter10OMokDlg::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	/*CFileDialog(TRUE(읽기)/FALSE(저장),기본확장자,기본파일명,열기모드,파일창 아래쪽에 나오는 필터링))*/
	CFileDialog dlgFileOpen(TRUE, "bor", NULL, OFN_FILEMUSTEXIST, "바둑판(*.bor)|*.bor||", NULL);
	
	long IBoard = 0;
	if (dlgFileOpen.DoModal() == IDOK)
	{
		if (dlgFileOpen.GetFileExt() == "bor")
		{
			CFile BoardFile(dlgFileOpen.GetPathName(), CFile::modeRead);

			CArchive caBoard(&BoardFile, CArchive::load);

			for (int y = 0;y < 10;y++)
			{
				for (int x = 0;x < 10;x++)
				{
					caBoard >> IBoard;
					m_nBoard[y][x] = IBoard;
				}
			}

			caBoard >> m_bTurn;

			caBoard.Close();
			BoardFile.Close();

			if (m_bStart == FALSE)
				m_bStart = TRUE;

			if (m_bTurn == FALSE)
			{
				m_strColAl = "검정색 알";
			}
			else if (m_bTurn == TRUE)
			{
				m_strColAl = "흰색 알";
			}

			Invalidate(TRUE);
			UpdateData(FALSE);
		}
		else {
			MessageBox("바둑판 파일이 아닙니다.", "알림", NULL);
		}
	}
}


void CChapter10OMokDlg::DrawBack()
{
	// TODO: 여기에 구현 코드 추가.
	int x = 0, y = 0;
	CClientDC dc(this);

	CPen MyPen(PS_SOLID, 0, RGB(206, 103, 0));
	CPen *oldPen = dc.SelectObject(&MyPen);

	CBrush MyBrush(RGB(206, 103, 0));
	CBrush *oldBrush = dc.SelectObject(&MyBrush);

	dc.Rectangle(10, 10, 10 + 20 * 9, 10 + 20 * 9);

	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);

	CPen MyPen2(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *oldPen2 = dc.SelectObject(&MyPen2);

	for (x = 0;x <= 9;x++)
	{
		dc.MoveTo(10 + 20 * x, 10);
		dc.LineTo(10 + 20 * x, 10 + 20 * 9);
	}

	for (y = 0;y <= 9;y++)
	{
		dc.MoveTo(10, 10 + 20 * y);
		dc.LineTo(10 + 20 * 9, 10 + 20 * y);
	}
	dc.SelectObject(oldPen2);
}


void CChapter10OMokDlg::OnClickedButtStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strColAl = "검정색 알";
	m_bStart = TRUE;
	UpdateData(FALSE);
	Invalidate(TRUE);
}


void CChapter10OMokDlg::InitBoard()
{
	// TODO: 여기에 구현 코드 추가.
	for (int y = 0;y < 10;y++)
	{
		for (int x = 0;x < 10;x++)
		{
			m_nBoard[y][x] = 0;
		}
	}
}


void CChapter10OMokDlg::DrawAI()
{
	// TODO: 여기에 구현 코드 추가.
	CClientDC dc(this);
	int x, y;

	for (y = 0;y < 10;y++)
	{
		for (x = 0;x < 10;x++)
		{
			if (m_nBoard[y][x] == 1)	// 바둑알이 검정색이면
			{
				dc.SelectObject(GetStockObject(BLACK_BRUSH));
				dc.Ellipse(2 + 20 * x, 2 + 20 * y, 18 + 20 * x, 18 + 20 * y);
				// 2하고 18은 알과 알사이의 간격이다.
				//Ellipse 첫번째,두번째 매개변수는 x,y좌표로써 가로,세로 위치이다.
				//세번째 네번째는 원의 크기이다.
			}
			else if(m_nBoard[y][x]==2)	// 바둑알이 흰색이면
			{
				dc.SelectObject(GetStockObject(WHITE_BRUSH));
				dc.Ellipse(2 + 20 * x, 2 + 20 * y, 18 + 20 * x, 18 + 20 * y);
			}
		}
	}
}


void CChapter10OMokDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bStart == TRUE)
	{
		int ax = 0, ay = 0;
		ax = point.x / 20;
		ay = point.y / 20;

		if (ax < 0 || ax >= 10 || ay < 0 || ay >= 10)
			return;

		if (m_nBoard[ay][ax] != 0)
			return;

		if (m_bTurn == FALSE)
		{
			m_nBoard[ay][ax] = 1;
			m_bTurn = TRUE;
		}
		else if (m_bTurn == TRUE)
		{
			m_nBoard[ay][ax] = 2;
			m_bTurn = FALSE;
		}
		
		if (m_bTurn == FALSE)
			m_strColAl = "검정색 알";
		else if (m_bTurn == TRUE)
			m_strColAl = "흰색 알";

		UpdateData(FALSE);
		DrawAI();

	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CChapter10OMokDlg::OnClickedButtRestart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bTurn = FALSE;
	m_strColAl = "검정색";
	InitBoard();
	UpdateData(FALSE);
	Invalidate(TRUE);
}


void CChapter10OMokDlg::OnFileSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFileDialog dlgFileOpen(FALSE, "bor", NULL, OFN_FILEMUSTEXIST,"바둑판(*.bor)|*.bor||",NULL);
	
	long IBoard = 0;
	if (dlgFileOpen.DoModal() == IDOK)
	{
		if (dlgFileOpen.GetFileExt() == "bor")
		{
			// 저장하고 싶은 파일의 절대경로와 모드를 넣어 CFile의 객체를 생성한다.
			CFile BoardFile(dlgFileOpen.GetPathName(),CFile::modeCreate|CFile::modeWrite);
			
			CArchive caBoard(&BoardFile, CArchive::store);	 //개발자와 CFile간의 유통 클래스

			for (int y = 0;y < 10;y++)
			{
				for (int x = 0;x < 10;x++)
				{
					caBoard << (long)m_nBoard[y][x];	//long형 2차원배열을 요소들을 넣는다.
				}
			}
			
			caBoard << m_bTurn;

			caBoard.Close();
			BoardFile.Close();
		}
	}

}


void CChapter10OMokDlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
