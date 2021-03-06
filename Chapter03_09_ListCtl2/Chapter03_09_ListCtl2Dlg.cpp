
// Chapter03_09_ListCtl2Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Chapter03_09_ListCtl2.h"
#include "Chapter03_09_ListCtl2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChapter0309ListCtl2Dlg 대화 상자



CChapter0309ListCtl2Dlg::CChapter0309ListCtl2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHAPTER03_09_LISTCTL2_DIALOG, pParent)
	, m_strName(_T(""))
	, m_strMail(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChapter0309ListCtl2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CTL, m_ListC);
	//  DDX_Control(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_MAIL, m_strMail);
}

BEGIN_MESSAGE_MAP(CChapter0309ListCtl2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_ADD, &CChapter0309ListCtl2Dlg::OnClickedButtAdd)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CChapter0309ListCtl2Dlg::OnClickedButtExit)
END_MESSAGE_MAP()


// CChapter0309ListCtl2Dlg 메시지 처리기

BOOL CChapter0309ListCtl2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
		char *szText[2] = { "이름","E-MAIL" };	//칼럼의 이름을 사용할 변수를 선언
	int nWid[2] = { 65,180 };	// 컬럼의 각각의 넓이를 지정할 변수 선언

	LV_COLUMN ICol;	// 칼럼을 정의할 구조체 선언

	ICol.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;	// 확장할 플래그들을 지정
	ICol.fmt = LVCFMT_LEFT;	// 칼럼을 왼쪽으로 정렬

	// 컬럼이 하나면 괜찮은데 이 프로그램에서는 하나 이상의 칼럼을 사용하므로 for문을 이용하였다.
	for (int i = 0;i < 2;i++)
	{
		ICol.pszText = szText[i];	// 컬럼의 이름을 지정
		ICol.iSubItem = i;	// 서브아이템의 넘버를 지정, 즉, 칼럼의 인덱스를 지정한다.
		ICol.cx = nWid[i];	// 각 컬럼의 넓이를 지정
		m_ListC.InsertColumn(i, &ICol);	//리스트 컨트롤에 컬럼을 추가한다.
	}
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChapter0309ListCtl2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChapter0309ListCtl2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChapter0309ListCtl2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChapter0309ListCtl2Dlg::OnClickedButtAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char szText[50] = "";	//문자열을 저장할 변수
	int nIndex = 0;	// 목록의 인덱스를 저장할 변수

	// 이 구조체를 이용하여 목록에 대한 정보를 작성한다.
	UpdateData(TRUE);
	LVITEM lItem;

	// 목록의 인덱스를 지정한다. 즉 각각의 번호를 준다.
	lItem.mask = LVIF_TEXT;
	lItem.iItem = nIndex;

	lItem.iSubItem = 0;	// 최상의 목록이므로 0을 준다.
	sprintf_s(szText, "%s", m_strName);	// m_strName변수가 CString형이라 szText변수로 바로 값을 전송할 수가 없다. 그러므로 sprintf()함수를 이용하여 전송한다.
	lItem.pszText = (LPSTR)szText;	// 목록의 내용을 지정
	m_ListC.InsertItem(&lItem);	// 최상의 목록일때만 InsertItem()함수를 사용한다.

	lItem.iSubItem = 1;	// 하위 목록
	sprintf_s(szText, "%s", m_strMail);
	lItem.pszText = (LPSTR)szText;
	m_ListC.SetItem(&lItem);	//최상위 목록이 아닌 하위 목록부터는 SetItem()함수를 사용한다.

	m_strName = "";
	m_strMail = "";
	nIndex++;
	//새로운 목록을 추가하기 위해 1값을 올린다.
	UpdateData(FALSE);
	// 변수에 있는 값을 리스트 컨트롤로 갱신한다.
}


void CChapter0309ListCtl2Dlg::OnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
