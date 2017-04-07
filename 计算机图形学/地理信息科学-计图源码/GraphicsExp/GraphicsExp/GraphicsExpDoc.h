
// GraphicsExpDoc.h : CGraphicsExpDoc ��Ľӿ�
//
#include"Line.h"
#include<vector>

using namespace std;

#pragma once


class CGraphicsExpDoc : public CDocument
{
protected: // �������л�����
	CGraphicsExpDoc();
	DECLARE_DYNCREATE(CGraphicsExpDoc)

	vector<Line> m_vLines;  //���ֱ��

// ����
public:
	void AddLine(CPoint pntStart, CPoint pntEnd);
	Line GetLine(int index);
	int GetLineNumber();

	virtual void DeleteContents();
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CGraphicsExpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
};
