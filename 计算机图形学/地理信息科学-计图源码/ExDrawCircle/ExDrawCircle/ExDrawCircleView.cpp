
// ExDrawCircleView.cpp : CExDrawCircleView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExDrawCircleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExDrawCircleView ����/����

CExDrawCircleView::CExDrawCircleView()
{
	// TODO:  �ڴ˴���ӹ������

}

CExDrawCircleView::~CExDrawCircleView()
{
}

BOOL CExDrawCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExDrawCircleView ����

void CExDrawCircleView::OnDraw(CDC* /*pDC*/)
{
	CExDrawCircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExDrawCircleView ��ӡ


void CExDrawCircleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExDrawCircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExDrawCircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExDrawCircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CExDrawCircleView ���

#ifdef _DEBUG
void CExDrawCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CExDrawCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExDrawCircleDoc* CExDrawCircleView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExDrawCircleDoc)));
	return (CExDrawCircleDoc*)m_pDocument;
}
#endif //_DEBUG


// CExDrawCircleView ��Ϣ�������


void CExDrawCircleView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	SetTimer(1, 50, NULL);
	r = 100; m = 100; x = point.x; y = point.y;

	CView::OnLButtonDown(nFlags, point);
}
