// TimerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Timer.h"
#include "TimerDlg.h"

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
// CTimerDlg dialog

CTimerDlg::CTimerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTimerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimerDlg)
	m_nSec = 0;
	m_nMin = 0;
	m_nHour = 0;
	m_strSetTimer = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimerDlg)
	DDX_Text(pDX, IDC_EDIT_SEC, m_nSec);
	DDX_Text(pDX, IDC_EDIT_MIN, m_nMin);
	DDX_Text(pDX, IDC_EDIT_HOUR, m_nHour);
	DDX_Text(pDX, IDC_STATIC_SETTIMER, m_strSetTimer);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTimerDlg, CDialog)
	//{{AFX_MSG_MAP(CTimerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTT_APPLY, OnButtApply)
	ON_BN_CLICKED(IDC_BUTT_CANCEL, OnButtCancel)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimerDlg message handlers

BOOL CTimerDlg::OnInitDialog()
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
	// 타이머를 설치한다.
	SetTimer(10,100,NULL);

	m_strSetTimer="현재 시간이 설정되지 않았습니다.";

	GetDlgItem(IDC_BUTT_CANCEL)->EnableWindow(false);

	m_bApply=FALSE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTimerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTimerDlg::OnPaint() 
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
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTimerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CTimerDlg::OnButtApply() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_nHour!=0)
	{
		if((m_nHour>24)||(m_nMin>59)||(m_nSec>59))
		{
			m_strSetTimer="시간 설정이 잘못 되었습니다.";
		}
		else
		{
			m_bApply=TRUE;

			GetDlgItem(IDC_BUTT_APPLY)->EnableWindow(false);
	        GetDlgItem(IDC_BUTT_CANCEL)->EnableWindow(true);

		    GetDlgItem(IDC_EDIT_HOUR)->EnableWindow(false);
		    GetDlgItem(IDC_EDIT_MIN)->EnableWindow(false);
		    GetDlgItem(IDC_EDIT_SEC)->EnableWindow(false);

	        m_strSetTimer.Format("%d시 %d분 %d초에 종료",m_nHour,m_nMin,m_nSec);
		}
	}
	else
		m_strSetTimer="시간 설정이 잘못 되었습니다.";

	UpdateData(FALSE);
}

void CTimerDlg::OnButtCancel() 
{
	// TODO: Add your control notification handler code here
	m_bApply=FALSE;
	GetDlgItem(IDC_BUTT_APPLY)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTT_CANCEL)->EnableWindow(FALSE);

	GetDlgItem(IDC_EDIT_HOUR)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_MIN)->EnableWindow(true);
	GetDlgItem(IDC_EDIT_SEC)->EnableWindow(true);

	m_strSetTimer="현재 시간이 설정되지 않았습니다.";
	UpdateData(FALSE);
}

void CTimerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	// 현재 시간을 출력

	COleDateTime mm;
	mm = COleDateTime::GetCurrentTime();
	CString strTemp;
	strTemp = mm.Format("%H:%M:%S");
	GetDlgItem(IDC_STATIC_TIME)->SetWindowText(strTemp);
	

	if(m_bApply==TRUE)
	{
		if((m_nHour==mm.GetHour()) && (m_nMin==mm.GetMinute()) && (m_nSec==mm.GetSecond()))
		{
			m_bApply=FALSE;
			m_strSetTimer="윈도우즈를 종료합니다.";
			ExitWindowsEx(EWX_SHUTDOWN,0);
		}
	}

	CDialog::OnTimer(nIDEvent);
}

void CTimerDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}


