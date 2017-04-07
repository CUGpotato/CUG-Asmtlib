
// GraphicsExpView.h : CGraphicsExpView ��Ľӿ�
//

#pragma once


class CGraphicsExpView : public CView
{
protected: // �������л�����
	CGraphicsExpView();
	DECLARE_DYNCREATE(CGraphicsExpView)

// ����
public:
	CGraphicsExpDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CGraphicsExpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_Drag=0; 
	CPoint m_pntPrev;
	CPoint m_pntOrigin;


// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // GraphicsExpView.cpp �еĵ��԰汾
inline CGraphicsExpDoc* CGraphicsExpView::GetDocument() const
   { return reinterpret_cast<CGraphicsExpDoc*>(m_pDocument); }
#endif

