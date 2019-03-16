// ListCtlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListCtl.h"
#include "ListCtlDlg.h"

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
// CListCtlDlg dialog

CListCtlDlg::CListCtlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListCtlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListCtlDlg)
	m_strName = _T("");
	m_strMail = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListCtlDlg)
	DDX_Control(pDX, IDC_LIST_CTL, m_ListC);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_MAIL, m_strMail);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListCtlDlg, CDialog)
	//{{AFX_MSG_MAP(CListCtlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_ADD, OnButtAdd)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTL, OnDblclkListCtl)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListCtlDlg message handlers

BOOL CListCtlDlg::OnInitDialog()
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
	char *szText[2]={"¿Ã∏ß","E-MAIL"};
	int nWid[2]={65,180};

	LVCOLUMN lCol;

	lCol.mask=LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH;
	lCol.fmt=LVCFMT_LEFT;

	for(int i=0 ; i<2; i++)
	{

		lCol.pszText=szText[i];
		lCol.iSubItem=i;
		lCol.cx=nWid[i];
		m_ListC.InsertColumn(i,&lCol);
	}

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListCtlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListCtlDlg::OnPaint() 
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
HCURSOR CListCtlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CListCtlDlg::OnButtAdd() 
{
	// TODO: Add your control notification handler code here
	char szText[50]="";
	int nIndex=0;
	
	UpdateData(TRUE);
	
	LVITEM lItem;

	lItem.mask=LVIF_TEXT;
	lItem.iItem=nIndex;

	lItem.iSubItem=0;
	sprintf(szText,"%s",m_strName);
	lItem.pszText=(LPSTR)szText;
	m_ListC.InsertItem(&lItem);

	lItem.iSubItem=1;
	sprintf(szText,"%s",m_strMail);
	lItem.pszText=(LPSTR)szText;
	m_ListC.SetItem(&lItem);

	m_strName="";
	m_strMail="";

	nIndex++;
	UpdateData(FALSE);
}

void CListCtlDlg::OnDblclkListCtl(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nIndex=0;
	nIndex=m_ListC.GetItemCount();

	m_ListC.DeleteItem(nIndex);
	*pResult = 0;
}

void CListCtlDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
