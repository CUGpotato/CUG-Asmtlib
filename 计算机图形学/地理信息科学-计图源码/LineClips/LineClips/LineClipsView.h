
// LineClipsView.h : CLineClipsView ��Ľӿ�
//

#pragma once
#include"Resource.h"

class CLineClipsView : public CView
{
protected: // �������л�����
	CLineClipsView();
	DECLARE_DYNCREATE(CLineClipsView)

// ����
public:
	CLineClipsDoc* GetDocument() const;

// ����
public:
	int m_draw;
	int m_Drag;
	CPoint m_pntPrev;
	CPoint m_pntOrigin;
	CPoint p0, p1;
	CPoint pr0, pr1;
	int clipTest(float p, float q, float *u1, float* u2);
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
	virtual ~CLineClipsView();
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
	afx_msg void OnClipInputline();
	afx_msg void OnClipInputclipwindow();
	afx_msg void OnClipClip();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // LineClipsView.cpp �еĵ��԰汾
inline CLineClipsDoc* CLineClipsView::GetDocument() const
   { return reinterpret_cast<CLineClipsDoc*>(m_pDocument); }
#endif

