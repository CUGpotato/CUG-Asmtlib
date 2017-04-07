
// Draw3DView.cpp : CDraw3DView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw3D.h"
#endif

#include "Draw3DDoc.h"
#include "Draw3DView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma once

#define PI 3.1415
// CDraw3DView

struct Point
{
	double x;
	double y;
	double z;
}m_point[8];

struct Line
{
	int point1;
	int point2;
}line[12];

double x0;
double y0_y0;
double z0;//原点坐标
int first_x, first_y, pre_x, pre_y;



IMPLEMENT_DYNCREATE(CDraw3DView, CView)

BEGIN_MESSAGE_MAP(CDraw3DView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDraw3DView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CDraw3DView 构造/析构

CDraw3DView::CDraw3DView()
{
	// TODO:  在此处添加构造代码
	//初始化正方形定点
	m_point[0].x = 200; m_point[0].y = 200; m_point[0].z = 200;
	m_point[1].x = 260; m_point[1].y = 200; m_point[1].z = 200;
	m_point[2].x = 260; m_point[2].y = 200; m_point[2].z = 260;
	m_point[3].x = 200; m_point[3].y = 200; m_point[3].z = 260;
	m_point[4].x = 200; m_point[4].y = 260; m_point[4].z = 200;
	m_point[5].x = 260; m_point[5].y = 260; m_point[5].z = 200;
	m_point[6].x = 260; m_point[6].y = 260; m_point[6].z = 260;
	m_point[7].x = 200; m_point[7].y = 260; m_point[7].z = 260;

	//原点设为正方形第一个顶点
	x0 = m_point[0].x;
	y0_y0 = m_point[0].y;
	z0 = m_point[0].z;
//初始化正方体的边
	line[0].point1 = 0; line[0].point2 = 1;
	line[1].point1 = 1; line[1].point2 =2;
	line[2].point1 = 2; line[2].point2 = 3;
	line[3].point1 = 3; line[3].point2 = 0;
	line[4].point1 = 0; line[4].point2 = 4;
	line[5].point1 = 1; line[5].point2 = 5;
	line[6].point1 = 2; line[6].point2 = 6;
	line[7].point1 = 3; line[7].point2 = 7;
	line[8].point1 = 4; line[8].point2 = 5;
	line[9].point1 = 5; line[9].point2 = 6;
	line[10].point1 = 6; line[10].point2 = 7;
	line[11].point1 = 7; line[11].point2 = 4;
}

CDraw3DView::~CDraw3DView()
{
}

BOOL CDraw3DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDraw3DView 绘制

void CDraw3DView::OnDraw(CDC* pDC)
{
	CDraw3DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int i;
	for (i = 0; i < 12; i++)
	{
		pDC->MoveTo(m_point[line[i].point1].x + 0.5, m_point[line[i].point1].y + 0.5);
		pDC->LineTo(m_point[line[i].point2].x + 0.5, m_point[line[i].point2].y + 0.5);
	}
	CBrush brush(RGB(255, 0, 0));
	CBrush* pOldbrush = pDC->SelectObject(&brush);
	pDC->Ellipse(x0 - 3, y0_y0 - 3, x0 + 3, y0_y0 + 3);
	pDC->SelectObject(pOldbrush);
	// TODO:  在此处为本机数据添加绘制代码
}


// CDraw3DView 打印


void CDraw3DView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDraw3DView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDraw3DView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CDraw3DView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CDraw3DView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDraw3DView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDraw3DView 诊断

#ifdef _DEBUG
void CDraw3DView::AssertValid() const
{
	CView::AssertValid();
}

void CDraw3DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDraw3DDoc* CDraw3DView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDraw3DDoc)));
	return (CDraw3DDoc*)m_pDocument;
}
#endif //_DEBUG


// CDraw3DView 消息处理程序


void CDraw3DView::Rotate(struct Point* point, double angle_x, double angle_y)
{
	//正方体旋转
	int i;
	for (i = 0; i < 8; i++,point++)
	{
		double x = (*point).x - x0, y = (*point).y - y0_y0, z = (*point).z - z0;
		double temp_x = x, temp_y = y, temp_z = z;
		temp_x = z*sin(angle_y / 180 * PI) + x*cos(angle_y / 180 * PI);
		temp_z = z*cos(angle_y / 180 * PI) - x*sin(angle_y / 180 * PI);
		temp_y = y;

		y = temp_y*cos(angle_x / 180 * PI) - temp_z*sin(angle_x / 180 * PI);
		z = temp_y*sin(angle_x / 180 * PI) + temp_z*cos(angle_x / 180 * PI);
		x = temp_x;
		(*point).x = x + x0;
		(*point).y = y + y0_y0;
		(*point).z = z + z0;

	}
		
}


void CDraw3DView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	first_x = point.x;
	first_y = point.y;
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CDraw3DView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (GetCapture() == this)
	{
		pre_x = point.x;
		pre_y = point.y;
		Rotate(m_point, (first_y - pre_y) / 10, (pre_x - first_x) / 10);
		Invalidate(true);
	}
	CView::OnMouseMove(nFlags, point);
}


void CDraw3DView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void CDraw3DView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	int i;
	switch (nChar)
	{
	case VK_UP:for (i = 0; i < 8; i++)m_point[i].y -= 5; break;
	case VK_DOWN:for (i = 0; i < 8; i++)m_point[i].y += 5; break;
	case VK_LEFT:for (i = 0; i < 8; i++)m_point[i].x -= 5; break;
	case VK_RIGHT:for (i = 0; i < 8; i++)m_point[i].x += 5; break;
	}

	x0 = m_point[0].x; y0_y0 = m_point[0].y; z0 = m_point[0].z;
	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CDraw3DView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	int i;
	for (i = 1; i < 8; i++)
	{
		double x = m_point[i].x - x0, y = m_point[i].y - y0_y0, z = m_point[i].z - z0;
		x += x*zDelta / 200; y += y*zDelta / 200; z += z*zDelta / 200;
		m_point[i].x = x + x0; m_point[i].y = y + y0_y0; m_point[i].z = z + z0;
	}
	Invalidate(true);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
