
// ExDrawLineView.h : CExDrawLineView ��Ľӿ�
//

#pragma once
#include"stdafx.h"
#include"ExDrawLine.h"
#include"ExDrawLineDoc.h"



class CExDrawLineView : public CView
{
protected: // �������л�����
	CExDrawLineView();
	DECLARE_DYNCREATE(CExDrawLineView);

// ����
public:
	CExDrawLineDoc* GetDocument() const;
	
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
	virtual ~CExDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint p0;
	CPoint p1;


// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	


public:
	int m_pointnum = 0;
	int linetype = -1;
	int r = 0, g = 0,b = 0;
	bool draw=false;


	afx_msg void OnDrawline();
	afx_msg void OnCompare();
};
#ifndef _DEBUG  // ExDrawLineView.cpp �еĵ��԰汾
inline CExDrawLineDoc* CExDrawLineView::GetDocument() const
   { return reinterpret_cast<CExDrawLineDoc*>(m_pDocument); }
#endif

