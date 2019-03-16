// SystemInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SystemInfo.h"
#include "SystemInfoDlg.h"

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
// CSystemInfoDlg dialog

CSystemInfoDlg::CSystemInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSystemInfoDlg)
	m_strBooting = _T("");
	m_strMusButt = _T("");
	m_strVga = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSystemInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSystemInfoDlg)
	DDX_Text(pDX, IDC_EDIT_BOOTING, m_strBooting);
	DDX_Text(pDX, IDC_EDIT_MUSBUTT, m_strMusButt);
	DDX_Text(pDX, IDC_EDIT_VGA, m_strVga);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSystemInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CSystemInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_PRINT, OnButtPrint)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemInfoDlg message handlers

BOOL CSystemInfoDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSystemInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSystemInfoDlg::OnPaint() 
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
HCURSOR CSystemInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSystemInfoDlg::OnButtPrint() 
{
	// TODO: Add your control notification handler code here

	// 마우스 버튼의 수
	int nMusButt=0;
	nMusButt=GetSystemMetrics(SM_CMOUSEBUTTONS);
	if(nMusButt>0)
		m_strMusButt.Format("%d개",nMusButt);
	else
		m_strMusButt="마우스가 설치되어 있지 않음";

	// 부팅 상태
	int nBoot=0;
	nBoot=GetSystemMetrics(SM_CLEANBOOT);
	switch(nBoot)
	{
	case 0:
		m_strBooting="정상부팅";
		break;
	case 1:
		m_strBooting="안전모드 부팅";
		break;
	case 2:
		m_strBooting="네트워크 부팅";
		break;
	}

	// 해상도
	m_strVga.Format("%d * %d",GetSystemMetrics(SM_CXSCREEN),
		                      GetSystemMetrics(SM_CYSCREEN));  
	
	UpdateData(FALSE);

}

void CSystemInfoDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
