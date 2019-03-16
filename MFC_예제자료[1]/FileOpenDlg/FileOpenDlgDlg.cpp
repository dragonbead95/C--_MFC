// FileOpenDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileOpenDlg.h"
#include "FileOpenDlgDlg.h"

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
// CFileOpenDlgDlg dialog

CFileOpenDlgDlg::CFileOpenDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileOpenDlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileOpenDlgDlg)
	m_strEdit1 = _T("");
	m_strEdit2 = _T("");
	m_strEdit3 = _T("");
	m_strEdit4 = _T("");
	m_strEdit5 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileOpenDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileOpenDlgDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
	DDX_Text(pDX, IDC_EDIT2, m_strEdit2);
	DDX_Text(pDX, IDC_EDIT3, m_strEdit3);
	DDX_Text(pDX, IDC_EDIT4, m_strEdit4);
	DDX_Text(pDX, IDC_EDIT5, m_strEdit5);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileOpenDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CFileOpenDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_OPEN, OnButtOpen)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileOpenDlgDlg message handlers

BOOL CFileOpenDlgDlg::OnInitDialog()
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

void CFileOpenDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileOpenDlgDlg::OnPaint() 
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
HCURSOR CFileOpenDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileOpenDlgDlg::OnButtOpen() 
{
	// TODO: Add your control notification handler code here

	BOOL bTrue=FALSE;

	CFileDialog dlgFileOpen(TRUE,"TXT",NULL,
		            OFN_FILEMUSTEXIST,
					"메모장(*.txt)|*.txt|모든파일(*.*)|*.*||",
					NULL);

	if(dlgFileOpen.DoModal()==IDOK)
	{
		m_strEdit1=dlgFileOpen.GetPathName();
		m_strEdit2=dlgFileOpen.GetFileName();
		m_strEdit3=dlgFileOpen.GetFileTitle();
		m_strEdit4=dlgFileOpen.GetFileExt();

		bTrue=dlgFileOpen.GetReadOnlyPref();
		if(bTrue==TRUE)
			m_strEdit5="읽기 전용 파일입니다.";
		else
			m_strEdit5="읽기 전용 파일이 아닙니다.";

		UpdateData(FALSE);
	}
	else
		MessageBox("선택을 잘못했습니다.","알림",NULL);

}

void CFileOpenDlgDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
