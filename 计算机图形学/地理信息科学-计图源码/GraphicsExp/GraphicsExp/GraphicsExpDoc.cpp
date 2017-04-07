
// GraphicsExpDoc.cpp : CGraphicsExpDoc 类的实现
//

#include "stdafx.h"
#include<iostream>

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GraphicsExp.h"
#endif

#include "GraphicsExpDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGraphicsExpDoc

IMPLEMENT_DYNCREATE(CGraphicsExpDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraphicsExpDoc, CDocument)
	ON_COMMAND(ID_EDIT_UNDO, &CGraphicsExpDoc::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CGraphicsExpDoc::OnUpdateEditUndo)
END_MESSAGE_MAP()


// CGraphicsExpDoc 构造/析构

CGraphicsExpDoc::CGraphicsExpDoc()
{
	// TODO:  在此添加一次性构造代码

}

CGraphicsExpDoc::~CGraphicsExpDoc()
{
}

BOOL CGraphicsExpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CGraphicsExpDoc 序列化

void CGraphicsExpDoc::Serialize(CArchive& ar)
{
	long i;
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
		ar << m_vLines.size();
		for (i = 0; i < m_vLines.size(); i++)
		{
			ar << m_vLines[i].m_pntStart.x << m_vLines[i].m_pntStart.y;
			ar << m_vLines[i].m_pntEnd.x << m_vLines[i].m_pntEnd.y;
		}
	}
	else
	{
		// TODO:  在此添加加载代码
		int nNum;
		ar >> nNum;
		m_vLines.resize(nNum);
		for (i = 0; i < nNum; i++)
		{
			ar >> m_vLines[i].m_pntStart.x >> m_vLines[i].m_pntStart.y;
			ar >> m_vLines[i].m_pntEnd.x >> m_vLines[i].m_pntEnd.y;
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CGraphicsExpDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CGraphicsExpDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CGraphicsExpDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CGraphicsExpDoc 诊断

#ifdef _DEBUG
void CGraphicsExpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraphicsExpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGraphicsExpDoc 命令

void CGraphicsExpDoc::AddLine(CPoint pntStart, CPoint pntEnd)
{
	m_vLines.push_back(Line(pntStart, pntEnd));
	SetModifiedFlag();
}

Line CGraphicsExpDoc::GetLine(int index)
{
	return m_vLines.at(index);
}

int CGraphicsExpDoc::GetLineNumber()
{
	return m_vLines.size();
}

void CGraphicsExpDoc::DeleteContents()
{
	m_vLines.clear();
}



void CGraphicsExpDoc::OnEditUndo()
{
	// TODO:  在此添加命令处理程序代码
	int index;
	index = m_vLines.size() - 1;
	if (index >= 0)
	{
		m_vLines.pop_back();
	}
	UpdateAllViews(NULL);
	SetModifiedFlag();
}


void CGraphicsExpDoc::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(m_vLines.size());
}
