// FontDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FontDlg.h"
#include "FontDlgDlg.h"

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
// CFontDlgDlg dialog

CFontDlgDlg::CFontDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFontDlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontDlgDlg)
	m_strEdit1 = _T("");
	m_strEdit2 = _T("");
	m_strEdit3 = _T("");
	m_strEdit4 = _T("");
	m_strEdit6 = _T("");
	m_strEdit7 = _T("");
	m_strEdit8 = _T("");
	m_strEdit5 = _T("");
	m_strEdit9 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFontDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontDlgDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strEdit1);
	DDX_Text(pDX, IDC_EDIT2, m_strEdit2);
	DDX_Text(pDX, IDC_EDIT3, m_strEdit3);
	DDX_Text(pDX, IDC_EDIT4, m_strEdit4);
	DDX_Text(pDX, IDC_EDIT6, m_strEdit6);
	DDX_Text(pDX, IDC_EDIT7, m_strEdit7);
	DDX_Text(pDX, IDC_EDIT8, m_strEdit8);
	DDX_Text(pDX, IDC_EDIT5, m_strEdit5);
	DDX_Text(pDX, IDC_EDIT9, m_strEdit9);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFontDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CFontDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_OPEN, OnButtOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontDlgDlg message handlers

BOOL CFontDlgDlg::OnInitDialog()
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

void CFontDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFontDlgDlg::OnPaint() 
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
HCURSOR CFontDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFontDlgDlg::OnButtOpen() 
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	CFontDialog Fontdlg;
	COLORREF color;

	CFont MyFont, *pOldFont;
	

	if(Fontdlg.DoModal()==IDOK)
	{
		 // 폰트의 페이스
	     m_strEdit1=Fontdlg.GetFaceName();

	     // 폰트의 스타일
	     m_strEdit2=Fontdlg.GetStyleName();

	     // 폰트의 크기
	     m_strEdit3.Format("%d",Fontdlg.GetSize()/10);

	     // 색상
	     color=Fontdlg.GetColor();

	
	     m_strEdit4.Format("Red: %d, Green: %d, Blue: %d",
		                    GetRValue(color),
	                        GetGValue(color),
				            GetBValue(color));

	     // 두께
	     m_strEdit5.Format("%d",Fontdlg.GetWeight());

	     // 취소선
	     if(Fontdlg.IsStrikeOut())
		     m_strEdit6="예";
	     else
		     m_strEdit6="아니오";

	     // 진하게
	     if(Fontdlg.IsBold())
		     m_strEdit7="예";
	     else
		     m_strEdit7="아니오";

	     // 이탤릭(기울임꼴)
	     if(Fontdlg.IsItalic())
		     m_strEdit8="예";
	     else
		     m_strEdit8="아니오";

	     // 밑줄
	     if(Fontdlg.IsUnderline())
		     m_strEdit9="예";
	     else
		     m_strEdit9="아니오";

		 // 폰트 생성
		 MyFont.CreateFont(Fontdlg.GetSize()/10,
			              0,
						  0,
						  0,
						  Fontdlg.GetWeight(),
						  Fontdlg.IsItalic(),
						  Fontdlg.IsUnderline(),
						  Fontdlg.IsStrikeOut(),
						  ANSI_CHARSET,
		                  OUT_DEFAULT_PRECIS,
					      CLIP_DEFAULT_PRECIS,
					      DEFAULT_QUALITY,
					      VARIABLE_PITCH|FF_SWISS,
					      Fontdlg.GetFaceName());
	     pOldFont=dc.SelectObject(&MyFont);
	     dc.SetTextColor(color);
	     dc.TextOut(10,30,"안녕하세요 필자입니다.");
	     dc.SelectObject(pOldFont);

	     UpdateData(FALSE);
	}
}
