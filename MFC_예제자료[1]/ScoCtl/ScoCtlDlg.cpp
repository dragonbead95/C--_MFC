// ScoCtlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScoCtl.h"
#include "ScoCtlDlg.h"

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
// CScoCtlDlg dialog

CScoCtlDlg::CScoCtlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CScoCtlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScoCtlDlg)
	m_iEdit = 0;
	m_iEdit2 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CScoCtlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScoCtlDlg)
	DDX_Control(pDX, IDC_SCR_HORI, m_scrHori);
	DDX_Control(pDX, IDC_SCR_VERT, m_scrVert);
	DDX_Text(pDX, IDC_EDIT_NUM, m_iEdit);
	DDX_Text(pDX, IDC_EDIT_NUM2, m_iEdit2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CScoCtlDlg, CDialog)
	//{{AFX_MSG_MAP(CScoCtlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScoCtlDlg message handlers

BOOL CScoCtlDlg::OnInitDialog()
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
	m_iRed=0;
	m_iGreen=0;

	m_scrVert.SetScrollRange(0,255);
	m_scrVert.SetScrollPos(0);
	
	m_scrHori.SetScrollRange(0,255);
	m_scrHori.SetScrollPos(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CScoCtlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CScoCtlDlg::OnPaint() 
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
	CClientDC dc(this);
	CBrush br;
	br.CreateSolidBrush(RGB(m_iRed,m_iGreen,0));

	CBrush *Oldbr=dc.SelectObject(&br);

	dc.Rectangle(30,30,100,100);

	dc.SelectObject(br);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CScoCtlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CScoCtlDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nSBCode)
	{
	case SB_LINELEFT:
		m_iRed--;
		break;
	case SB_LINERIGHT:
		m_iRed++;
		break;
	case SB_PAGELEFT:
		m_iRed--;		
		break;
	case SB_PAGERIGHT:
		m_iRed++;		
		break;
	case SB_THUMBPOSITION:
		m_iRed=nPos;			
		break;
	}
	m_iEdit=m_scrVert.GetScrollPos();
	m_scrVert.SetScrollPos(m_iRed);
	Invalidate(FALSE);
	UpdateData(FALSE);
	
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CScoCtlDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nSBCode)
	{
	case SB_LINELEFT:
		m_iGreen--;
		break;
	case SB_LINERIGHT:
		m_iGreen++;
		break;
	/*case SB_PAGELEFT:
		m_iGreen--;		
		break;
	case SB_PAGERIGHT:
		m_iGreen++;		
		break;
	case SB_THUMBPOSITION:
		m_iGreen=nPos;			
		break;*/
	}
	m_iEdit2=m_scrHori.GetScrollPos();
	m_scrHori.SetScrollPos(m_iGreen);
	Invalidate(FALSE);
	UpdateData(FALSE);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CScoCtlDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
