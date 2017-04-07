
// LineClipsView.cpp : CLineClipsView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "LineClips.h"
#endif


#include "LineClipsDoc.h"
#include "LineClipsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLineClipsView

IMPLEMENT_DYNCREATE(CLineClipsView, CView)

BEGIN_MESSAGE_MAP(CLineClipsView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLineClipsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CLIP_INPUTLINE, &CLineClipsView::OnClipInputline)
	ON_COMMAND(ID_CLIP_INPUTCLIPWINDOW, &CLineClipsView::OnClipInputclipwindow)
	ON_COMMAND(ID_CLIP_CLIP, &CLineClipsView::OnClipClip)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CLineClipsView 构造/析构

CLineClipsView::CLineClipsView()
{
	// TODO:  在此处添加构造代码

}

CLineClipsView::~CLineClipsView()
{
}

BOOL CLineClipsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLineClipsView 绘制

void CLineClipsView::OnDraw(CDC* /*pDC*/)
{
	CLineClipsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CLineClipsView 打印


void CLineClipsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLineClipsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLineClipsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CLineClipsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CLineClipsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLineClipsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLineClipsView 诊断

#ifdef _DEBUG
void CLineClipsView::AssertValid() const
{
	CView::AssertValid();
}

void CLineClipsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLineClipsDoc* CLineClipsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLineClipsDoc)));
	return (CLineClipsDoc*)m_pDocument;
}
#endif //_DEBUG


// CLineClipsView 消息处理程序


void CLineClipsView::OnClipInputline()
{
	m_draw = 1;
	// TODO:  在此添加命令处理程序代码
}


void CLineClipsView::OnClipInputclipwindow()
{
	m_draw = 2;
	// TODO:  在此添加命令处理程序代码
}


void CLineClipsView::OnClipClip()
{
	// TODO:  在此添加命令处理程序代码
	int xwmin, ywmin, xwmax, ywmax, x1, y1, x2, y2;
	x1 = p0.x;
	y1 = p0.y;
	x2 = p1.x;
	y2 = p1.y;
	float u1 = 0.0, u2 = 1.0, dx = x2 - x1, dy = y2 - y1;
	xwmin = pr0.x;
	ywmin = pr0.y;
	xwmax = pr1.x;
	ywmax = pr1.y;
	if (pr0.x > pr1.x)
	{
		xwmin = pr1.x;
		xwmax = pr0.x;
	}
	if (pr0.y > pr1.y)
	{
		ywmin = pr1.y;
		ywmax = pr0.y;
	}
	if (clipTest(-dx, x1 - xwmin, &u1, &u2))
	{
		if (clipTest(dx, xwmax - x1, &u1, &u2))
		{
			if (clipTest(-dy, y1 - ywmin, &u1, &u2))
			{
				if (clipTest(dy, ywmax - y1, &u1, &u2))
				{
					if (u2 < 1.0)
					{
						x2 = x1 + u2*dx;
						y2 = y1 + u2*dy;
					}
					if (u1 > 0.0)
					{
						x1 = x1 + u1*dx;
						y1 = y1 + u1*dy;
					}
					CClientDC dc(this);
					dc.SetROP2(R2_NOT);
					dc.MoveTo(p0);
					dc.LineTo(p1);
					dc.MoveTo(x1, y1);
					dc.LineTo(x2, y2);
				}
			}
		}
	}
}

int CLineClipsView::clipTest(float p, float q, float *u1, float* u2)
{
	int flag = 1;
	float r;
	if (p < 0.0)
	{
		r = q / p;
		if (r > *u2)
			flag = 0;
		else if (r > *u1)
			*u1 = r;
	}
	else if (p > 0.0)
	{
		r = q / p;
		if (r < *u1)
			flag = 0;
		else if (r < *u2)
			*u2 = r;
	}
	else if (q < 0.0)
		flag = 0;
	return(flag);
}

void CLineClipsView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	switch (m_draw)
	{
	case 1:p0 = point; break;
	case 2:pr0 = point; break;
	default:break;
	}
	CClientDC dc(this);
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


void CLineClipsView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	switch (m_draw)
	{
	case 1:p1 = point; break;
	case 2:pr1 = point; break;
	default:break;
	}
	if (m_Drag)
	{
		m_Drag = 0;
		ReleaseCapture();
		ClipCursor(NULL);
	}
	CView::OnLButtonUp(nFlags, point);
}


void CLineClipsView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	HCURSOR m_hCursor = LoadCursor(NULL, IDC_CROSS);
	CClientDC dc(this);
	if (m_Drag)
	{
		dc.SetROP2(R2_NOT);
		switch (m_draw)
		{
		case 1:
			dc.MoveTo(m_pntOrigin);
			dc.LineTo(m_pntPrev);
			dc.MoveTo(m_pntOrigin);
			dc.LineTo(point);
			m_pntPrev = point;
			break;
		case 2:
			dc.Rectangle(m_pntOrigin.x, m_pntOrigin.y, m_pntPrev.x, m_pntPrev.y);
			dc.Rectangle(m_pntOrigin.x, m_pntOrigin.y, point.x, point.y);
			m_pntPrev = point;
			break;
		default:
			break;
		}
	}
	CView::OnMouseMove(nFlags, point);
}
