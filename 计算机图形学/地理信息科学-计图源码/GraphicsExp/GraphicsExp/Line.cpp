#include "stdafx.h"
#include "Line.h"


Line::Line(CPoint pntStart, CPoint pntEnd)
{
	m_pntStart = pntStart;
	m_pntEnd = pntEnd;
}

void Line::DrawLine(CDC *pDC)
{
	pDC->MoveTo(m_pntStart);
	pDC->MoveTo(m_pntEnd);
}