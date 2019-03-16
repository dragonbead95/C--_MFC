// FileSeriDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileSeri.h"
#include "FileSeriDlg.h"

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
// CFileSeriDlg dialog

CFileSeriDlg::CFileSeriDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileSeriDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileSeriDlg)
	m_strVar1 = _T("");
	m_strVar2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileSeriDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileSeriDlg)
	DDX_Text(pDX, IDC_EDIT_VAR1, m_strVar1);
	DDX_Text(pDX, IDC_EDIT_VAR2, m_strVar2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileSeriDlg, CDialog)
	//{{AFX_MSG_MAP(CFileSeriDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_WRITE, OnButtWrite)
	ON_BN_CLICKED(IDC_BUTT_READ, OnButtRead)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileSeriDlg message handlers

BOOL CFileSeriDlg::OnInitDialog()
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

void CFileSeriDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileSeriDlg::OnPaint() 
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
HCURSOR CFileSeriDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileSeriDlg::OnButtWrite() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CFile MyFile;
	MyFile.Open("C:\\Seri.txt",CFile::modeCreate|CFile::modeWrite);

	// 아카이브 개체를 저장으로 생성한다.
	CArchive ar(&MyFile,CArchive::store);

	// 변수의 값을 아카이브로 보낸다.
	ar << m_strVar1 << m_strVar2;

	m_strVar1="";
	m_strVar2="";
	UpdateData(FALSE);

	// 아카이브 닫기
	ar.Close();

	// 파일 닫기
	MyFile.Close();

}

void CFileSeriDlg::OnButtRead() 
{
	// TODO: Add your control notification handler code here
	CString strText1,strText2;
	CFile MyFile;
	MyFile.Open("C:\\Seri.txt",CFile::modeRead);

	// 아카이브 개체를 읽기로 생성한다.
	CArchive ar(&MyFile,CArchive::load);

	// 아카이브에 있는 값을 변수로 보낸다.
	ar >> strText1 >> strText2;

	// 변수 값을 출력한다.
	MessageBox(strText1+" "+strText2,"알림",NULL);

	// 아카이브 닫기
	ar.Close();

	// 파일 닫기
	MyFile.Close();
}

void CFileSeriDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
