// BSplitView.h : interface of the CBSplitView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BSPLITVIEW_H__1A7E160C_F833_42BD_9B30_269A11FE1CD5__INCLUDED_)
#define AFX_BSPLITVIEW_H__1A7E160C_F833_42BD_9B30_269A11FE1CD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBSplitView : public CView
{
protected: // create from serialization only
	CBSplitView();
	DECLARE_DYNCREATE(CBSplitView)

// Attributes
public:
	CBSplitDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBSplitView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBSplitView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBSplitView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BSplitView.cpp
inline CBSplitDoc* CBSplitView::GetDocument()
   { return (CBSplitDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BSPLITVIEW_H__1A7E160C_F833_42BD_9B30_269A11FE1CD5__INCLUDED_)
