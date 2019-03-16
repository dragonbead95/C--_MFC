// BSplitDoc.h : interface of the CBSplitDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BSPLITDOC_H__6509C2D3_D4E2_4B42_A5A7_1E8602945BF7__INCLUDED_)
#define AFX_BSPLITDOC_H__6509C2D3_D4E2_4B42_A5A7_1E8602945BF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBSplitDoc : public CDocument
{
protected: // create from serialization only
	CBSplitDoc();
	DECLARE_DYNCREATE(CBSplitDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBSplitDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBSplitDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBSplitDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BSPLITDOC_H__6509C2D3_D4E2_4B42_A5A7_1E8602945BF7__INCLUDED_)
