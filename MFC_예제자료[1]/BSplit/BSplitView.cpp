// BSplitView.cpp : implementation of the CBSplitView class
//

#include "stdafx.h"
#include "BSplit.h"

#include "BSplitDoc.h"
#include "BSplitView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBSplitView

IMPLEMENT_DYNCREATE(CBSplitView, CView)

BEGIN_MESSAGE_MAP(CBSplitView, CView)
	//{{AFX_MSG_MAP(CBSplitView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBSplitView construction/destruction

CBSplitView::CBSplitView()
{
	// TODO: add construction code here

}

CBSplitView::~CBSplitView()
{
}

BOOL CBSplitView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBSplitView drawing

void CBSplitView::OnDraw(CDC* pDC)
{
	CBSplitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->SetTextColor(RGB(255,0,0));
	pDC->TextOut(10,10,"¾È³çÇÏ¼¼¿ä?");
}

/////////////////////////////////////////////////////////////////////////////
// CBSplitView printing

BOOL CBSplitView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBSplitView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBSplitView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CBSplitView diagnostics

#ifdef _DEBUG
void CBSplitView::AssertValid() const
{
	CView::AssertValid();
}

void CBSplitView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBSplitDoc* CBSplitView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBSplitDoc)));
	return (CBSplitDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBSplitView message handlers
