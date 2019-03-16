// ProcValueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProcValue.h"
#include "ProcValueDlg.h"

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
// CProcValueDlg dialog

CProcValueDlg::CProcValueDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProcValueDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcValueDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProcValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcValueDlg)
	DDX_Control(pDX, IDC_LIST_VALUE, m_ListValue);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProcValueDlg, CDialog)
	//{{AFX_MSG_MAP(CProcValueDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_PRINT, OnButtPrint)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcValueDlg message handlers

BOOL CProcValueDlg::OnInitDialog()
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
	char *szList[2]={"Variable","Value"};
	int nWid[2]={150,1400};

	LVCOLUMN Col;
	
	Col.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;
	Col.fmt=LVCFMT_LEFT;

	for(int a=0; a<=1; a++)
	{
		Col.pszText=szList[a];
		Col.iSubItem=a;
		Col.cx=nWid[a];
		m_ListValue.InsertColumn(a,&Col);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProcValueDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProcValueDlg::OnPaint() 
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
HCURSOR CProcValueDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CProcValueDlg::OnButtPrint() 
{
	// TODO: Add your control notification handler code here
	char szBuff[255]="";
	int nCount=0;
	LPSTR lpVariable;
	LPSTR lpValue;

	lpVariable=GetEnvironmentStrings();

	LVITEM Item;
	Item.mask=LVIF_TEXT;

	while(*lpVariable)
	{
		lpValue=strstr(lpVariable+1,"=");

		if(lpValue)
		{
			*lpValue='\0';
			lpValue++;
		}

		Item.iItem=nCount;
		Item.iSubItem=0;
		Item.pszText=lpVariable;
		m_ListValue.InsertItem(&Item);

		Item.iSubItem=1;
		Item.pszText=lpValue;
		m_ListValue.SetItem(&Item);

		lpVariable=lpVariable+strlen(lpVariable)+1+strlen(lpValue)+1;
	}
	
}

void CProcValueDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
