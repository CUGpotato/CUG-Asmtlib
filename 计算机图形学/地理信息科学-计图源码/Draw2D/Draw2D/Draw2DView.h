// Draw 2DView.h : CDraw2DView 类的接口
//

#pragma once


class CDraw2DView : public CView
{
	struct Point{
		double x; double y;
	}m_point[4];
	struct Line{
		int point1; int point2;
	}line[4];
	double x0, y0;
	int first_x, first_y, pre_x, pre_y;
protected: // 仅从序列化创建
	CDraw2DView();
	DECLARE_DYNCREATE(CDraw2DView)

	// 特性
public:
	CDraw2DDoc* GetDocument() const;

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
	virtual ~CDraw2DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	void Rotate(struct Point* point, double angle_x, double angle_y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // Draw 2DView.cpp 中的调试版本
inline CDraw2DDoc* CDraw2DView::GetDocument() const
{
	return reinterpret_cast<CDraw2DDoc*>(m_pDocument);
}
#endif
