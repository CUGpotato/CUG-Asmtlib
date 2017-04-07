
// GraphicsExpDoc.h : CGraphicsExpDoc 类的接口
//
#include"Line.h"
#include<vector>

using namespace std;

#pragma once


class CGraphicsExpDoc : public CDocument
{
protected: // 仅从序列化创建
	CGraphicsExpDoc();
	DECLARE_DYNCREATE(CGraphicsExpDoc)

	vector<Line> m_vLines;  //存放直线

// 特性
public:
	void AddLine(CPoint pntStart, CPoint pntEnd);
	Line GetLine(int index);
	int GetLineNumber();

	virtual void DeleteContents();
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CGraphicsExpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
};
