// ASplitDoc.h : interface of the CASplitDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASPLITDOC_H__CC2CF4CA_A458_48B9_A41E_EBAECBEBD417__INCLUDED_)
#define AFX_ASPLITDOC_H__CC2CF4CA_A458_48B9_A41E_EBAECBEBD417__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CASplitDoc : public CDocument
{
protected: // create from serialization only
	CASplitDoc();
	DECLARE_DYNCREATE(CASplitDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CASplitDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CASplitDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CASplitDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASPLITDOC_H__CC2CF4CA_A458_48B9_A41E_EBAECBEBD417__INCLUDED_)
