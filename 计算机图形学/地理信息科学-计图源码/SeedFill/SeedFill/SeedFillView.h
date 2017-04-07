
// SeedFillView.h : CSeedFillView ��Ľӿ�
//

#pragma once
#include"SeedFillFunc.h"

class CSeedFillView : public CView
{
protected: // �������л�����
	CSeedFillView();
	DECLARE_DYNCREATE(CSeedFillView)

// ����
public:
	CSeedFillDoc* GetDocument() const;

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
	virtual ~CSeedFillView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SeedFillView.cpp �еĵ��԰汾
inline CSeedFillDoc* CSeedFillView::GetDocument() const
   { return reinterpret_cast<CSeedFillDoc*>(m_pDocument); }
#endif

