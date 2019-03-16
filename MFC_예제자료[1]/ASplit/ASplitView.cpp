// ASplitView.cpp : implementation of the CASplitView class
//

#include "stdafx.h"
#include "ASplit.h"

#include "ASplitDoc.h"
#include "ASplitView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CASplitView

IMPLEMENT_DYNCREATE(CASplitView, CView)

BEGIN_MESSAGE_MAP(CASplitView, CView)
	//{{AFX_MSG_MAP(CASplitView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CASplitView construction/destruction

CASplitView::CASplitView()
{
	// TODO: add construction code here

}

CASplitView::~CASplitView()
{
}

BOOL CASplitView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CASplitView drawing

void CASplitView::OnDraw(CDC* pDC)
{
	CASplitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	pDC->TextOut(50,50,"MFC Programming");
}

/////////////////////////////////////////////////////////////////////////////
// CASplitView printing

BOOL CASplitView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CASplitView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CASplitView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CASplitView diagnostics

#ifdef _DEBUG
void CASplitView::AssertValid() const
{
	CView::AssertValid();
}

void CASplitView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CASplitDoc* CASplitView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CASplitDoc)));
	return (CASplitDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CASplitView message handlers
