
// ExDrawLineView.cpp : CExDrawLineView ���ʵ��
//

#include "stdafx.h"
#include"DrawLineDlg.h"
#include"DrawLineAlgorithms.h"
#include"ExDrawLineDoc.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CExDrawLineView ����/����

CExDrawLineView::CExDrawLineView()
{
	// TODO:  �ڴ˴���ӹ������

}

CExDrawLineView::~CExDrawLineView()
{
}

BOOL CExDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExDrawLineView ����

void CExDrawLineView::OnDraw(CDC* /*pDC*/)
{
	CExDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExDrawLineView ��ӡ


void CExDrawLineView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CExDrawLineView ���

#ifdef _DEBUG
void CExDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CExDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExDrawLineDoc* CExDrawLineView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExDrawLineDoc)));
	return (CExDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CExDrawLineView ��Ϣ�������



void CExDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ���������������
	CDC *pDC = GetDC();
	CString msgDDA, msgBresenham, msgMiddlepoint;
	CPoint point1(10, 10), point2(100, 100);
	LARGE_INTEGER t1, t2, frq;
	QueryPerformanceFrequency(&frq);  //��ȡ������Ƶ��

	QueryPerformanceCounter(&t1);     //��ȡ��ʱ��ʼֵ
	for (int i = 0; i < 1000; i++)
		DDA(pDC, point1.x, point1.y, point2.x, point2.y, RGB(0, 0, 0));
	QueryPerformanceCounter(&t2);
	msgDDA.Format(_T("ʹ��DDA�㷨����һ���ӵ㣨10��10�����㣨100��100����ֱ��1000���ʱ��%fms"), ((double)t2.QuadPart - (double)t1.QuadPart )/ (double)frq.QuadPart * 1000);

	QueryPerformanceCounter(&t1);
	for (int i = 0; i < 1000; i++)
		Bresenham(pDC, point1.x, point1.y, point2.x, point2.y, RGB(0, 0, 0));
	QueryPerformanceCounter(&t2);
	msgBresenham.Format(_T("ʹ��Bresenham�㷨����һ���ӵ㣨10��10�����㣨100��100����ֱ��1000���ʱ��%fms"), ((double)t2.QuadPart - (double)t1.QuadPart) / (double)frq.QuadPart * 1000);

	QueryPerformanceCounter(&t1);
	for (int i = 0; i < 1000; i++)
		Middlepoint(pDC, point1.x, point1.y, point2.x, point2.y, RGB(0, 0, 0));
	QueryPerformanceCounter(&t2);
	msgMiddlepoint.Format(_T("ʹ���е㻭���㷨����һ���ӵ㣨10��10�����㣨100��100����ֱ��1000���ʱ��%fms"), ((double)t2.QuadPart - (double)t1.QuadPart) / (double)frq.QuadPart * 1000);

	AfxMessageBox(msgDDA + '\n' + msgBresenham + '\n' + msgMiddlepoint);
}
