#pragma once
#include"Afxwin.h"
#define SECTION 500
#define DEFAULT_COLOR RGB(0,0,0)
class MyMath
{
public:
	static void Bezier_Normal(CDC*pDC, COLORREF tempColor, int*X, int*Y, int pointNum, int section);
private:
	static double Bblend(int i, int n, double t);
public:
	static void Bezier_Geometry(CDC*pDC, COLORREF tempColor, int *X, int*Y, int pointNum, int section);
};

