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
	void AppendPoint(CPoint point);//��ӵ�һ�����Ƶ�
	void UpdateLastPoint(CPoint point);//�޸����һ����
	void ClearAllPoints();//������п��Ƶ�
public:
	void Draw(CDC* pDC, bool bIsNormal);
	void DrawPoint(CDC *pDC, int x, int y, int size, COLORREF color);
private:
	vector<CPoint>vPoint;
	int m_nSection;
	COLORREF m_nColor;

};
