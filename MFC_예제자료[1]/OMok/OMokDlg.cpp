// OMokDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OMok.h"
#include "OMokDlg.h"

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
// COMokDlg dialog

COMokDlg::COMokDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COMokDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COMokDlg)
	m_strColAl = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COMokDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COMokDlg)
	DDX_Text(pDX, IDC_STATIC_COLAL, m_strColAl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COMokDlg, CDialog)
	//{{AFX_MSG_MAP(COMokDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_START, OnButtStart)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTT_RESTART, OnButtRestart)
	ON_COMMAND(FILE_OPEN, OnOpen)
	ON_COMMAND(FILE_SAVE, OnSave)
	ON_COMMAND(FILE_EXIT, OnExit)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COMokDlg message handlers

BOOL COMokDlg::OnInitDialog()
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
	InitBoard();
	m_bTurn=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COMokDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COMokDlg::OnPaint() 
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
	if(m_bStart==TRUE)
	{
		DrawBack();
		DrawAl();
	}
		
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COMokDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COMokDlg::DrawBack()
{
	int x=0,y=0;
	CClientDC dc(this);

	// 배경이 되는 사각형을 그린다.
	CPen MyPen(PS_SOLID,0,RGB(206,103,0));
	CPen *oldPen=dc.SelectObject(&MyPen);

	CBrush MyBrush(RGB(206,103,0));
	CBrush *oldBrush=dc.SelectObject(&MyBrush);

	dc.Rectangle(10,10,10+20*9,10+20*9);

	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);

	// 선을 그린다.
	CPen MyPen2(PS_SOLID,1,RGB(0,0,0));
	CPen *oldPen2=dc.SelectObject(&MyPen2);

	// 위에서 아래로 선을 그린다.
    // 이런 선을 10개 그린다.
	
	for(x=0; x<=9 ; x++)
	{
		dc.MoveTo(10+20*x,10);
		dc.LineTo(10+20*x,10+20*9);
	}

	// 왼쪽에서 오른쪽으로 선을 그린다.
	// 이런 선을 10개 그린다.
	for(y=0; y<=9 ; y++) 
	{
		dc.MoveTo(10,10+20*y);
		dc.LineTo(10+20*9,10+20*y);
	}
	dc.SelectObject(oldPen2);
}

void COMokDlg::OnButtStart() 
{
	// TODO: Add your control notification handler code here
	m_strColAl="검정색 알";
	m_bStart=TRUE;
	UpdateData(FALSE);

    // 이 함수는 항상 말했듯이 OnPaint함수를 호출한다.
	Invalidate(TRUE);
}

void COMokDlg::InitBoard()
{
	for(int y=0; y<10; y++)
		for(int x=0; x<10; x++)
			m_nBoard[y][x]=0;

}

void COMokDlg::DrawAl()
{
	CClientDC dc(this);
	int x,y;
	for(y=0; y<10; y++)
	{
		for(x=0; x<10; x++)
		{
			if(m_nBoard[y][x]==1) // 바둑알이 검정색이면...
			{
				dc.SelectObject(GetStockObject(BLACK_BRUSH));
				dc.Ellipse(2+20*x,2+20*y,18+20*x,18+20*y);
			}
			else if(m_nBoard[y][x]==2) // 바둑알이 흰색이면...
			{
				dc.SelectObject(GetStockObject(WHITE_BRUSH));
				dc.Ellipse(2+20*x,2+20*y,18+20*x,18+20*y);
			}
		}
	}
}

void COMokDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bStart==TRUE)
	{
		int ax=0,ay=0;

	    ax=point.x/20;
	    ay=point.y/20;

	    if((ax<0) || (ax>=10) || (ay<0) || (ay>=10))
			return;

	    if(m_nBoard[ay][ax]!=0)
			return;

	    if(m_bTurn==FALSE)
		{
			m_nBoard[ay][ax]=1;
		    m_bTurn=TRUE;
		}
		else if(m_bTurn==TRUE)
		{
			m_nBoard[ay][ax]=2;
		    m_bTurn=FALSE;
		}
		
		if(m_bTurn==FALSE)
		   m_strColAl="검정색 알";
	    else if(m_bTurn==TRUE)
		   m_strColAl="흰색 알";

	    UpdateData(FALSE);
	    DrawAl();
	}

	CDialog::OnLButtonDown(nFlags, point);
}

void COMokDlg::OnButtRestart() 
{
	// TODO: Add your control notification handler code here
	m_bTurn=FALSE;
	m_strColAl="검정색";
	InitBoard();
	UpdateData(FALSE);
	Invalidate(TRUE);
}

void COMokDlg::OnOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog dlgFileOpen(TRUE,"bor",NULL,
		                 OFN_FILEMUSTEXIST,
					"바둑판(*.bor)|*.bor||",
					NULL);
    long lBoard=0;
	if(dlgFileOpen.DoModal()==IDOK)
	{
		if(dlgFileOpen.GetFileExt()=="bor")
		{
			CFile BoardFile(dlgFileOpen.GetPathName(),CFile::modeRead);
		
	        CArchive caBoard(&BoardFile,CArchive::load);
            for(int y=0; y<10; y++)
			{
				for(int x=0; x<10; x++)
				{
					caBoard >> lBoard;
					m_nBoard[y][x]=lBoard;
				}
			}

			caBoard >> m_bTurn;

			caBoard.Close();
			BoardFile.Close();

			if(m_bStart==FALSE)
				m_bStart=TRUE;

			if(m_bTurn==FALSE)
			{
				m_strColAl="검정색 알";
			}
	        else if(m_bTurn==TRUE)
			{
				m_strColAl="흰색 알";
			}

			Invalidate(TRUE);

			UpdateData(FALSE);
		}
		else
			MessageBox("바둑판 파일이 아닙니다.","알림",NULL);
	}
}

void COMokDlg::OnSave() 
{
	// TODO: Add your command handler code here
	CFileDialog dlgFileOpen(FALSE,"bor",NULL,
		                 OFN_FILEMUSTEXIST,
					"바둑판(*.bor)|*.bor||",
					NULL);

	if(dlgFileOpen.DoModal()==IDOK)
	{
		if(dlgFileOpen.GetFileExt()=="bor")
		{
			CFile BoardFile(dlgFileOpen.GetPathName(),
				  CFile::modeCreate|CFile::modeWrite);
		
		    CArchive caBoard(&BoardFile,CArchive::store);
            for(int y=0; y<10; y++)
			{
				for(int x=0; x<10; x++)
				{
					caBoard << (long)m_nBoard[y][x];
				}
			}

			caBoard << m_bTurn;

			caBoard.Close();
			BoardFile.Close();
		}
	}
}

void COMokDlg::OnExit() 
{
	// TODO: Add your command handler code here
	OnOK();
}

void COMokDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
