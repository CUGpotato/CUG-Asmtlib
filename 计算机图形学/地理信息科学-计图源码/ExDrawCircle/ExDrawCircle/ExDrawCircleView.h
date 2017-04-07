
// ExDrawCircleView.h : CExDrawCircleView ��Ľӿ�
//

#pragma once
#include"Animationfunc.h"

class CExDrawCircleView : public CView
{
protected: // �������л�����
	CExDrawCircleView();
	DECLARE_DYNCREATE(CExDrawCircleView)

// ����
public:
	CExDrawCircleDoc* GetDocument() const;

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
	virtual ~CExDrawCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	int r, m;
	int x, y;


// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ExDrawCircleView.cpp �еĵ��԰汾
inline CExDrawCircleDoc* CExDrawCircleView::GetDocument() const
   { return reinterpret_cast<CExDrawCircleDoc*>(m_pDocument); }
#endif

