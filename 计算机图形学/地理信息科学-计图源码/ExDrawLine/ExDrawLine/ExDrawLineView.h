
// ExDrawLineView.h : CExDrawLineView 类的接口
//

#pragma once
#include"stdafx.h"
#include"ExDrawLine.h"
#include"ExDrawLineDoc.h"



class CExDrawLineView : public CView
{
protected: // 仅从序列化创建
	CExDrawLineView();
	DECLARE_DYNCREATE(CExDrawLineView);

// 特性
public:
	CExDrawLineDoc* GetDocument() const;
	
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
	virtual ~CExDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint p0;
	CPoint p1;


// 生成的消息映射函数
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
#ifndef _DEBUG  // ExDrawLineView.cpp 中的调试版本
inline CExDrawLineDoc* CExDrawLineView::GetDocument() const
   { return reinterpret_cast<CExDrawLineDoc*>(m_pDocument); }
#endif

