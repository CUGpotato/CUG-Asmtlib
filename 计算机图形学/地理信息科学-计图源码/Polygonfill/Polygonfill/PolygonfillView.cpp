
// PolygonfillView.cpp : CPolygonfillView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Polygonfill.h"
#endif

#include "PolygonfillDoc.h"
#include "PolygonfillView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPolygonfillView

IMPLEMENT_DYNCREATE(CPolygonfillView, CView)

BEGIN_MESSAGE_MAP(CPolygonfillView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPolygonfillView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POLIGONFILL_SCANLINEFILL32773, &CPolygonfillView::OnPoligonfillScanlinefill)
END_MESSAGE_MAP()

// CPolygonfillView 构造/析构

CPolygonfillView::CPolygonfillView()
{
	// TODO:  在此处添加构造代码

}

CPolygonfillView::~CPolygonfillView()
{
}

BOOL CPolygonfillView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPolygonfillView 绘制

void CPolygonfillView::OnDraw(CDC* /*pDC*/)
{
	CPolygonfillDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CPolygonfillView 打印


void CPolygonfillView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPolygonfillView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPolygonfillView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CPolygonfillView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CPolygonfillView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPolygonfillView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPolygonfillView 诊断

#ifdef _DEBUG
void CPolygonfillView::AssertValid() const
{
	CView::AssertValid();
}

void CPolygonfillView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPolygonfillDoc* CPolygonfillView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPolygonfillDoc)));
	return (CPolygonfillDoc*)m_pDocument;
}
#endif //_DEBUG


// CPolygonfillView 消息处理程序


void CPolygonfillView::OnPoligonfillScanlinefill()
{
	// TODO:  在此添加命令处理程序代码
	Invalidate(true);
	const double angle = 0.0;
	const double gap = 1.0;
	if (FillSetDlg.DoModal() == IDOK)
	{
		UpdateData(TRUE);
		m_nScanColor = FillSetDlg.ScanLineColor;
		m_nScanAngle = FillSetDlg.m_nScanLineAngle;
		m_nScanGap = FillSetDlg.m_nScanLineGap;
	}
	else
	{
		m_nScanColor = RGB(255, 255, 255);
		m_nScanAngle = angle;
		m_nScanGap = gap;
	}
	int polypoints[16] = { 100, 300, 200, 200, 300, 200, 300, 350,
		400, 250, 450, 300, 300, 50, 100, 150 };///************************************
	CDC* pDC = GetDC();
	CPen pen;
	COLORREF penColor = m_nScanColor;
	pen.CreatePen(PS_SOLID, 1, penColor);
	pDC->SelectObject(&pen);
	pDC->MoveTo(polypoints[0], polypoints[1]);
	for (int i = 1; i < 8; i++)
		pDC->LineTo(polypoints[2 * i], polypoints[2 * i + 1]);
	pDC->LineTo(polypoints[0], polypoints[1]);
	poly_fill(pDC, 8, polypoints, m_nScanGap, m_nScanAngle);
}
