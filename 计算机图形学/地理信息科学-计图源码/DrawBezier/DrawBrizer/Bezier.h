#pragma once
#include<vector>
#include<Afxwin.h>	
using namespace std;
#include"MyMath.h"
class Bezier{
public:
	Bezier();
	~Bezier();
	void SetSection(int nSection);
	void SetColor(COLORREF color);
	void AppendPoint(CPoint point);//添加第一个控制点
	void UpdateLastPoint(CPoint point);//修改最后一个点
	void ClearAllPoints();//清空所有控制点
public:
	void Draw(CDC* pDC, bool bIsNormal);
	void DrawPoint(CDC *pDC, int x, int y, int size, COLORREF color);
private:
	vector<CPoint>vPoint;
	int m_nSection;
	COLORREF m_nColor;

};
