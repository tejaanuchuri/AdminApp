
// AdminView.cpp : implementation of the CAdminView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Admin.h"
#endif

#include "AdminDoc.h"
#include "AdminView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAdminView

IMPLEMENT_DYNCREATE(CAdminView, CView)

BEGIN_MESSAGE_MAP(CAdminView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CAdminView construction/destruction

CAdminView::CAdminView() noexcept
{
	// TODO: add construction code here

}

CAdminView::~CAdminView()
{
}

BOOL CAdminView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CAdminView drawing

void CAdminView::OnDraw(CDC* /*pDC*/)
{
	CAdminDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CAdminView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAdminView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAdminView diagnostics

#ifdef _DEBUG
void CAdminView::AssertValid() const
{
	CView::AssertValid();
}

void CAdminView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAdminDoc* CAdminView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAdminDoc)));
	return (CAdminDoc*)m_pDocument;
}
#endif //_DEBUG


// CAdminView message handlers
