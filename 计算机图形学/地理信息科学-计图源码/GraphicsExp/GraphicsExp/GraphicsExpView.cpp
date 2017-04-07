
// GraphicsExpView.cpp : CGraphicsExpView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "GraphicsExp.h"
#endif

#include "GraphicsExpDoc.h"
#include "GraphicsExpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicsExpView

IMPLEMENT_DYNCREATE(CGraphicsExpView, CView)

BEGIN_MESSAGE_MAP(CGraphicsExpView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGraphicsExpView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CGraphicsExpView ����/����

CGraphicsExpView::CGraphicsExpView()
{
	// TODO:  �ڴ˴���ӹ������

}

CGraphicsExpView::~CGraphicsExpView()
{
}

BOOL CGraphicsExpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, (HBRUSH)::GetStockObject(WHITE_BRUSH), 0);

	return CView::PreCreateWindow(cs);
}

// CGraphicsExpView ����

void CGraphicsExpView::OnDraw(CDC* pDC)
{
	CGraphicsExpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int index = pDoc->GetLineNumber();
	while (index--)
		pDoc->GetLine(index).DrawLine(pDC);

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CGraphicsExpView ��ӡ


void CGraphicsExpView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGraphicsExpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGraphicsExpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGraphicsExpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CGraphicsExpView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGraphicsExpView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGraphicsExpView ���

#ifdef _DEBUG
void CGraphicsExpView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicsExpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicsExpDoc* CGraphicsExpView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicsExpDoc)));
	return (CGraphicsExpDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicsExpView ��Ϣ�������


void CGraphicsExpView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

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


void CGraphicsExpView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	HCURSOR m_hCursor = LoadCursor(NULL,IDC_CROSS);
	SetCursor(m_hCursor);    //����ʮ�ֹ��
	CClientDC dc(this);
	if (m_Drag)
	{
		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_pntOrigin);
		dc.LineTo(m_pntPrev);
		dc.MoveTo(m_pntOrigin);
		dc.LineTo(point);
		m_pntPrev = point;
	}

	CView::OnMouseMove(nFlags, point);
}


void CGraphicsExpView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_Drag = 0;
	ReleaseCapture();
	ClipCursor(NULL);

	CGraphicsExpDoc* pDoc = GetDocument();
	pDoc->AddLine(m_pntOrigin, point);

	CView::OnLButtonUp(nFlags, point);
}
