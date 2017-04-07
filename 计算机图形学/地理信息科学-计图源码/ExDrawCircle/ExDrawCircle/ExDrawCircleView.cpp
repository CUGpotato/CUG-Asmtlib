
// ExDrawCircleView.cpp : CExDrawCircleView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ExDrawCircle.h"
#endif

#include "ExDrawCircleDoc.h"
#include "ExDrawCircleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExDrawCircleView

IMPLEMENT_DYNCREATE(CExDrawCircleView, CView)

BEGIN_MESSAGE_MAP(CExDrawCircleView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExDrawCircleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExDrawCircleView 构造/析构

CExDrawCircleView::CExDrawCircleView()
{
	// TODO:  在此处添加构造代码

}

CExDrawCircleView::~CExDrawCircleView()
{
}

BOOL CExDrawCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExDrawCircleView 绘制

void CExDrawCircleView::OnDraw(CDC* /*pDC*/)
{
	CExDrawCircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CExDrawCircleView 打印


void CExDrawCircleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExDrawCircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExDrawCircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CExDrawCircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CExDrawCircleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExDrawCircleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExDrawCircleView 诊断

#ifdef _DEBUG
void CExDrawCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CExDrawCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExDrawCircleDoc* CExDrawCircleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExDrawCircleDoc)));
	return (CExDrawCircleDoc*)m_pDocument;
}
#endif //_DEBUG


// CExDrawCircleView 消息处理程序


void CExDrawCircleView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDC *pDC = GetDC();
	if (r > 0)
	{
		ellipseMidpoint(pDC, x, y, m, r, RGB(0, 0, 0));
		ellipseMidpoint(pDC, x, y, r, m, RGB(0, 0, 0));
		r-= 5; Invalidate(false);
	}
	else
	{
		pDC->MoveTo(x - m, y);
		pDC->MoveTo(x + m, y);
		pDC->MoveTo(x, y + m);
		pDC->MoveTo(x, y - m);
	}

	CView::OnTimer(nIDEvent);
}


void CExDrawCircleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	SetTimer(1, 50, NULL);
	r = 100; m = 100; x = point.x; y = point.y;

	CView::OnLButtonDown(nFlags, point);
}
