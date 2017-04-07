
// PolygonfillView.h : CPolygonfillView ��Ľӿ�
//

#pragma once
#include"stdafx.h"
#include"FileView.h"
#include"FillSet.h"
#include"ScanLineFillfunc.h"

class CPolygonfillView : public CView
{
protected: // �������л�����
	CPolygonfillView();
	DECLARE_DYNCREATE(CPolygonfillView)

// ����
public:
	CPolygonfillDoc* GetDocument() const;

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
	virtual ~CPolygonfillView();
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
	afx_msg void OnPoligonfillScanlinefill();

	CFillSet  FillSetDlg;
	COLORREF m_nScanColor;
	double m_nScanAngle;
	double m_nScanGap;
};

#ifndef _DEBUG  // PolygonfillView.cpp �еĵ��԰汾
inline CPolygonfillDoc* CPolygonfillView::GetDocument() const
   { return reinterpret_cast<CPolygonfillDoc*>(m_pDocument); }
#endif

