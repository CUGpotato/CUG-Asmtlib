
// ExDrawLineView.cpp : CExDrawLineView 类的实现
//

#include "stdafx.h"
#include"DrawLineDlg.h"
#include"DrawLineAlgorithms.h"
#include"ExDrawLineDoc.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ExDrawLine.h"
#endif


#include"resource.h"
#include "ExDrawLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExDrawLineView

IMPLEMENT_DYNCREATE(CExDrawLineView, CView)

BEGIN_MESSAGE_MAP(CExDrawLineView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExDrawLineView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_DRAWLINE32775, &CExDrawLineView::OnDrawline)
	ON_COMMAND(ID_COMPARE32776, &CExDrawLineView::OnCompare)
END_MESSAGE_MAP()

// CExDrawLineView 构造/析构

CExDrawLineView::CExDrawLineView()
{
	// TODO:  在此处添加构造代码

}

CExDrawLineView::~CExDrawLineView()
{
}

BOOL CExDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExDrawLineView 绘制

void CExDrawLineView::OnDraw(CDC* /*pDC*/)
{
	CExDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CExDrawLineView 打印


void CExDrawLineView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CExDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CExDrawLineView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExDrawLineView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExDrawLineView 诊断

#ifdef _DEBUG
void CExDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CExDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExDrawLineDoc* CExDrawLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExDrawLineDoc)));
	return (CExDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CExDrawLineView 消息处理程序



void CExDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDC *pDC = GetDC();
	if (draw)
	{
		m_pointnum++;
		if (m_pointnum >= 2)
		{
			p1 = point;
			switch (linetype)
			{
			case 0: Middlepoint(pDC, p0.x, p0.y, p1.x, p1.y, RGB(r, g, b)); break;
			case 1: DDA(pDC, p0.x, p0.y, p1.x, p1.y, RGB(r, g, b)); break;
			case 2: Bresenham(pDC, p0.x, p0.y, p1.x, p1.y, RGB(r, g, b)); break;
			default:break;
			}
			p0 = p1;
		}
		else p0 = point;
	}
	CView::OnLButtonDown(nFlags, point);
}




void CExDrawLineView::OnDrawline()
{
	// TODO:  在此添加命令处理程序代码
	CDrawLineDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		UpdateData(true);
		m_pointnum = 0;
		linetype = dlg.m_algorithm;
		r = dlg.m_r;
		g = dlg.m_g;
		b = dlg.m_b;
		if (linetype == -1)
		{
			AfxMessageBox(_T("Please select an algorithm!"));
			draw = false;
		}
		else if (r < 0 || r>255 || g < 0 || g>255 || b < 0 || b>255)
		{
			AfxMessageBox(_T("Please input a correct color!"));
			draw = false;
		}
		else
			draw = true;
	}
}



void CExDrawLineView::OnCompare()
{
	// TODO:  在此添加命令处理程序代码
	CDC *pDC = GetDC();
	CString msgDDA, msgBresenham, msgMiddlepoint;
	CPoint point1(10, 10), point2(100, 100);
	LARGE_INTEGER t1, t2, frq;
	QueryPerformanceFrequency(&frq);  //获取计数器频率

	QueryPerformanceCounter(&t1);     //获取计时初始值
	for (int i = 0; i < 1000; i++)
		DDA(pDC, point1.x, point1.y, point2.x, point2.y, RGB(0, 0, 0));
	QueryPerformanceCounter(&t2);
	msgDDA.Format(_T("使用DDA算法绘制一条从点（10，10）到点（100，100）的直线1000遍耗时：%fms"), ((double)t2.QuadPart - (double)t1.QuadPart )/ (double)frq.QuadPart * 1000);

	QueryPerformanceCounter(&t1);
	for (int i = 0; i < 1000; i++)
		Bresenham(pDC, point1.x, point1.y, point2.x, point2.y, RGB(0, 0, 0));
	QueryPerformanceCounter(&t2);
	msgBresenham.Format(_T("使用Bresenham算法绘制一条从点（10，10）到点（100，100）的直线1000遍耗时：%fms"), ((double)t2.QuadPart - (double)t1.QuadPart) / (double)frq.QuadPart * 1000);

	QueryPerformanceCounter(&t1);
	for (int i = 0; i < 1000; i++)
		Middlepoint(pDC, point1.x, point1.y, point2.x, point2.y, RGB(0, 0, 0));
	QueryPerformanceCounter(&t2);
	msgMiddlepoint.Format(_T("使用中点画线算法绘制一条从点（10，10）到点（100，100）的直线1000遍耗时：%fms"), ((double)t2.QuadPart - (double)t1.QuadPart) / (double)frq.QuadPart * 1000);

	AfxMessageBox(msgDDA + '\n' + msgBresenham + '\n' + msgMiddlepoint);
}
