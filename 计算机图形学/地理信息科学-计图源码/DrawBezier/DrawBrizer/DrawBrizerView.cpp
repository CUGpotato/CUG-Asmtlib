
// DrawBrizerView.cpp : CDrawBrizerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DrawBrizer.h"
#endif

#include "DrawBrizerDoc.h"
#include "DrawBrizerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawBrizerView

IMPLEMENT_DYNCREATE(CDrawBrizerView, CView)

BEGIN_MESSAGE_MAP(CDrawBrizerView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawBrizerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SetParam, &CDrawBrizerView::OnSetparam)
	ON_COMMAND(ID_BRIZER_Normal, &CDrawBrizerView::OnBrizerNormal)
	ON_COMMAND(ID_BRIZER_Geometry, &CDrawBrizerView::OnBrizerGeometry)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CDrawBrizerView 构造/析构

CDrawBrizerView::CDrawBrizerView()
{
	// TODO:  在此处添加构造代码
	Init();

}

CDrawBrizerView::~CDrawBrizerView()
{
}

BOOL CDrawBrizerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawBrizerView 绘制

void CDrawBrizerView::OnDraw(CDC* /*pDC*/)
{
	CDrawBrizerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CDrawBrizerView 打印


void CDrawBrizerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawBrizerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawBrizerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CDrawBrizerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CDrawBrizerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawBrizerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawBrizerView 诊断

#ifdef _DEBUG
void CDrawBrizerView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawBrizerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawBrizerDoc* CDrawBrizerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawBrizerDoc)));
	return (CDrawBrizerDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawBrizerView 消息处理程序


void CDrawBrizerView::OnSetparam()
{
	// TODO:  在此添加命令处理程序代码
	SetParamDlg dlg;
	dlg.m_nSection = m_nSection;
	dlg.m_nColor = m_nColor;
	if (dlg.DoModal())
	{
		m_nSection = dlg.m_nSection;
		m_nColor = dlg.m_nColor;
		m_Bezier.SetSection(m_nSection);
		m_Bezier.SetColor(m_nColor);
	}
}


void CDrawBrizerView::OnBrizerNormal()
{
	// TODO:  在此添加命令处理程序代码
	m_blsNormal = true;
	m_blsGeometry = false;
	ReturnNormal();
	Invalidate(TRUE);
}

void CDrawBrizerView::OnUpdateBrizerNormal(CCmdUI*pCmdUI)
{
	pCmdUI->SetCheck(m_blsNormal);
}

void CDrawBrizerView::OnBrizerGeometry()
{
	// TODO:  在此添加命令处理程序代码
	m_blsNormal = false;
	m_blsGeometry = true;
	ReturnNormal();
	Invalidate(TRUE);
}

void CDrawBrizerView::OnUpdateBrizerGeometry(CCmdUI*pCmdUI)
{
	pCmdUI->SetCheck(m_blsGeometry);
}

void CDrawBrizerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (m_blsNormal||m_blsGeometry)
	{ 
		if (m_nStep == 0 || m_nStep == 1)
		{
			m_Bezier.DrawPoint(&dc, point.x, point.y, 2, RGB(0, 0, 0));
			m_nStep++;
			m_Bezier.AppendPoint(point);
		}
		else
		{
			m_Bezier.DrawPoint(&dc, point.x, point.y, 2, RGB(0, 0, 0));
			m_nStep++; 
			dc.SetROP2(R2_NOTXORPEN);
			m_Bezier.Draw(&dc, m_blsNormal);
			m_nEndY = 0;
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CDrawBrizerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (m_blsNormal || m_blsGeometry)
	{
		if (m_nStep >= 2)
		{
			if (m_nEndY == 0)
				m_Bezier.AppendPoint(point);
			dc.SetROP2(R2_NOTXORPEN);
			if (m_nEndY != 0)
			{
				m_Bezier.Draw(&dc, m_blsNormal);
				m_Bezier.UpdateLastPoint(point);
			}
			m_nEndY = point.y;
			m_Bezier.Draw(&dc, m_blsNormal);
		}
	}
	CView::OnMouseMove(nFlags, point);
}


void CDrawBrizerView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_blsNormal || m_blsGeometry)
	{
		CClientDC dc(this);
		m_Bezier.Draw(&dc, m_blsNormal);
		m_Bezier.ClearAllPoints();
		ReturnNormal();
	}
	CView::OnRButtonDown(nFlags, point);
}
