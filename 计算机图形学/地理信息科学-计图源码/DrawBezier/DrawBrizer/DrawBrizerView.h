
// DrawBrizerView.h : CDrawBrizerView ��Ľӿ�
//

#pragma once
#include"Bezier.h"
#include"SetParamDlg.h"
#include"DrawBrizerDoc.h"

class CDrawBrizerView : public CView
{
protected: // �������л�����
	CDrawBrizerView();
	DECLARE_DYNCREATE(CDrawBrizerView);

// ����
public:
	CDrawBrizerDoc* GetDocument() const;

// ����
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
	virtual ~CDrawBrizerView();
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
	afx_msg void OnSetparam();
	afx_msg void OnBrizerNormal();
	afx_msg void OnUpdateBrizerNormal(CCmdUI*pCmdUI);
	afx_msg void OnBrizerGeometry();
	afx_msg void OnUpdateBrizerGeometry(CCmdUI*pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawBrizerView.cpp �еĵ��԰汾
inline CDrawBrizerDoc* CDrawBrizerView::GetDocument() const
   { return reinterpret_cast<CDrawBrizerDoc*>(m_pDocument); }
#endif

