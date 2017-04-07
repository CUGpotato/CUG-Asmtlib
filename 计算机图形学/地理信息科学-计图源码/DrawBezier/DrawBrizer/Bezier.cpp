#include "stdafx.h"
#include"Bezier.h"
Bezier::Bezier(){
	m_nSection = SECTION;
	m_nColor = DEFAULT_COLOR;
}
Bezier::~Bezier(){
}
void Bezier::SetSection(int nSection){
	this->m_nSection = nSection;
}
void  Bezier::SetColor(COLORREF color){
	this->m_nColor = color;
}
void Bezier::AppendPoint(CPoint point){
	vPoint.push_back(point);
}
void Bezier::UpdateLastPoint(CPoint point){
	int pointNum = vPoint.size();
	vPoint[pointNum - 1].x = point.x;
	vPoint[pointNum - 1].y = point.y;
}
void Bezier::ClearAllPoints(){
	vPoint.clear();
}
void Bezier::Draw(CDC* pDC, bool bIsNormal){
	int pointNum = vPoint.size();
	if (pointNum < 3)return;
	int *X = new int[pointNum];
	int *Y = new int[pointNum];
	for (int i = 0; i < pointNum; i++){//控制点
		X[i] = vPoint[i].x;
		Y[i] = vPoint[i].y;
	}
	if (bIsNormal)//直接计算法
		MyMath::Bezier_Normal(pDC, this->m_nColor, X, Y, pointNum, this->m_nSection);
	else
	{
		MyMath::Bezier_Geometry(pDC, this->m_nColor, X, Y, pointNum, this->m_nSection);
	}
	delete[]X;
	delete[]Y;
}
void Bezier::DrawPoint(CDC *pDC, int x, int y, int size, COLORREF color){
	CBrush newBrush(color);
	CBrush *pOldBrush = pDC->SelectObject(&newBrush);
	pDC->Ellipse(x - size, y - size, x + size, y + size);
	pDC->SelectObject(pOldBrush);
}