#pragma once

#include<Afxwin.h>

void Middlepoint(CDC *pDC, int p0_x, int p0_y, int p1_x, int p1_y, COLORREF color);

void DDA(CDC *pDC, int p0_x, int p0_y, int p1_x, int p1_y, COLORREF color);

void Bresenham(CDC *pDC, int p0_x, int p0_y, int p1_x, int p1_y, COLORREF color);
