
// LineClipsView.cpp : CLineClipsView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CLineClipsView ����/����

CLineClipsView::CLineClipsView()
{
	// TODO:  �ڴ˴���ӹ������

}

CLineClipsView::~CLineClipsView()
{
}

BOOL CLineClipsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLineClipsView ����

void CLineClipsView::OnDraw(CDC* /*pDC*/)
{
	CLineClipsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CLineClipsView ��ӡ


void CLineClipsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLineClipsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLineClipsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLineClipsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CLineClipsView ���

#ifdef _DEBUG
void CLineClipsView::AssertValid() const
{
	CView::AssertValid();
}

void CLineClipsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLineClipsDoc* CLineClipsView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLineClipsDoc)));
	return (CLineClipsDoc*)m_pDocument;
}
#endif //_DEBUG


// CLineClipsView ��Ϣ�������


void CLineClipsView::OnClipInputline()
{
	m_draw = 1;
	// TODO:  �ڴ���������������
}


void CLineClipsView::OnClipInputclipwindow()
{
	m_draw = 2;
	// TODO:  �ڴ���������������
}


void CLineClipsView::OnClipClip()
{
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
