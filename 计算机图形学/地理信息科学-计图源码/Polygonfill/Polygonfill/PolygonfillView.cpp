
// PolygonfillView.cpp : CPolygonfillView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPolygonfillView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POLIGONFILL_SCANLINEFILL32773, &CPolygonfillView::OnPoligonfillScanlinefill)
END_MESSAGE_MAP()

// CPolygonfillView ����/����

CPolygonfillView::CPolygonfillView()
{
	// TODO:  �ڴ˴���ӹ������

}

CPolygonfillView::~CPolygonfillView()
{
}

BOOL CPolygonfillView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPolygonfillView ����

void CPolygonfillView::OnDraw(CDC* /*pDC*/)
{
	CPolygonfillDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CPolygonfillView ��ӡ


void CPolygonfillView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPolygonfillView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPolygonfillView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPolygonfillView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CPolygonfillView ���

#ifdef _DEBUG
void CPolygonfillView::AssertValid() const
{
	CView::AssertValid();
}

void CPolygonfillView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPolygonfillDoc* CPolygonfillView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPolygonfillDoc)));
	return (CPolygonfillDoc*)m_pDocument;
}
#endif //_DEBUG


// CPolygonfillView ��Ϣ�������


void CPolygonfillView::OnPoligonfillScanlinefill()
{
	// TODO:  �ڴ���������������
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
