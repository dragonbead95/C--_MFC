// PuzzDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Puzz.h"
#include "PuzzDlg.h"

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
// CPuzzDlg dialog

CPuzzDlg::CPuzzDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPuzzDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPuzzDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPuzzDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPuzzDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPuzzDlg, CDialog)
	//{{AFX_MSG_MAP(CPuzzDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_START, OnButtStart)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPuzzDlg message handlers

BOOL CPuzzDlg::OnInitDialog()
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
	m_bStart=FALSE;
	InitPuzz();
	m_bitPuzz.LoadBitmap(IDB_PUZZ);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPuzzDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPuzzDlg::OnPaint() 
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
	if(m_bStart==FALSE)
		DrawBmp();
	else
	{
    	DrawBack();
		for(int y=0; y<3; y++)
			for(int x=0; x<3; x++)
				DrawPuzzBmp(y,x,m_nPuzz[y][x]);
		DrawNum();
	}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPuzzDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPuzzDlg::DrawBmp()
{
	CClientDC dc(this);
	CDC memDC;
	
	memDC.CreateCompatibleDC(&dc);
	CBitmap *oldBitPuzz=memDC.SelectObject(&m_bitPuzz);
	dc.BitBlt(10,10,180,180,&memDC,0,0,SRCCOPY);
	memDC.SelectObject(oldBitPuzz);
}

void CPuzzDlg::DrawPuzzBmp(int nRow, int nCol, int nNum)
{
	int nSize=180/3;

	if(nNum==-1)
		ZeroRect(nRow,nCol);

	int nX=int(nNum%3);
	int nY=int(nNum/3);

	CClientDC dc(this);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap *oldBitPuzz=memDC.SelectObject(&m_bitPuzz);

	dc.BitBlt(10+(nCol*(nSize+3)),10+(nRow*(nSize+3)),nSize,nSize,
		          &memDC,(nX*nSize),(nY*nSize),SRCCOPY);

	memDC.SelectObject(oldBitPuzz);
	
}

void CPuzzDlg::InitPuzz()
{
	int nCount=0;

	for(int y=0; y<3; y++)
		for(int x=0; x<3; x++)
			m_nPuzz[y][x]=nCount++;

	m_nPuzz[2][2]=-1;

}

void CPuzzDlg::OnButtStart() 
{
	// TODO: Add your control notification handler code here
	m_bStart=TRUE;
	
	DrawBack();
	
	RandPuzzBmp();

}

void CPuzzDlg::DrawBack()
{
	CClientDC dc(this);

	// 배경 그리기
	CPen WhitePen(PS_SOLID,1,RGB(255,255,255));
	CPen *oldWhitePen=dc.SelectObject(&WhitePen);

	CBrush WhiteBrush(RGB(255,255,255));
	CBrush *oldWhiteBrush=dc.SelectObject(&WhiteBrush);

	dc.Rectangle(8,8,8+(63*3),8+(63*3));

	dc.SelectObject(oldWhitePen);
	dc.SelectObject(oldWhiteBrush);
	
    
	CPen RedPen(PS_SOLID,1,RGB(255,0,0));
	CPen *oldRedPen=dc.SelectObject(&RedPen);
	for(int x=0; x<4; x++)
	{
		dc.MoveTo(8,8+x*63);
		dc.LineTo(8+(63*3),8+x*63);
	}
	for(int y=0; y<4; y++)
	{
		dc.MoveTo(8+y*63,8);
		dc.LineTo(8+y*63,8+(63*3));
	}

	dc.SelectObject(&oldRedPen);
}

void CPuzzDlg::DrawNum()
{
	CClientDC dc(this);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(0,0,255));
	char szText[2]="";

	for(int y=0; y<3; y++)
	{
		for(int x=0; x<3; x++)
		{
		    if(-1!=m_nPuzz[y][x])
			{
				sprintf(szText,"%d",m_nPuzz[y][x]);
			    dc.TextOut(10+((63*x)),10+((63*y)),szText);
			}
		}
	}
}

void CPuzzDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int nMusY=0, nMusX=0;
	int nZeroY=0, nZeroX=0;
	if(m_bStart==TRUE)
	{
		if(PosToIndex(point,nMusY,nMusX))
		{
			if(ZeroPostion(nMusY,nMusX,nZeroY,nZeroX))
			{
				MovePuzzBmp(nMusY,nMusX,nZeroY,nZeroX);
			    DrawNum();
				if(CheckPuzz())
				{
					MessageBox("축합니다.^^","알림",NULL);
					m_bStart=FALSE;
					Invalidate();
				}

			}
		}
	}

	CDialog::OnLButtonDown(nFlags, point);
}

BOOL CPuzzDlg::PosToIndex(CPoint pos,int &nY, int &nX)
{
	for(int y=0; y<3; y++)
	{
		if((pos.y>10+y*63) && (pos.y<10+(y+1)*63-3))
			break;
	}

	for(int x=0; x<3; x++)
	{
		if((pos.x>10+x*63) && (pos.x<10+(x+1)*63-3))
			break;
	}

	if(y==3 || x==3)
		return FALSE;
	else
	{
		nY=y;
		nX=x;
		return TRUE;
	}
}

BOOL CPuzzDlg::ZeroPostion(int nMusY,int nMusX,int &nZeroY,int &nZeroX)
{
	int i=0;
	for(i=0; i<3; i++)
	{
		if(-1==m_nPuzz[i][nMusX])
		{
			nZeroY=i;
			nZeroX=nMusX;
			return TRUE;
		}
	}

	for(i=0; i<3; i++)
	{
		if(-1==m_nPuzz[nMusY][i])
		{
			nZeroY=nMusY;
			nZeroX=i;
			return TRUE;
		}
	}

	return FALSE;
}

void CPuzzDlg::MovePuzzBmp(int nMusY,int nMusX,int nZeroY,int nZeroX)
{
	int nY=nMusY-nZeroY;
	int nX=nMusX-nZeroX;

	int a=0;

	if(nY>0)
	{
		for(a=nZeroY; a<nMusY; a++)
		{
			m_nPuzz[a][nMusX]=m_nPuzz[a+1][nMusX];
			DrawPuzzBmp(a,nMusX,m_nPuzz[a+1][nMusX]);
		}
	}

	if(nY<0)
	{
		for(a=nZeroY; a>nMusY; a--)
		{
			m_nPuzz[a][nMusX]=m_nPuzz[a-1][nMusX];
			DrawPuzzBmp(a,nMusX,m_nPuzz[a-1][nMusX]);
		}
	}

	if(nX>0)
	{
		for(a=nZeroX; a<nMusX; a++)
		{
			m_nPuzz[nMusY][a]=m_nPuzz[nMusY][a+1];
			DrawPuzzBmp(nMusY,a,m_nPuzz[nMusY][a+1]);
		}
	}

	if(nX<0)
	{
		for(a=nZeroX; a>nMusX; a--)
		{
			m_nPuzz[nMusY][a]=m_nPuzz[nMusY][a-1];
			DrawPuzzBmp(nMusY,a,m_nPuzz[nMusY][a-1]);
		}
	}

	m_nPuzz[nMusY][nMusX]=-1;
	ZeroRect(nMusY,nMusX);
	
}

void CPuzzDlg::ZeroRect(int nZeroY, int nZeroX)
{
	int nSize=180/3;

	CClientDC dc(this);
	CPen RedPen(PS_SOLID,1,RGB(255,0,0));
	CPen *oldRedPen=dc.SelectObject(&RedPen);
	CBrush RedBrush(RGB(255,0,0));
	CBrush *oldRedBrush=dc.SelectObject(&RedBrush);

	
	dc.Rectangle(10+(nZeroX*(nSize+3)),
		             10+(nZeroY*(nSize+3)),
		             10+(nZeroX*(nSize+3))+60,
				     10+(nZeroY*(nSize+3))+60);

	dc.SelectObject(oldRedBrush);
	dc.SelectObject(oldRedPen);
}

void CPuzzDlg::RandPuzzBmp()
{
	srand((unsigned)time(NULL));

	int nRandY,nRandX;
	int nY,nX;

	BOOL bBool=FALSE;

	for(int i=0; i<500; i++)
	{
		nRandY=rand()%3;
		nRandX=rand()%3;
		
		bBool=ZeroPostion(nRandY,nRandX,nY,nX);
		
		if(bBool)
		{
			MovePuzzBmp(nRandY,nRandX,nY,nX);
			DrawNum();
		}
	}
}


BOOL CPuzzDlg::CheckPuzz()
{
	for(int y=0; y<3; y++)
	{
		for(int x=0; x<3; x++)
		{
			if(y==2 && x==2)
			{
				if(m_nPuzz[y][x]!=-1)
					return FALSE;
			}
			else
			{
				if(m_nPuzz[y][x] != y*3+x)
					return FALSE;
			}
		}
	}
	return TRUE;
}

void CPuzzDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
