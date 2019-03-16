// DiskInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DiskInfo.h"
#include "DiskInfoDlg.h"

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
// CDiskInfoDlg dialog

CDiskInfoDlg::CDiskInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDiskInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiskInfoDlg)
	m_strAlldisk = _T("");
	m_strFat = _T("");
	m_strFreedisk = _T("");
	m_strLabel = _T("");
	m_strType = _T("");
	m_strUsedisk = _T("");
	m_strSeldrv = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDiskInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiskInfoDlg)
	DDX_Control(pDX, IDC_COMBO_DRIVER, m_ctlDriver);
	DDX_Text(pDX, IDC_STATIC_ALLDISK, m_strAlldisk);
	DDX_Text(pDX, IDC_STATIC_FAT, m_strFat);
	DDX_Text(pDX, IDC_STATIC_FREEDISK, m_strFreedisk);
	DDX_Text(pDX, IDC_STATIC_LABEL, m_strLabel);
	DDX_Text(pDX, IDC_STATIC_TYPE, m_strType);
	DDX_Text(pDX, IDC_STATIC_USEDISK, m_strUsedisk);
	DDX_Text(pDX, IDC_STATIC_SELDRV, m_strSeldrv);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDiskInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CDiskInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_DRIVER, OnSelchangeComboDriver)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiskInfoDlg message handlers

BOOL CDiskInfoDlg::OnInitDialog()
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
	// 드라이브 구하기
	CString strTemp;
	char szDriver[10]="";
	m_dDriver=GetLogicalDrives();
	
	for(int a=0; a<=10; a++)
	{
		if(m_dDriver & (1<<a))
		{
			sprintf(szDriver,"%c",a+'A');
			strTemp.Format("%s 디스크",szDriver);
			m_ctlDriver.AddString(strTemp);
		}
	}
	m_strSeldrv="선택된 디스크:";
	m_strType="디스크 타입:";
	m_strLabel="디스크 이름:";
	m_strFat="파일 시스템:";
	m_strAlldisk="전체 용량:";
	m_strUsedisk="사용 용량:";
	m_strFreedisk="남은 용량:";
	

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDiskInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDiskInfoDlg::OnPaint() 
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
HCURSOR CDiskInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDiskInfoDlg::OnSelchangeComboDriver() 
{
	// TODO: Add your control notification handler code here
	int nCursel;
	char szDrv[10]="";

	nCursel=m_ctlDriver.GetCurSel();

	if(nCursel!=0)
		nCursel+=1;

	if(m_dDriver & (1<<nCursel))
	{
		sprintf(szDrv,"%c",nCursel+'A');
		m_strSeldrv.Format("선택된 디스크: %s 디스크",szDrv);
		DiskInfo(szDrv);
	}
	UpdateData(FALSE);
}

void CDiskInfoDlg::DiskInfo(char *szDrv)
{
	// 디스크 타입
	int nType=0;
	strcat(szDrv,":\\");
	nType=GetDriveType(szDrv);
	switch(nType)
	{
	case 0:
		m_strType="디스크 타입: 알수 없는 디스크";
		break;
	case 1:
		m_strType="디스크 타입: 존재하지 않는 디스크";
		break;
	case DRIVE_CDROM:
		m_strType="디스크 타입: CD-ROM";
		break;
	case DRIVE_FIXED:
		m_strType="디스크 타입: 하드 디스크";
		break;
	case DRIVE_RAMDISK:
		m_strType="디스크 타입: 램 디스크";
		break;
	case DRIVE_REMOTE:
		m_strType="디스크 타입: 네트워크에 연결된 디스크";
		break;
	case DRIVE_REMOVABLE:
		m_strType="디스크 타입: 플로피 디스크";
		break;
	}

	// 디스크 이름(Label)과 파일 시스템 구하기
	char szLabel[30]="";
	char szFat[30]="";

	GetVolumeInformation(szDrv,szLabel,sizeof(szLabel)-1,
		                 NULL,
						 NULL,
						 NULL,
						 szFat,sizeof(szFat)-1);
	m_strLabel.Format("디스크 이름: %s",szLabel);
	m_strFat.Format("파일 시스템: %s",szFat);

	// 디스크 용량 구하기
	ULARGE_INTEGER uTotal;
    ULARGE_INTEGER uFree;
	
	GetDiskFreeSpaceEx(szDrv, NULL, &uTotal, &uFree);

	// 전체 용량 
	CString strTemp;
	strTemp.Format("%I64u",uTotal);
	m_strAlldisk="전체 용량: "+ComMa(strTemp)+"Byte";

    // 남은 용량 
	CString strTemp2;
	strTemp2.Format("%I64u",uFree);
	m_strFreedisk="남은 용량: "+ComMa(strTemp2)+"Byte";

	// 사용 용량
	int nTotal=0,nFree=0,nUse=0;
	CString strTemp3;

	nTotal=atoi(strTemp);
	nFree=atoi(strTemp2);
	nUse=nTotal-nFree;

	strTemp3.Format("%d",nUse);
	m_strUsedisk="사용 용량: "+ComMa(strTemp3)+"Byte";

	UpdateData(FALSE);
}

CString CDiskInfoDlg::ComMa(CString strNum)
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

void CDiskInfoDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
