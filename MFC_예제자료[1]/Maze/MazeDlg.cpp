// MazeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Maze.h"
#include "MazeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeDlg dialog

CMazeDlg::CMazeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMazeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMazeDlg)
	m_strDown = _T("");
	m_strFrag = _T("");
	m_strLeft = _T("");
	m_strRight = _T("");
	m_strUp = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMazeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMazeDlg)
	DDX_Text(pDX, IDC_STATIC_DOWN, m_strDown);
	DDX_Text(pDX, IDC_STATIC_FRAG, m_strFrag);
	DDX_Text(pDX, IDC_STATIC_LEFT, m_strLeft);
	DDX_Text(pDX, IDC_STATIC_RIGHT, m_strRight);
	DDX_Text(pDX, IDC_STATIC_UP, m_strUp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMazeDlg, CDialog)
	//{{AFX_MSG_MAP(CMazeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(FILE_LOAD, OnLoad)
	ON_BN_CLICKED(IDC_BUTT_START, OnButtStart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTT_RESTART, OnButtRestart)
	ON_COMMAND(FILE_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeDlg message handlers

BOOL CMazeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	InitMaze();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMazeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMazeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	CPoint p=0;

	for(int y=0; y<20; y++)
	{
		for(int x=0; x<20; x++)
		{
			p.y=y;
			p.x=x;
			DrawBlock(p);
		}
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMazeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMazeDlg::InitMaze()
{
	for(int y=0; y<20; y++)
	{
		for(int x=0; x<20; x++)
		{
			m_nMaze[y][x]=0;
		}
	}
}

void CMazeDlg::DrawBlock(CPoint pMus)
{
	CClientDC dc(this);

	CBrush BlueBrush(RGB(0,0,255));
	CBrush *oldBlueBrush=0;
	CPen BluePen(PS_SOLID,1,RGB(0,0,255));
	CPen *oldBluePen=0;

	CBrush GreenBrush(RGB(0,255,0));
	CBrush *oldGreenBrush=0;
	CPen GreenPen(PS_SOLID,1,RGB(0,255,0));
	CPen *oldGreenPen=0;

	CBrush BlackBrush(RGB(0,0,0));
	CBrush *oldBlackBrush=0;
	CPen BlackPen(PS_SOLID,1,RGB(0,0,0));
	CPen *oldBlackPen=0;

	CBrush WhiteBrush(RGB(255,255,255));
	CBrush *oldWhiteBrush=0;
	CPen WhitePen(PS_SOLID,1,RGB(255,255,255));
	CPen *oldWhitePen=0;

	switch(m_nMaze[pMus.y][pMus.x])
	{
	case 5: // 시작
		oldBluePen=dc.SelectObject(&BluePen);
		oldBlueBrush=dc.SelectObject(&BlueBrush);
		break;
	case 6: // 끝
		oldGreenPen=dc.SelectObject(&GreenPen);
		oldGreenBrush=dc.SelectObject(&GreenBrush);
		break;
	case 1: // 블럭
		oldBlackPen=dc.SelectObject(&BlackPen);
		oldBlackBrush=dc.SelectObject(&BlackBrush);
		break;
	case 0: // 길
		oldWhitePen=dc.SelectObject(&WhitePen);
		oldWhiteBrush=dc.SelectObject(&WhiteBrush);
		break;
	}

	dc.Rectangle(10+(pMus.x*20),
		         10+(pMus.y*20),
				 10+(pMus.x*20)+20,
				 10+(pMus.y*20)+20);

	dc.SelectObject(oldBluePen);
	dc.SelectObject(oldGreenPen);
	dc.SelectObject(oldBlackPen);
	dc.SelectObject(oldWhitePen);

	dc.SelectObject(oldBlueBrush);
        
	dc.SelectObject(oldGreenBrush);

	dc.SelectObject(oldBlackBrush);

	dc.SelectObject(oldWhiteBrush);
}

void CMazeDlg::OnLoad() 
{
	// TODO: Add your command handler code here
	CFileDialog dlgFileOpen(TRUE,"roa",NULL,
		                 OFN_FILEMUSTEXIST,
					"미로(*.roa)|*.roa||",
					NULL);
    long lBoard=0;
	if(dlgFileOpen.DoModal()==IDOK)
	{
		if(dlgFileOpen.GetFileExt()=="roa")
		{
			CFile BoardFile(dlgFileOpen.GetPathName(),CFile::modeRead);
		
	        CArchive caBoard(&BoardFile,CArchive::load);
            for(int y=0; y<20; y++)
			{
				for(int x=0; x<20; x++)
				{
					caBoard >> lBoard;
					m_nMaze[y][x]=lBoard;
				}
			}

			caBoard.Close();
			BoardFile.Close();

			Invalidate();

			m_strLeft="";
	        m_strUp="";
	        m_strRight="";
	        m_strDown="";
	        UpdateData(FALSE);

		}
		else
			MessageBox("미로 파일이 아닙니다.","알림",NULL);
	}
}

void CMazeDlg::OnButtRestart() 
{
	// TODO: Add your control notification handler code here
	CPoint p=0;

	KillTimer(1);

	// 시작지점
	m_nMaze[m_pStart.y][m_pStart.x]=5;
	
	// 캐릭터가 있던 지점을 길로 바꾼다.
	if(CharPostion(p))
		m_nMaze[p.y][p.x]=0;

	m_strLeft="";
	m_strUp="";
	m_strRight="";
	m_strDown="";
	UpdateData(FALSE);

	Invalidate();
}

void CMazeDlg::OnButtStart() 
{
	// TODO: Add your control notification handler code here
	// 시작지점 찾기
	CPoint pStart=0;

	if(StartPoint(pStart))
	{
		// 시작지점에 캐릭터의 위치를 지정한다.
		m_pStart=pStart;
		m_nMaze[pStart.y][pStart.x]=-1;

		CleanChar(0,0,pStart);
		DrawChar(0,0,pStart);

		SetTimer(1,1,NULL);
		UpdateData(FALSE);
	}
}

BOOL CMazeDlg::StartPoint(CPoint &p)
{
	for(int y=0; y<20; y++)
	{
		for(int x=0; x<20; x++)
		{
			if(m_nMaze[y][x]==5)
			{
				p.y=y;
				p.x=x;
				return TRUE;
			}
		}
	}
	return FALSE;
}

void CMazeDlg::CleanChar(int nMovY, int nMovX, CPoint p)
{
	CClientDC dc(this);

	CBrush WhiteBrush(RGB(255,255,255));
	CBrush *oldWhiteBrush=dc.SelectObject(&WhiteBrush);
	CPen WhitePen(PS_SOLID,1,RGB(255,255,255));
	CPen *oldWhitePen=dc.SelectObject(&WhitePen);
	
	dc.Rectangle(10+(p.x*20)+nMovX,
		         10+(p.y*20)+nMovY,
				 10+(p.x*20)+20+nMovX,
				 10+(p.y*20)+20+nMovY);

	dc.SelectObject(oldWhitePen);
	
	dc.SelectObject(oldWhiteBrush);
}

BOOL CMazeDlg::CharPostion(CPoint &p)
{
	for(int y=0; y<20; y++)
	{
		for(int x=0; x<20; x++)
		{
			if(m_nMaze[y][x]==-1)
			{
				p.y=y;
				p.x=x;
				return TRUE;
			}
		}
	}
	return FALSE;
}

void CMazeDlg::DrawChar(int nMovY, int nMovX, CPoint p)
{
	CClientDC dc(this);
	CPen RedPen(PS_SOLID,1,RGB(255,0,0));
	CPen *oldRedPen=dc.SelectObject(&RedPen);

	CBrush RedBrush(RGB(255,0,0));
	CBrush *oldRedBrush=dc.SelectObject(&RedBrush);

	dc.Ellipse(15+(p.x*20)+nMovX,
		       15+(p.y*20)+nMovY,
			   15+(p.x*20)+10+nMovX,
			   15+(p.y*20)+10+nMovY);

	dc.SelectObject(oldRedPen);
	dc.SelectObject(oldRedBrush);
}

void CMazeDlg::RoadPostion(CPoint p, int &nLeft, int &nUp, int &nRight, int &nDown)
{
	// 왼쪽
	if(m_nMaze[p.y][p.x-1]==0) 	
		nLeft=1;
	else
		nLeft=0;
	
	// 위쪽
	if(m_nMaze[p.y-1][p.x]==0)
		nUp=2;
	else
		nUp=0;

	// 오른쪽
	if(m_nMaze[p.y][p.x+1]==0)
		nRight=3;
	else
		nRight=0;

	// 아래쪽
	if(m_nMaze[p.y+1][p.x]==0) 
		nDown=4;
	else
		nDown=0;
}

void CMazeDlg::MovChar()
{
    // 방향
	static int a=1;
	CPoint p=0;
	static int c=0;

	// 캐릭터의 위치 찾기
	CharPostion(p);

	switch(a)
	{
	case 1: // 왼쪽에 벽이 없다면
		if(m_nMaze[p.y][p.x-1]!=1)
		{
			// 끝지점인지 체크
			if(m_nMaze[p.y][p.x-1]==6)
			{
				c--;
				CleanChar(0,c,p);
				DrawChar(0,c,p);
		    	
				if(c==-20)
		    	{
					m_strFrag="끝";
					KillTimer(1);
				}
			}
			else // 끝지점이 아니라면 왼쪽으로 이동
			{
				m_strFrag="왼쪽";
				c--;
				CleanChar(0,c,p);
				DrawChar(0,c,p);

				if(c==-20)
		    	{
					m_nMaze[p.y][p.x]=0;
			    	m_nMaze[p.y][p.x-1]=-1;
					
					c=0;
				}
			}
		}
		else // 벽이라면
			Ai(a);
		break;
	case 2: //위쪽에 벽이 없다면
		if(m_nMaze[p.y-1][p.x]!=1)
		{
			// 끝지점인지 체크
			if(m_nMaze[p.y-1][p.x]==6)
			{
				c--;
				CleanChar(c,0,p);
				DrawChar(c,0,p);

				if(c==-20)
				{
					m_strFrag="끝";
					KillTimer(1);
				}
			}
			else // 끝지점이 아니라면 위쪽으로 이동
			{
				m_strFrag="위쪽";
			    c--;
				CleanChar(c,0,p);
				DrawChar(c,0,p);
			
			    if(c==-20)
				{
					m_nMaze[p.y][p.x]=0;
			        m_nMaze[p.y-1][p.x]=-1;
    			    
					c=0;
				}
			}
		}
		else // 벽이라면
			Ai(a);
		break;
	case 3: // 오른쪽에 벽이 없다면
		if(m_nMaze[p.y][p.x+1]!=1)
		{	
			// 끝지점인지 체크
			if(m_nMaze[p.y][p.x+1]==6)
			{
				c++;
				CleanChar(0,c,p);
				DrawChar(0,c,p);

				if(c==20)
				{
					m_strFrag="끝";
					KillTimer(1);
				}
			}
			else // 끝지점이 아니라면 오른쪽으로 이동
			{
				m_strFrag="오른쪽";
			    c++;
				CleanChar(0,c,p);
				DrawChar(0,c,p);
			    
			    if(c==20)
				{
					m_nMaze[p.y][p.x]=0;
			        m_nMaze[p.y][p.x+1]=-1;

					c=0;
				}
			}
		}
		else
			Ai(a);
		break;
	case 4: // 아래쪽에 벽이 없다면
		if(m_nMaze[p.y+1][p.x]!=1)
		{
			// 끝지점인지 체크
			if(m_nMaze[p.y+1][p.x]==6)
			{
				c++;
				CleanChar(c,0,p);
				DrawChar(c,0,p);

				if(c==20)
				{
					m_strFrag="끝";
					KillTimer(1);
				}
			}
			else // 끝지점이 아니라면 아래쪽으로 이동
			{
				m_strFrag="아래쪽";
				c++;
				CleanChar(c,0,p);
				DrawChar(c,0,p);
				
				if(c==20)
				{
					m_nMaze[p.y][p.x]=0;
					m_nMaze[p.y+1][p.x]=-1;

					c=0;

				}
			}
		}
		else // 벽이라면
			Ai(a);
		break;
	}
	UpdateData(FALSE);

}

void CMazeDlg::Ai(int &a)
{
	CPoint pChar=0;
	int nLeft=0,nUp=0,nRight=0,nDown=0;

	if(CharPostion(pChar))
	{
		RoadPostion(pChar,nLeft,nUp,nRight,nDown);
		m_strLeft.Format("Left: %d",nLeft);
		m_strUp.Format("Up: %d",nUp);
		m_strRight.Format("Right: %d",nRight);
		m_strDown.Format("Down: %d",nDown);
		
		UpdateData(FALSE);

		// 왼쪽
		if((nLeft) && (nUp==0) && (nRight==0) && (nDown==0))
			a=1;

		// 위쪽
		if((nLeft==0) && (nUp) && (nRight==0) && (nDown==0))
			a=2;

		// 오른쪽
		if((nLeft==0) && (nUp==0) && (nRight) && (nDown==0))
			a=3;

		// 아래쪽
		if((nLeft==0) && (nUp==0) && (nRight==0) && (nDown))
			a=4;

		// 왼쪽 아래쪽
		if((nLeft) && (nUp==0) && (nRight==0) && (nDown))
		{
			if(a==2)
				a=1;
			if(a==3)
	   			a=4;
		}

		// 왼쪽 위쪽
		if((nLeft) && (nUp) && (nRight==0) && (nDown==0))
		{
			if(a==4)
				a=1;
			if(a==3)
				a=2;
		}

		// 오른쪽 아래쪽
		if((nLeft==0) && (nUp==0) && (nRight) && (nDown))
		{
			if(a==0)
				a=3;
			if(a==1)
				a=4;
			if(a==2)
				a=3;
		}
	
		// 오른쪽 위쪽
		if((nLeft==0) && (nUp) && (nRight) && (nDown==0))
		{
			if(a==4)
				a=3;
			if(a==1)
				a=2;
		}

		// 왼쪽 오른쪽 위쪽
		if((nLeft) && (nUp) && (nRight) && (nDown==0))
			a=3;

		// 왼쪽 위쪽 아래쪽
		if((nLeft) && (nUp) && (nRight==0) && (nDown))
			a=4;

		// 왼쪽 오른쪽 아래쪽
		if((nLeft) && (nUp==0) && (nRight) && (nDown))
			a=3;
	}

}

void CMazeDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	MovChar();
	CDialog::OnTimer(nIDEvent);
}

void CMazeDlg::OnExit() 
{
	// TODO: Add your command handler code here
	OnOK();
}
