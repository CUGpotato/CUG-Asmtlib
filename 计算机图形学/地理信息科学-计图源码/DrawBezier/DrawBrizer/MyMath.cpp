#include "stdafx.h"
#include "MyMath.h"
#include<cmath>
#include "stdafx.h"
#include "MyMath.h"
#include<cmath>
double MyMath::Bblend(int i, int n, double t){
	double c = 1.0;
	int j;
	for (j = n; j >= i + 1; j--)c *= j;
	for (j = n - i; j >= 2; j--)c /= j;
	double result = c*powf(t, i)*powf(1 - t, n - i);
	return result;
}
void MyMath::Bezier_Normal(CDC*pDC, COLORREF tempColor, int*X, int*Y, int pointNum, int section){
	if (pointNum < 3)return;
	int n = pointNum - 1;
	int i, j;
	double t = 0.0, temp;
	double dt = 1 / (double)section;
	double x, y;
	CPen newPen(PS_SOLID, 2, tempColor);
	CPen*pOldPen = pDC->SelectObject(&newPen);
	pDC->MoveTo(X[0], Y[0]);
	for (j = 0; j < section; j++){
		t += dt;
		x = y = 0.0;
		for (i = 0; i <= n; i++){
			temp = Bblend(i, n, t);
			x += X[i] * temp;
			y += Y[i] * temp;
		}
		pDC->LineTo(x, y);
	}
	pDC->LineTo(X[n], Y[n]);
	pDC->SelectObject(pOldPen);
}
void MyMath::Bezier_Geometry(CDC*pDC, COLORREF tempColor, int *X, int*Y, int pointNum, int section){
	if (pointNum < 3)return;
	int n = pointNum - 1;
	double *rx = new double[pointNum];
	double *ry = new double[pointNum];
	int i, j, m;
	double t = 0.0;
	double dt = 1 / (double)section;
	CPen newPen(PS_SOLID, 1, tempColor);
	CPen*pOldPen = pDC->SelectObject(&newPen);
	pDC->MoveTo(X[0], Y[0]);
	for (j = 0; j < section; j++){
		t += dt;
		for (i = 0; i <= n; i++){
			rx[i] = X[i];
			ry[i] = Y[i];
		}
		m = n;
		while (m > 0){
			for (i = 0; i < m; i++){
				rx[i] = rx[i] + t*(rx[i + 1] - rx[i]);
				ry[i] = ry[i] + t*(ry[i + 1] - ry[i]);
			}
			m--;
		}
		pDC->LineTo(rx[0], ry[0]);
	}
	delete[]ry;
	delete[]rx;
	pDC->SelectObject(pOldPen);
}

