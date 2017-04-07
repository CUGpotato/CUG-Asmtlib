
// ExDrawCircleView.h : CExDrawCircleView 类的接口
//

#pragma once
#include"Animationfunc.h"

class CExDrawCircleView : public CView
{
protected: // 仅从序列化创建
	CExDrawCircleView();
	DECLARE_DYNCREATE(CExDrawCircleView)

// 特性
public:
	CExDrawCircleDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CExDrawCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	int r, m;
	int x, y;


// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ExDrawCircleView.cpp 中的调试版本
inline CExDrawCircleDoc* CExDrawCircleView::GetDocument() const
   { return reinterpret_cast<CExDrawCircleDoc*>(m_pDocument); }
#endif

