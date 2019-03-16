// RealMemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RealMem.h"
#include "RealMemDlg.h"

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
// CRealMemDlg dialog

CRealMemDlg::CRealMemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRealMemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRealMemDlg)
	m_strEdit1 = _T("");
	m_strEdit2 = _T("");
	m_strEdit3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	
}

void CRealMemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRealMemDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
	DDX_Text(pDX, IDC_EDIT2, m_strEdit2);
	DDX_Text(pDX, IDC_EDIT3, m_strEdit3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRealMemDlg, CDialog)
	//{{AFX_MSG_MAP(CRealMemDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRealMemDlg message handlers

BOOL CRealMemDlg::OnInitDialog()
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
    SetTimer(1,100,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRealMemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRealMemDlg::OnPaint() 
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
HCURSOR CRealMemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRealMemDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	MemoryInfo();
	CDialog::OnTimer(nIDEvent);

}

void CRealMemDlg::MemoryInfo()
{
	MEMORYSTATUS MemInfo;
	MemInfo.dwLength=sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(&MemInfo);

    int nMemoryLoad=0;
	nMemoryLoad=MemInfo.dwMemoryLoad;
	char szMem[10]="";

	CClientDC dc(this);

	CPen MyPenBlue(PS_SOLID,1,RGB(0,0,255));
	CBrush MyBrushBlue(RGB(0,0,255));
		
	CPen *pOldPenBlue=dc.SelectObject(&MyPenBlue);
	CBrush *pOldBrushBlue=dc.SelectObject(&MyBrushBlue);

	dc.Rectangle(nMemoryLoad+20,50,120,70);

	dc.SelectObject(pOldPenBlue);
	dc.SelectObject(pOldBrushBlue);

	CPen MyPenRed(PS_SOLID,1,RGB(255,0,0));
	CBrush MyBrushRed(RGB(255,0,0));

	CPen *pOldPenRed=dc.SelectObject(&MyPenRed);
	CBrush *pOldBrushRed=dc.SelectObject(&MyBrushRed);

	dc.Rectangle(20,50,nMemoryLoad+20,70);

	dc.SelectObject(pOldPenRed);
	dc.SelectObject(pOldBrushRed);
	
	sprintf(szMem,"%d%%",nMemoryLoad);
	dc.SetTextColor(RGB(255,255,255));
	dc.SetBkMode(TRANSPARENT);
	dc.TextOut(60,52,szMem);
	dc.SetTextColor(RGB(0,0,0));
	dc.TextOut(10,32,"메모리 사용률");

	CString AllMemory;
	AllMemory.Format("%d",MemInfo.dwTotalPhys);
	m_strEdit1=ComMa(AllMemory);
	
	CString UserMemory;
	UserMemory.Format("%d",MemInfo.dwTotalPhys-MemInfo.dwAvailPhys);
	m_strEdit2=ComMa(UserMemory);

	CString FreeMemory;
	FreeMemory.Format("%d",MemInfo.dwAvailPhys);
	m_strEdit3=ComMa(FreeMemory);

	UpdateData(FALSE);

}

CString CRealMemDlg::ComMa(CString strNum)
{
	CString strTemp;
	int a=0,k=0;;
	
	a=strNum.GetLength();
	k=a;
	
	for(int c=1; c<=a; c++)
	{
		k--;
		strTemp+=strNum.GetAt(k);
	}
	
	int o=0;
	a=a/3;
	for(int b=1;b<=a;b++)
	{
		if(b==1)
			strTemp.Insert(b*3,",");
		else
		{
			o++;
			strTemp.Insert(b*3+o,",");
		}
		
	}
	
	CString strTemp2;
	int z=0,u=0;
	z=strTemp.GetLength();
	u=z;
	for(int y=1; y<=z; y++)
	{
		u--;
		strTemp2+=strTemp.GetAt(u);
	}
	
	if(0==strTemp2.Find(",",0))
		strTemp2.Delete(0,1);
	
	return strTemp2;

}

void CRealMemDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CRealMemDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	KillTimer(1);
}
