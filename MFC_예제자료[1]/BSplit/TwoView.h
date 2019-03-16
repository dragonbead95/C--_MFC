#if !defined(AFX_TWOVIEW_H__FC525396_1F75_45CC_8B12_FF37B0011FDB__INCLUDED_)
#define AFX_TWOVIEW_H__FC525396_1F75_45CC_8B12_FF37B0011FDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TwoView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTwoView view

class CTwoView : public CView
{
protected:
	CTwoView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTwoView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTwoView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTwoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTwoView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TWOVIEW_H__FC525396_1F75_45CC_8B12_FF37B0011FDB__INCLUDED_)
