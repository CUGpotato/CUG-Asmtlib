
// GraphicsExpView.cpp : CGraphicsExpView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GraphicsExp.h"
#endif

#include "GraphicsExpDoc.h"
#include "GraphicsExpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicsExpView

IMPLEMENT_DYNCREATE(CGraphicsExpView, CView)

BEGIN_MESSAGE_MAP(CGraphicsExpView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGraphicsExpView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CGraphicsExpView 构造/析构

CGraphicsExpView::CGraphicsExpView()
{
	// TODO:  在此处添加构造代码

}

CGraphicsExpView::~CGraphicsExpView()
{
}

BOOL CGraphicsExpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, (HBRUSH)::GetStockObject(WHITE_BRUSH), 0);

	return CView::PreCreateWindow(cs);
}

// CGraphicsExpView 绘制

void CGraphicsExpView::OnDraw(CDC* pDC)
{
	CGraphicsExpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int index = pDoc->GetLineNumber();
	while (index--)
		pDoc->GetLine(index).DrawLine(pDC);

	// TODO:  在此处为本机数据添加绘制代码
}


// CGraphicsExpView 打印


void CGraphicsExpView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGraphicsExpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGraphicsExpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CGraphicsExpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CGraphicsExpView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGraphicsExpView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGraphicsExpView 诊断

#ifdef _DEBUG
void CGraphicsExpView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicsExpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicsExpDoc* CGraphicsExpView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicsExpDoc)));
	return (CGraphicsExpDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicsExpView 消息处理程序


void CGraphicsExpView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	m_pntPrev = point;
	m_pntOrigin = point;
	SetCapture();
	m_Drag = 1;
	RECT rect;
	GetClientRect(&rect);
	ClientToScreen(&rect);
	ClipCursor(&rect);

	CView::OnLButtonDown(nFlags, point);
}


void CGraphicsExpView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	HCURSOR m_hCursor = LoadCursor(NULL,IDC_CROSS);
	SetCursor(m_hCursor);    //设置十字光标
	CClientDC dc(this);
	if (m_Drag)
	{
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_pntOrigin);
		dc.LineTo(m_pntPrev);
		dc.MoveTo(m_pntOrigin);
		dc.LineTo(point);
		m_pntPrev = point;
	}

	CView::OnMouseMove(nFlags, point);
}


void CGraphicsExpView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	m_Drag = 0;
	ReleaseCapture();
	ClipCursor(NULL);

	CGraphicsExpDoc* pDoc = GetDocument();
	pDoc->AddLine(m_pntOrigin, point);

	CView::OnLButtonUp(nFlags, point);
}
