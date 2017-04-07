#pragma once
#include<iostream>

class Line
{
public:
	Line(){};
	Line(CPoint pntStart,CPoint pntEnd);
	Line(Line& L)
	{
		m_pntStart = L.m_pntStart;
		m_pntEnd = L.m_pntEnd;
	}
	void DrawLine(CDC *pDC);
	CPoint m_pntStart;
	CPoint m_pntEnd;

};

