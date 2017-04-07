
// DrawBrizerView.cpp : CDrawBrizerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CDrawBrizerView ����/����

CDrawBrizerView::CDrawBrizerView()
{
	// TODO:  �ڴ˴���ӹ������
	Init();

}

CDrawBrizerView::~CDrawBrizerView()
{
}

BOOL CDrawBrizerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawBrizerView ����

void CDrawBrizerView::OnDraw(CDC* /*pDC*/)
{
	CDrawBrizerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDrawBrizerView ��ӡ


void CDrawBrizerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawBrizerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawBrizerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawBrizerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CDrawBrizerView ���

#ifdef _DEBUG
void CDrawBrizerView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawBrizerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawBrizerDoc* CDrawBrizerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawBrizerDoc)));
	return (CDrawBrizerDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawBrizerView ��Ϣ�������


void CDrawBrizerView::OnSetparam()
{
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_blsNormal || m_blsGeometry)
	{
		CClientDC dc(this);
		m_Bezier.Draw(&dc, m_blsNormal);
		m_Bezier.ClearAllPoints();
		ReturnNormal();
	}
	CView::OnRButtonDown(nFlags, point);
}
