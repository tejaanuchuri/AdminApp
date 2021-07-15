
// AdminView.h : interface of the CAdminView class
//

#pragma once


class CAdminView : public CView
{
protected: // create from serialization only
	CAdminView() noexcept;
	DECLARE_DYNCREATE(CAdminView)

// Attributes
public:
	CAdminDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CAdminView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AdminView.cpp
inline CAdminDoc* CAdminView::GetDocument() const
   { return reinterpret_cast<CAdminDoc*>(m_pDocument); }
#endif

