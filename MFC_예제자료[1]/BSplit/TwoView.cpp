// TwoView.cpp : implementation file
//

#include "stdafx.h"
#include "BSplit.h"
#include "TwoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTwoView

IMPLEMENT_DYNCREATE(CTwoView, CView)

CTwoView::CTwoView()
{
}

CTwoView::~CTwoView()
{
}


BEGIN_MESSAGE_MAP(CTwoView, CView)
	//{{AFX_MSG_MAP(CTwoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTwoView drawing

void CTwoView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	pDC->SetTextColor(RGB(0,255,0));
	pDC->TextOut(10,10,"필자입니다.");
}

/////////////////////////////////////////////////////////////////////////////
// CTwoView diagnostics

#ifdef _DEBUG
void CTwoView::AssertValid() const
{
	CView::AssertValid();
}

void CTwoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTwoView message handlers
