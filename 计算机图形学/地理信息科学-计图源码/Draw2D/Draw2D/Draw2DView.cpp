// Draw 2DView.cpp : CDraw2DView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Draw2D.h"
#endif

#include "Draw2DDoc.h"
#include "Draw2DView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDraw2DView

IMPLEMENT_DYNCREATE(CDraw2DView, CView)

BEGIN_MESSAGE_MAP(CDraw2DView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CDraw2DView ����/����

CDraw2DView::CDraw2DView()
{
	// TODO:  �ڴ˴���ӹ������
	m_point[0].x = 200; m_point[0].y = 200;
	m_point[1].x = 260; m_point[1].y = 200;
	m_point[2].x = 200; m_point[2].y = 260;
	m_point[3].x = 260; m_point[3].y = 260;
	x0 = m_point[0].x; y0 = m_point[0].y;
	line[0].point1 = 0; line[0].point2 = 1;
	line[1].point1 = 1; line[1].point2 = 3;
	line[2].point1 = 3; line[2].point2 =2;
	line[3].point1 = 2; line[3].point2 = 0;
}

CDraw2DView::~CDraw2DView()
{
}

BOOL CDraw2DView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDraw2DView ����

void CDraw2DView::OnDraw(CDC* pDC)
{
	CDraw2DDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int i;
	for (i = 0; i < 4; i++){
		pDC->MoveTo(m_point[line[i].point1].x + 0.5, m_point[line[i].point1].y + 0.5);
		pDC->LineTo(m_point[line[i].point2].x + 0.5, m_point[line[i].point2].y + 0.5);
	}
	CBrush brush(RGB(255, 0, 0));
	CBrush*pOldbrush = pDC->SelectObject(&brush);
	pDC->Ellipse(x0 - 3, y0 - 3, x0 + 3, y0 + 3);
	pDC->SelectObject(pOldbrush);

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDraw2DView ��ӡ

BOOL CDraw2DView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDraw2DView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDraw2DView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CDraw2DView ���

#ifdef _DEBUG
void CDraw2DView::AssertValid() const
{
	CView::AssertValid();
}

void CDraw2DView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDraw2DDoc* CDraw2DView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDraw2DDoc)));
	return (CDraw2DDoc*)m_pDocument;
}
#endif //_DEBUG


// CDraw2DView ��Ϣ�������


void CDraw2DView::Rotate(struct Point* point, double angle_x, double angle_y)
{
	int i;
	const double PI = 3.1415926;
	for (i = 0; i<8; i++, point++){
		double x = (*point).x - x0, y = (*point).y - y0;
		double temp_x = x, temp_y = y;
		temp_x = y*sin(angle_y / 180 * PI) + x*cos(angle_y / 180 * PI);
		temp_y = -x*sin(angle_y / 180 * PI) + y*cos(angle_y / 180 * PI);
		(*point).x = x + x0; (*point).y = y + y0;
	}
}


void CDraw2DView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	first_x = point.x; first_y = point.y;
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CDraw2DView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i;
	switch (nChar){
	case VK_UP:for (i = 0; i < 4; i++)m_point[i].y -= 5; break;
	case VK_DOWN:for (i = 0; i < 4; i++)m_point[i].y += 5; break;
	case VK_LEFT:for (i = 0; i < 4; i++)m_point[i].x -= 5; break;
	case VK_RIGHT:for (i = 0; i < 4; i++)m_point[i].x += 5; break;
	}
	x0 = m_point[0].x; y0 = m_point[0].y;
	Invalidate(true);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CDraw2DView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (GetCapture() == this){
		pre_x = point.x; pre_y = point.y;
		Rotate(m_point, (first_y - pre_y) /10, (pre_x - first_x) / 10);

	}
			Invalidate(true);
	CView::OnMouseMove(nFlags, point);
}

BOOL CDraw2DView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i;
	for (i = 1; i < 4; i++){
		double x = m_point[i].x - x0, y = m_point[i].y - y0;
		x += x*zDelta / 200; y += y*zDelta / 200;
		m_point[i].x = x + x0; m_point[i].y = y + y0;
	}
	Invalidate(true);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}