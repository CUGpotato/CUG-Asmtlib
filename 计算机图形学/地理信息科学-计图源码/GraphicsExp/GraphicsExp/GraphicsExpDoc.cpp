
// GraphicsExpDoc.cpp : CGraphicsExpDoc ���ʵ��
//

#include "stdafx.h"
#include<iostream>

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CGraphicsExpDoc ����/����

CGraphicsExpDoc::CGraphicsExpDoc()
{
	// TODO:  �ڴ����һ���Թ������

}

CGraphicsExpDoc::~CGraphicsExpDoc()
{
}

BOOL CGraphicsExpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CGraphicsExpDoc ���л�

void CGraphicsExpDoc::Serialize(CArchive& ar)
{
	long i;
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
		ar << m_vLines.size();
		for (i = 0; i < m_vLines.size(); i++)
		{
			ar << m_vLines[i].m_pntStart.x << m_vLines[i].m_pntStart.y;
			ar << m_vLines[i].m_pntEnd.x << m_vLines[i].m_pntEnd.y;
		}
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
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

// ����ͼ��֧��
void CGraphicsExpDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CGraphicsExpDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CGraphicsExpDoc ���

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


// CGraphicsExpDoc ����

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
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(m_vLines.size());
}
