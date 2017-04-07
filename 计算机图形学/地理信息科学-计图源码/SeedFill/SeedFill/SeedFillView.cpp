
// SeedFillView.cpp : CSeedFillView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSeedFillView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSeedFillView ����/����

CSeedFillView::CSeedFillView()
{
	// TODO:  �ڴ˴���ӹ������

}

CSeedFillView::~CSeedFillView()
{
}

BOOL CSeedFillView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSeedFillView ����

void CSeedFillView::OnDraw(CDC* /*pDC*/)
{
	CSeedFillDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSeedFillView ��ӡ


void CSeedFillView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSeedFillView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSeedFillView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSeedFillView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CSeedFillView ���

#ifdef _DEBUG
void CSeedFillView::AssertValid() const
{
	CView::AssertValid();
}

void CSeedFillView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSeedFillDoc* CSeedFillView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSeedFillDoc)));
	return (CSeedFillDoc*)m_pDocument;
}
#endif //_DEBUG


// CSeedFillView ��Ϣ�������


void CSeedFillView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
