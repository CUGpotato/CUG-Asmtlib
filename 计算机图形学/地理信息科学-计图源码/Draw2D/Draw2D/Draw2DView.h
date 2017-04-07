// Draw 2DView.h : CDraw2DView ��Ľӿ�
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
protected: // �������л�����
	CDraw2DView();
	DECLARE_DYNCREATE(CDraw2DView)

	// ����
public:
	CDraw2DDoc* GetDocument() const;

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
	virtual ~CDraw2DView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	void Rotate(struct Point* point, double angle_x, double angle_y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // Draw 2DView.cpp �еĵ��԰汾
inline CDraw2DDoc* CDraw2DView::GetDocument() const
{
	return reinterpret_cast<CDraw2DDoc*>(m_pDocument);
}
#endif
