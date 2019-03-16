// BSplitDoc.cpp : implementation of the CBSplitDoc class
//

#include "stdafx.h"
#include "BSplit.h"

#include "BSplitDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBSplitDoc

IMPLEMENT_DYNCREATE(CBSplitDoc, CDocument)

BEGIN_MESSAGE_MAP(CBSplitDoc, CDocument)
	//{{AFX_MSG_MAP(CBSplitDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBSplitDoc construction/destruction

CBSplitDoc::CBSplitDoc()
{
	// TODO: add one-time construction code here

}

CBSplitDoc::~CBSplitDoc()
{
}

BOOL CBSplitDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBSplitDoc serialization

void CBSplitDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBSplitDoc diagnostics

#ifdef _DEBUG
void CBSplitDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBSplitDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBSplitDoc commands
