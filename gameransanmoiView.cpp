
// gameransanmoiView.cpp : implementation of the CgameransanmoiView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "gameransanmoi.h"
#endif

#include "gameransanmoiDoc.h"
#include "gameransanmoiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CgameransanmoiView

IMPLEMENT_DYNCREATE(CgameransanmoiView, CView)

BEGIN_MESSAGE_MAP(CgameransanmoiView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CgameransanmoiView construction/destruction

CgameransanmoiView::CgameransanmoiView() noexcept
{
	// TODO: add construction code here
	banco = Banco();

}

CgameransanmoiView::~CgameransanmoiView()
{
}

BOOL CgameransanmoiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CgameransanmoiView drawing

void CgameransanmoiView::OnDraw(CDC* /*pDC*/)
{
	CgameransanmoiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	banco.vehinh(&pdc);
}

void CgameransanmoiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CgameransanmoiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CgameransanmoiView diagnostics

#ifdef _DEBUG
void CgameransanmoiView::AssertValid() const
{
	CView::AssertValid();
}

void CgameransanmoiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CgameransanmoiDoc* CgameransanmoiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CgameransanmoiDoc)));
	return (CgameransanmoiDoc*)m_pDocument;
}
#endif //_DEBUG


// CgameransanmoiView message handlers


void CgameransanmoiView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (banco.dk == 0 && nChar == 32 && banco.thang == 1 && banco.level == 0)
	{
		batdaugame();
	}
	if (banco.dk == 1 && nChar >= 37 && nChar <= 40)
	{
		banco.huong = nChar;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

UINT randichuyen(LPVOID pParam)
{
	CgameransanmoiView* cview = (CgameransanmoiView*)pParam;
	CClientDC pdc(cview);
	cview->banco.randichuyen(&pdc);
	return 0;
}

UINT capnhathinh(LPVOID pParam)
{
	CgameransanmoiView* cview = (CgameransanmoiView*)pParam;
	CClientDC pdc(cview);
	cview->banco.capnhathinh(&pdc);
	return 0;
}

int CgameransanmoiView::batdaugame()
{
	// TODO: Add your implementation code here.
	banco.batdau();
	AfxBeginThread(randichuyen, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	AfxBeginThread(capnhathinh, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	return 0;
}
