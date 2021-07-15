
// AdminDoc.cpp : implementation of the CAdminDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Admin.h"
#endif

#include "AdminDoc.h"

#include <propkey.h>
#include "CHomePageDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAdminDoc

IMPLEMENT_DYNCREATE(CAdminDoc, CDocument)

BEGIN_MESSAGE_MAP(CAdminDoc, CDocument)
	ON_COMMAND(ID_ADMINAAPP_HOMEPAGE, &CAdminDoc::OnAdminaappHomepage)
	ON_COMMAND(ID_APPS_ADMINAPP, &CAdminDoc::OnAppsAdminapp)
END_MESSAGE_MAP()


// CAdminDoc construction/destruction

CAdminDoc::CAdminDoc() noexcept
{
	// TODO: add one-time construction code here

}

CAdminDoc::~CAdminDoc()
{
}

BOOL CAdminDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CAdminDoc serialization

void CAdminDoc::Serialize(CArchive& ar)
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

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CAdminDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CAdminDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CAdminDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CAdminDoc diagnostics

#ifdef _DEBUG
void CAdminDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAdminDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAdminDoc commands


void CAdminDoc::OnAdminaappHomepage()
{

}


void CAdminDoc::OnAppsAdminapp()
{
	CHomePageDlg dlg;
	if (dlg.DoModal() == IDOK) {

	}
}
