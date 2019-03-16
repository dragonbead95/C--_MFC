// CalenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calen.h"
#include "CalenDlg.h"

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
// CCalenDlg dialog

CCalenDlg::CCalenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalenDlg)
	m_nYear = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalenDlg)
	DDX_Control(pDX, IDC_COMBO_MONTH, m_ctlMonth);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_nYear);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalenDlg, CDialog)
	//{{AFX_MSG_MAP(CCalenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	ON_CBN_SELCHANGE(IDC_COMBO_MONTH, OnSelchangeComboMonth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalenDlg message handlers

BOOL CCalenDlg::OnInitDialog()
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
	COleDateTime mm;
	mm = COleDateTime::GetCurrentTime();
	m_nYear=mm.GetYear();

	m_nMonth=mm.GetMonth();
	m_ctlMonth.SetCurSel(m_nMonth-1);


	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalenDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalenDlg::OnPaint() 
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
	BackGround();
	DatePrint();

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalenDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nSBCode)
	{
	case SB_LINELEFT:
		if(m_nYear<2099)
		{
			m_nYear++;
		}
		break;
	case SB_LINERIGHT:
		if(m_nYear>1980)
		{
			m_nYear--;
		}
		break;
	}
	InvalidateRect(NULL,FALSE);
	UpdateData(FALSE);
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CCalenDlg::BackGround()
{
	CClientDC dc(this);
	dc.Rectangle(12,35,155,200);
	dc.SetTextColor(RGB(0,255,0));
	dc.TextOut(37,40,"간단한 달력");
	dc.SetTextColor(RGB(0,0,0));
	dc.TextOut(14,57,"일 월 화 수 목 금 토");
}

void CCalenDlg::DatePrint()
{
	CClientDC dc(this);
	COleDateTime mm;
	mm = COleDateTime::GetCurrentTime();
	int w=0,b=0,c=0,t=0;
	char szText[3]="";
	
	t=mm.GetDay();
	
	mm.SetDate(m_nYear,m_nMonth,1);
	w=mm.GetDayOfWeek();

	for(int a=1; a<=6; a++)
	{
		for(b=w; b<=7; b++)
		{
			w=1;
			c=c+1;
			mm.SetDate(m_nYear,m_nMonth,c);
			if(mm.GetDay()!=-1)
			{
				if(c==t)
					dc.SetTextColor(RGB(0,0,255));
				else if(mm.GetDayOfWeek()==1)
					dc.SetTextColor(RGB(255,0,0));
				else
					dc.SetTextColor(RGB(0,0,0));

				sprintf(szText,"%d",c);
			    dc.TextOut(b*19,55+a*20,szText);
			}
		}
	}
}

void CCalenDlg::OnSelchangeComboMonth() 
{
	// TODO: Add your control notification handler code here
	m_nMonth=m_ctlMonth.GetCurSel()+1;
	InvalidateRect(NULL,FALSE);
}

void CCalenDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
