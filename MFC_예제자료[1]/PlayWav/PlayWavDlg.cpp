// PlayWavDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlayWav.h"
#include "PlayWavDlg.h"

#include "mmsystem.h"

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
// CPlayWavDlg dialog

CPlayWavDlg::CPlayWavDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayWavDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayWavDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlayWavDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayWavDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPlayWavDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayWavDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_OPEN, OnButtOpen)
	ON_BN_CLICKED(IDC_BUTT_PLAY, OnButtPlay)
	ON_BN_CLICKED(IDC_BUTT_FIRST, OnButtFirst)
	ON_BN_CLICKED(IDC_BUTT_STOP, OnButtStop)
	ON_BN_CLICKED(IDC_BUTT_PAUSE, OnButtPause)
	ON_BN_CLICKED(IDC_BUTT_RESUME, OnButtResume)
	ON_BN_CLICKED(IDC_BUTT_EXIT, OnButtExit)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayWavDlg message handlers

BOOL CPlayWavDlg::OnInitDialog()
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

void CPlayWavDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPlayWavDlg::OnPaint() 
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
HCURSOR CPlayWavDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPlayWavDlg::OnButtOpen() 
{
	// TODO: Add your control notification handler code here
	MCI_OPEN_PARMS mOpen;
	MCIERROR mErr;

	mOpen.lpstrDeviceType="waveaudio";
	mOpen.lpstrElementName="c:\\windows\\media\\TADA.WAV";

	mErr=mciSendCommand(NULL,MCI_OPEN,
		               MCI_OPEN_TYPE|MCI_OPEN_ELEMENT,
					   (DWORD)&mOpen);

	if(mErr)
	{
		MessageBox("MCI 장치를 열지 못했음","알림",NULL);
		return;
	}
	else
		m_dwID=mOpen.wDeviceID;

	
}

void CPlayWavDlg::OnButtPlay() 
{
	// TODO: Add your control notification handler code here
	MCI_PLAY_PARMS mPlay;
	MCIERROR mErr;

	mPlay.dwCallback=(DWORD)m_hWnd;
	
	mErr=mciSendCommand(m_dwID,MCI_PLAY,NULL,(DWORD)&mPlay);

	if(mErr)
		MessageBox("플레이 에러","알림",NULL);
}

void CPlayWavDlg::OnButtFirst() 
{
	// TODO: Add your control notification handler code here
	MCI_SEEK_PARMS mSeek;
	MCIERROR mErr;

	mErr=mciSendCommand(m_dwID,MCI_SEEK,
		                MCI_SEEK_TO_START,
						(DWORD)&mSeek);
	
	if(mErr)
		MessageBox("처음으로 돌리지 못함","알림",NULL);
}

void CPlayWavDlg::OnButtStop() 
{
	// TODO: Add your control notification handler code here
	MCI_GENERIC_PARMS mGen;
	MCIERROR mErr;

	mErr=mciSendCommand(m_dwID,MCI_STOP,MCI_WAIT,(DWORD)&mGen);

	if(mErr)
		MessageBox("정지 못함","알림",NULL);

}

void CPlayWavDlg::OnButtPause() 
{
	// TODO: Add your control notification handler code here
	MCI_GENERIC_PARMS mGen;
	MCIERROR mErr;

	mErr=mciSendCommand(m_dwID,MCI_PAUSE,MCI_WAIT,(DWORD)&mGen);

	if(mErr)
		MessageBox("잠깐정지 못함","알림",NULL);

}

void CPlayWavDlg::OnButtResume() 
{
	// TODO: Add your control notification handler code here
	MCI_GENERIC_PARMS mGen;
	MCIERROR mErr;

	mErr=mciSendCommand(m_dwID,MCI_RESUME,MCI_WAIT,(DWORD)&mGen);

	if(mErr)
		MessageBox("다시PLAY 못함","알림",NULL);
}

void CPlayWavDlg::OnButtExit() 
{
	// TODO: Add your control notification handler code here
	MCI_GENERIC_PARMS mGen;
	MCIERROR mErr;

	mErr=mciSendCommand(m_dwID,MCI_CLOSE,MCI_WAIT,(DWORD)&mGen);

	if(mErr)
		MessageBox("종료 못함","알림",NULL);
	else 
		OnOK();
}

void CPlayWavDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	MCI_GENERIC_PARMS mGen;
	MCIERROR mErr;

	mErr=mciSendCommand(m_dwID,MCI_CLOSE,MCI_WAIT,(DWORD)&mGen);

}
