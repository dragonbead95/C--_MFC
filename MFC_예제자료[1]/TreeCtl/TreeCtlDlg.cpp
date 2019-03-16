// TreeCtlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TreeCtl.h"
#include "TreeCtlDlg.h"

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
// CTreeCtlDlg dialog

CTreeCtlDlg::CTreeCtlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeCtlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTreeCtlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeCtlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTreeCtlDlg)
	DDX_Control(pDX, IDC_TREE_CTL, m_ctlTree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTreeCtlDlg, CDialog)
	//{{AFX_MSG_MAP(CTreeCtlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_PRINT, OnButtPrint)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeCtlDlg message handlers

BOOL CTreeCtlDlg::OnInitDialog()
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

void CTreeCtlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTreeCtlDlg::OnPaint() 
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
HCURSOR CTreeCtlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTreeCtlDlg::OnButtPrint() 
{
	// TODO: Add your control notification handler code here
	TVINSERTSTRUCT tInsert;

	// 음식
	HTREEITEM hFood; 
	// 음식의 종류
	HTREEITEM hFoodSort;

	// 최상위 목록
	tInsert.hParent=0;
	tInsert.hInsertAfter=TVI_SORT;
	tInsert.item.mask=TVIF_TEXT;
	tInsert.item.pszText="음식";
	hFood=m_ctlTree.InsertItem(&tInsert);

	// 상위 목록
	tInsert.hParent=hFood;
	tInsert.item.pszText="매운음식";
	hFoodSort=m_ctlTree.InsertItem(&tInsert);

	// 최하위 목록
	tInsert.hParent=hFoodSort;
	tInsert.item.pszText="고추장";
	m_ctlTree.InsertItem(&tInsert);

	// 최하위 목록
	tInsert.hParent=hFoodSort;
	tInsert.item.pszText="김치볶음밥";
	m_ctlTree.InsertItem(&tInsert);

	// 최하위 목록
	tInsert.hParent=hFoodSort;
	tInsert.item.pszText="매운탕";
	m_ctlTree.InsertItem(&tInsert);

	// 상위 목록
	tInsert.hParent=hFood;
	tInsert.item.pszText="느끼한음식";
	hFoodSort=m_ctlTree.InsertItem(&tInsert);

	// 최하위 목록
	tInsert.hParent=hFoodSort;
	tInsert.item.pszText="돈까스";
	m_ctlTree.InsertItem(&tInsert);

	// 최하위 목록
	tInsert.hParent=hFoodSort;
	tInsert.item.pszText="오므라이스";
	m_ctlTree.InsertItem(&tInsert);

	// 최하위 목록
	tInsert.hParent=hFoodSort;
	tInsert.item.pszText="피자";
	m_ctlTree.InsertItem(&tInsert);


}

void CTreeCtlDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
