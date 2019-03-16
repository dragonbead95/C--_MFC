// MazeEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MazeEdit.h"
#include "MazeEditDlg.h"

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
// CMazeEditDlg dialog

CMazeEditDlg::CMazeEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMazeEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMazeEditDlg)
	m_strMus = _T("");
	m_strBlock = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMazeEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMazeEditDlg)
	DDX_Text(pDX, IDC_STATIC_MUS, m_strMus);
	DDX_Text(pDX, IDC_STATIC_BLOCK, m_strBlock);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMazeEditDlg, CDialog)
	//{{AFX_MSG_MAP(CMazeEditDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_REDRAW, OnButtRedraw)
	ON_BN_CLICKED(IDC_BUTT_START, OnButtStart)
	ON_BN_CLICKED(IDC_BUTT_END, OnButtEnd)
	ON_BN_CLICKED(IDC_BUTT_BLOCK, OnButtBlock)
	ON_BN_CLICKED(IDC_BUTT_ROAD, OnButtRoad)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	ON_COMMAND(FILE_LOAD, OnLoad)
	ON_COMMAND(FILE_SAVE, OnSave)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeEditDlg message handlers

BOOL CMazeEditDlg::OnInitDialog()
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
	m_nBlock=1;
	m_strBlock="1: 블럭";
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMazeEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMazeEditDlg::OnPaint() 
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
	DrawNum();
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMazeEditDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMazeEditDlg::DrawBlock(CPoint pMus)
{
	CClientDC dc(this);
	CBrush BlueBrush(RGB(0,0,255));
	CBrush *oldBlueBrush=0;

	CBrush GreenBrush(RGB(0,255,0));
	CBrush *oldGreenBrush=0;

	CBrush BlackBrush(RGB(0,0,0));
	CBrush *oldBlackBrush=0;

	CBrush WhiteBrush(RGB(255,255,255));
	CBrush *oldWhiteBrush=0;

	switch(m_nMaze[pMus.y][pMus.x])
	{
	case 5: // 시작
		oldBlueBrush=dc.SelectObject(&BlueBrush);
		break;
	case 6: // 끝
		oldGreenBrush=dc.SelectObject(&GreenBrush);
		break;
	case 1: // 블럭
		oldBlackBrush=dc.SelectObject(&BlackBrush);
		break;
	case 0: // 길
		oldWhiteBrush=dc.SelectObject(&WhiteBrush);
		break;
	}

	dc.Rectangle(10+(pMus.x*20),
		         10+(pMus.y*20),
				 10+(pMus.x*20)+20,
				 10+(pMus.y*20)+20);

	dc.SelectObject(oldBlueBrush);
        
	dc.SelectObject(oldGreenBrush);

	dc.SelectObject(oldBlackBrush);

	dc.SelectObject(oldWhiteBrush);

}

void CMazeEditDlg::InitMaze()
{
	for(int y=0; y<20; y++)
	{
		for(int x=0; x<20; x++)
		{
			m_nMaze[y][x]=0;
		}
	}
}

BOOL CMazeEditDlg::PosToIndex(CPoint pClkMus, CPoint &pMus)
{
		for(int y=0; y<20; y++)
	{
		if((pClkMus.y>10+y*20) && (pClkMus.y<10+(y+1)*20))
			break;
	}

	for(int x=0; x<20; x++)
	{
		if((pClkMus.x>10+x*20) && (pClkMus.x<10+(x+1)*20))
			break;
	}

	if(y==20 || x==20)
		return FALSE;
	else
	{
		pMus.y=y;
		pMus.x=x;
		return TRUE;
	}

}

void CMazeEditDlg::DrawNum()
{
	CClientDC dc(this);
	char szText[2];

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255,0,0));

	for(int y=0; y<20; y++)
	{
		for(int x=0; x<20; x++)
		{
			sprintf(szText,"%d",m_nMaze[y][x]);
			dc.TextOut(10+(20*x)+6,10+(20*y)+2,szText);
		}
	}


}

void CMazeEditDlg::OnButtRedraw() 
{
	// TODO: Add your control notification handler code here
	InitMaze();
	m_nBlock=1;
	m_strBlock="1: 블럭";
	UpdateData(FALSE);
	Invalidate();
}

void CMazeEditDlg::OnButtStart() 
{
	// TODO: Add your control notification handler code here
	m_nBlock=5;
	m_strBlock="5: 시작지점";
	UpdateData(FALSE);
}

void CMazeEditDlg::OnButtEnd() 
{
	// TODO: Add your control notification handler code here
	m_nBlock=6;
	m_strBlock="6: 끝지점";
	UpdateData(FALSE);
}

void CMazeEditDlg::OnButtBlock() 
{
	// TODO: Add your control notification handler code here
	m_nBlock=1;
	m_strBlock="1: 블럭";
	UpdateData(FALSE);
}

void CMazeEditDlg::OnButtRoad() 
{
	// TODO: Add your control notification handler code here
	m_nBlock=0;
	m_strBlock="0: 길";
	UpdateData(FALSE);
}

void CMazeEditDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CMazeEditDlg::OnLoad() 
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

		}
		else
			MessageBox("미로 파일이 아닙니다.","알림",NULL);
	}
}

void CMazeEditDlg::OnSave() 
{
	// TODO: Add your command handler code here
		CFileDialog dlgFileOpen(FALSE,"roa",NULL,
		                 OFN_FILEMUSTEXIST,
	     				"미로(*.roa)|*.roa||",
		      			NULL);

	if(dlgFileOpen.DoModal()==IDOK)
	{
		if(dlgFileOpen.GetFileExt()=="roa")
		{
			CFile BoardFile(dlgFileOpen.GetPathName(),
				  CFile::modeCreate|CFile::modeWrite);
		
		    CArchive caBoard(&BoardFile,CArchive::store);
            for(int y=0; y<20; y++)
			{
				for(int x=0; x<20; x++)
				{
					caBoard << (long)m_nMaze[y][x];
				}
			}

			caBoard.Close();
			BoardFile.Close();
		}
	}
}

void CMazeEditDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint pMus=0;;

	if(PosToIndex(point,pMus))
	{
		m_strMus.Format("[Mus] y:%d, x:%d",
		                      pMus.y,
							  pMus.x);
		m_nMaze[pMus.y][pMus.x]=m_nBlock;
		DrawBlock(pMus);
		DrawNum();
	}
	UpdateData(FALSE);
	CDialog::OnLButtonDown(nFlags, point);
}
