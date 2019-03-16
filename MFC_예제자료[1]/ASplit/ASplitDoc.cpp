// ASplitDoc.cpp : implementation of the CASplitDoc class
//

#include "stdafx.h"
#include "ASplit.h"

#include "ASplitDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CASplitDoc

IMPLEMENT_DYNCREATE(CASplitDoc, CDocument)

BEGIN_MESSAGE_MAP(CASplitDoc, CDocument)
	//{{AFX_MSG_MAP(CASplitDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CASplitDoc construction/destruction

CASplitDoc::CASplitDoc()
{
	// TODO: add one-time construction code here

}

CASplitDoc::~CASplitDoc()
{
}

BOOL CASplitDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CASplitDoc serialization

void CASplitDoc::Serialize(CArchive& ar)
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
// CASplitDoc diagnostics

#ifdef _DEBUG
void CASplitDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CASplitDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CASplitDoc commands
