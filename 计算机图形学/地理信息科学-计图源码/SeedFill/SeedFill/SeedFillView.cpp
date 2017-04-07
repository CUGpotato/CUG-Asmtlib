
// SeedFillView.cpp : CSeedFillView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SeedFill.h"
#endif

#include "SeedFillDoc.h"
#include "SeedFillView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSeedFillView

IMPLEMENT_DYNCREATE(CSeedFillView, CView)

BEGIN_MESSAGE_MAP(CSeedFillView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSeedFillView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSeedFillView 构造/析构

CSeedFillView::CSeedFillView()
{
	// TODO:  在此处添加构造代码

}

CSeedFillView::~CSeedFillView()
{
}

BOOL CSeedFillView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSeedFillView 绘制

void CSeedFillView::OnDraw(CDC* /*pDC*/)
{
	CSeedFillDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CSeedFillView 打印


void CSeedFillView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSeedFillView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSeedFillView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CSeedFillView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CSeedFillView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSeedFillView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSeedFillView 诊断

#ifdef _DEBUG
void CSeedFillView::AssertValid() const
{
	CView::AssertValid();
}

void CSeedFillView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSeedFillDoc* CSeedFillView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSeedFillDoc)));
	return (CSeedFillDoc*)m_pDocument;
}
#endif //_DEBUG


// CSeedFillView 消息处理程序


void CSeedFillView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CDC* pDC = GetDC();
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pDC->SelectObject(&pen);
	int polypoints[] = { 100, 300, 200, 200, 300, 200, 300, 350,
		400, 250, 450, 300, 300, 50, 100, 150 };
	pDC->MoveTo(polypoints[0], polypoints[1]);
	for (int i = 1; i < 8; i++)
		pDC->LineTo(polypoints[2 * i], polypoints[2 * i + 1]);
	pDC->LineTo(polypoints[0], polypoints[1]);
	SeedFill(pDC, point, pDC->GetPixel(point.x, point. y), RGB(255, 0, 0));
	CView::OnLButtonDown(nFlags, point);
}
