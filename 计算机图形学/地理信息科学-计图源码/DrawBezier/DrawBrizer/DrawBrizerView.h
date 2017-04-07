
// DrawBrizerView.h : CDrawBrizerView 类的接口
//

#pragma once
#include"Bezier.h"
#include"SetParamDlg.h"
#include"DrawBrizerDoc.h"

class CDrawBrizerView : public CView
{
protected: // 仅从序列化创建
	CDrawBrizerView();
	DECLARE_DYNCREATE(CDrawBrizerView);

// 特性
public:
	CDrawBrizerDoc* GetDocument() const;

// 操作
private:
	Bezier m_Bezier;
	int m_nSection;
	COLORREF m_nColor;
	bool m_blsNormal;
	bool m_blsGeometry;
	int m_nStep;
	int m_nEndY;
public:
	void Init()
	{
		m_nSection = SECTION;
		m_nColor = DEFAULT_COLOR;
		m_blsNormal = false;
		m_blsGeometry = false;
		m_nStep = 0;
		m_nEndY = 0;
	}
	void ReturnNormal()
	{
		m_nStep = 0;
		m_nEndY = 0;
	}

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
	virtual ~CDrawBrizerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetparam();
	afx_msg void OnBrizerNormal();
	afx_msg void OnUpdateBrizerNormal(CCmdUI*pCmdUI);
	afx_msg void OnBrizerGeometry();
	afx_msg void OnUpdateBrizerGeometry(CCmdUI*pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawBrizerView.cpp 中的调试版本
inline CDrawBrizerDoc* CDrawBrizerView::GetDocument() const
   { return reinterpret_cast<CDrawBrizerDoc*>(m_pDocument); }
#endif

